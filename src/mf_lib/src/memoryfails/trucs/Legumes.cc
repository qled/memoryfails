#include <memoryfails/trucs/Legumes.hh>

using namespace memoryfails;

Legumes::Legumes()
{
}

Legumes::Legumes(Legumes const & autre_p)
{
    *this = autre_p;
}

Legumes& Legumes::operator=(Legumes const & autre_p)
{
    if(this != &autre_p)
    {
        this->poids_m = autre_p.poids_m;
        this->variete_m = autre_p.variete_m;
        // on aurait bien aimé faire un clone, mais dommage on n'en a pas
        this->pTracabilite_m = autre_p.pTracabilite_m;
    }
    return *this;
}

Legumes::~Legumes()
{
    if (pTracabilite_m != nullptr)
    {
        delete pTracabilite_m;
    }
}

Legumes::Legumes(double poids_p, std::string const & variete_p, Tracabilite * pTracabilite_p)
: poids_m(poids_p), variete_m(variete_p), pTracabilite_m(pTracabilite_p)
{
}