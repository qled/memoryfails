#include <memoryfails/algo/Ainejagne.hh>
#include <memoryfails/trucs/Choux.hh>
#include <memoryfails/trucs/Patates.hh>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace memoryfails;

Ainejagne::Ainejagne(std::string const & fichier_p)
:fichier_m(fichier_p)
{
}

Ainejagne::Ainejagne(Ainejagne const & autre_p)
{
    *this = autre_p;
}

Ainejagne& Ainejagne::operator=(Ainejagne const & autre_p)
{
    if(this != &autre_p)
    {
        this->fichier_m = autre_p.fichier_m;
    }
    return *this;
}

Ainejagne::~Ainejagne()
{
}

bool is_voyelle(char const char_p)
{
    return char_p == 'a' || char_p == 'e' || char_p == 'i' || char_p == 'o' || char_p == 'u' || char_p == 'y' ||
           char_p == 'A' || char_p == 'E' || char_p == 'I' || char_p == 'O' || char_p == 'U' || char_p == 'Y';
}

void parse_line(Context * context_p, std::string const & line_p)
{
    Brouette & brouette_l = context_p->getBrouette();

    std::string token_l;
    std::istringstream iss_l(line_p);
    while(iss_l >> token_l)
    {
        double poids_l = 0.0;
        for(auto & char_l : token_l) poids_l += 3.14 * char_l;
        char first_l = token_l.at(0);
        std::string variete_l(&first_l);
        Tracabilite * pTracabilite_l = new Tracabilite(token_l);
        // pour chaque mot qui commence par une voyelle on a ajoute des choux dont le diametre est de dix fois le nombre de lettre
        if (is_voyelle(first_l))
        {
            brouette_l[pTracabilite_l] = new Choux(poids_l, variete_l, 10 * token_l.size());
        }
        // pour chaque mot qui commence par une consonne on a ajoute des patates dont le calibre est le nombre de lettre
        else
        {
            brouette_l[pTracabilite_l] = new Patates(poids_l, variete_l, token_l.size());
        }
        brouette_l[pTracabilite_l]->setTracabilite(pTracabilite_l);
    }
}

void Ainejagne::runOnContext(Context * context_p)
{
    // on charge un texte
    std::string line_l;
    std::ifstream ifs_l(fichier_m.c_str());

    if (ifs_l.is_open())
    {
        std::cout << "On parse le fichier " << fichier_m << std::endl;
        while(std::getline(ifs_l, line_l))
        {
            parse_line(context_p, line_l);
        }
        ifs_l.close();
    }
}