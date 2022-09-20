#include <memoryfails/algo/Ainejagne.hh>
#include <memoryfails/algo/Graphe.hh>

#include <memoryfails/trucs/Legumes.hh>
#include <memoryfails/trucs/Choux.hh>
#include <memoryfails/trucs/Patates.hh>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <list>
#include <algorithm> // for copy()
#include <iterator> // for back_inserter
#include <limits>
#include <cctype>
#include <memory>

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

bool voyelle(char const char_p)
{
    return char_p == 'a' || char_p == 'e' || char_p == 'i' || char_p == 'o' || char_p == 'u' || char_p == 'y' ||
           char_p == 'A' || char_p == 'E' || char_p == 'I' || char_p == 'O' || char_p == 'U' || char_p == 'Y';
}

void decoupe_ligne(Contexte * contexte_p, std::string const & line_p)
{
    BrouetteMap & brouette_l = contexte_p->getBrouette();

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
        if (voyelle(first_l))
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

void rempli_contexte(Contexte * contexte_p, std::string const & fichier_p)
{
    // on charge un texte
    std::string ligne_l;
    std::ifstream ifs_l(fichier_p.c_str());

    if (ifs_l.is_open())
    {
        std::cout << "On parse le fichier " << fichier_p << std::endl;
        while(std::getline(ifs_l, ligne_l))
        {
            decoupe_ligne(contexte_p, ligne_l);
        }
        ifs_l.close();
    }
}

std::string to_lower_case(std::string const & data_p)
{
    std::string result_l(data_p);
    std::transform(result_l.begin(), result_l.end(), result_l.begin(), [](unsigned char c){ return std::tolower(c); });
    return result_l;
}

std::list<StatItem const *> genere_stats(std::string const & prefix_p, std::list<double> const & valeurs_p)
{
    std::list<StatItem const *> result_l;
    double min_l = std::numeric_limits<double>::max();
    double mean_l = 0.0;
    double max_l = -std::numeric_limits<double>::max();
    for(double const valeur_l : valeurs_p)
    {
        min_l = std::min(valeur_l, min_l);
        mean_l += valeur_l;
        max_l = std::max(valeur_l, max_l);
    }
    if (!valeurs_p.empty()) {
        size_t nb_l = valeurs_p.size();
        result_l.push_back(new StatItem(prefix_p + "_nb", nb_l));
        result_l.push_back(new StatItem(prefix_p + "_min", min_l));
        result_l.push_back(new StatItem(prefix_p + "_mean", mean_l / nb_l));
        result_l.push_back(new StatItem(prefix_p + "_max", max_l));
    }
    return result_l;
}

template <typename T> std::list<double> get_list_of_poids(std::list<T *> const & data_p)
{
    std::list<double> result_l;
    for(auto item_l : data_p)
    {
        result_l.push_back(item_l->getPoids());
    }
    return result_l;
}

size_t index_noeud(char lettre_p)
{
    size_t index_l = lettre_p - 'a';
    return index_l;
}

Graphe cree_graphe(BrouetteMap & brouette_l)
{
    Graphe graphe_l;

    NoeudVector & noeuds_l = graphe_l.getNoeuds();
    for (size_t i_l = 0; i_l < 26; ++i_l)
    {
        std::string label_l(1,'a' + i_l);
        Noeud noeud_l {i_l, label_l, 0};
        noeuds_l.push_back(std::make_shared<Noeud>(noeud_l));
    }

    for(auto & item_l : brouette_l)
    {
        std::string const & data_l = to_lower_case(item_l.first->provenance_m);
        size_t * prev_l = nullptr;
        for (char const & lettre_l : data_l)
        {
            if (lettre_l == ',' || lettre_l == '.') continue;
            size_t index_l = index_noeud(lettre_l);
            if (prev_l != nullptr)
            {
                std::shared_ptr<Noeud> p_l = noeuds_l[*prev_l];
                noeuds_l[index_l]->adjacence_m.insert(p_l);
            } else {
                prev_l = new size_t;
            }
            *prev_l = index_l;
        }
        delete prev_l;
    }

    return graphe_l;
}

void calcul_stats_sur_contexte(Contexte * contexte_p)
{
    // on des choux et des patates, on veut des stats sur :
    // - combien de choux, combien de patates ?
    // - la moyenne du poids des choux, la moyenne du poids des patates
    // - le nombre de varietes moyen
    BrouetteMap & brouette_l = contexte_p->getBrouette();
    std::list<Choux *> choux_l;
    std::list<Patates *> patates_l;
    std::list<Legumes *> legumes_l;
    for(auto & item_l : brouette_l)
    {
        Choux * chou_l = dynamic_cast<Choux *>(item_l.second);
        if (chou_l != nullptr) {
            choux_l.push_back(chou_l);
        }
        Patates * patate_l = dynamic_cast<Patates *>(item_l.second);
        if (patate_l != nullptr) {
            patates_l.push_back(patate_l);
        }
        legumes_l.push_back(item_l.second);
    }
    // stats sur les differents legumes
    auto statsChoux_l = genere_stats("choux_", get_list_of_poids(choux_l));
    auto statsPatates_l = genere_stats("patates_", get_list_of_poids(patates_l));
    auto statsLegumes_l = genere_stats("legumes_", get_list_of_poids(legumes_l));

    // rassemblement des stats
    StatsVector & statsVector_l = contexte_p->getStats();
    std::copy(statsChoux_l.begin(), statsChoux_l.end(), std::back_inserter(statsVector_l));
    std::copy(statsPatates_l.begin(), statsPatates_l.end(), std::back_inserter(statsVector_l));
    std::copy(statsLegumes_l.begin(), statsLegumes_l.end(), std::back_inserter(statsVector_l));

    // calcul du graphe pour les affinites
    Graphe graphe_l = cree_graphe(brouette_l);
    std::vector<std::shared_ptr<Noeud>> noeuds_l;
    std::copy(graphe_l.getNoeuds().begin(), graphe_l.getNoeuds().end(), std::back_inserter(noeuds_l));
    std::sort(noeuds_l.begin(), noeuds_l.end(), [](std::shared_ptr<Noeud> a_l, std::shared_ptr<Noeud> b_l) {
        return a_l->adjacence_m.size() > b_l->adjacence_m.size();
    });

    // affichage affinite
    std::cout << "Affinite :" << std::endl;
    AffiniteMap & affinites_l = contexte_p->getAffinites();
    for(auto noeud_l : noeuds_l)
    {
        // calcul de la liste d'affinite
        std::string affinite_l;
        for(auto prev_l : noeud_l->adjacence_m)
        {
            affinite_l = affinite_l + prev_l->label_m;
        }
        // affichage
        if (!noeud_l->adjacence_m.empty())
        {
            std::cout << "\t" << noeud_l->label_m << ": " << affinite_l << std::endl;
            affinites_l[noeud_l->label_m] = affinite_l;
        }
    }
}

void resume_contexte(Contexte * contexte_p)
{
    StatsVector & statsVector_l = contexte_p->getStats();

    std::cout << "Stats :" << std::endl;
    for (auto item_l : statsVector_l)
    {
        std::cout << "\t" << item_l->label_m << ": " << item_l->valeur_m << std::endl;
    }
}

void Ainejagne::applique_sur_contexte(Contexte * contexte_p)
{
    rempli_contexte(contexte_p, fichier_m);
    calcul_stats_sur_contexte(contexte_p);
    resume_contexte(contexte_p);
}