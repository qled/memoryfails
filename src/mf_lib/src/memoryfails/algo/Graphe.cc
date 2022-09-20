#include <memoryfails/algo/Graphe.hh>

using namespace memoryfails;

Graphe::Graphe()
{
}

Graphe::Graphe(Graphe const & autre_p)
{
    *this = autre_p;
}

Graphe& Graphe::operator=(Graphe const & autre_p)
{
    if(this != &autre_p)
    {
        this->noeuds_m = autre_p.noeuds_m; // c'est des shared pointers, donc c'est bon non ?
    }
    return *this;
}

Graphe::~Graphe()
{
    // c'est des shared pointers, donc il y a rien a faire
}