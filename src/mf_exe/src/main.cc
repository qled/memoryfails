#include <memoryfails/Contexte.hh>
#include <memoryfails/algo/Ainejagne.hh>

#include <string>
#include <iostream>

using namespace memoryfails;

void help(std::string const & arg0_p)
{
    std::cout << "Usage: " << arg0_p << " <nimp file>" << std::endl;
}

Contexte * cree_contexte()
{
    // On cree le contexte
    Contexte * pContexte_l = new Contexte();
    // on l'initialise
    pContexte_l->init();
    // et on le retourne
    return pContexte_l;
}

int main (int argc, const char ** argv)
{
    if (argc == 1)
    {
        std::string arg0_l(argv[0]);
        help(arg0_l);
        return 1;
    }

    Contexte * pContexte_l = cree_contexte();

    std::string fichier_l(argv[1]);
    Ainejagne moteur_l(fichier_l);

    moteur_l.applique_sur_contexte(pContexte_l);

    pContexte_l->clean();

    std::cout << "Fin du programme" << std::endl;

    return 0;
}

