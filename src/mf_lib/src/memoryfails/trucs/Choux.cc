#include <memoryfails/trucs/Choux.hh>

using namespace memoryfails;

Choux::Choux()
{
}

Choux::Choux(Choux const & autre_p)
{
    *this = autre_p;
}

Choux& Choux::operator=(Choux const & autre_p)
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

Choux::~Choux()
{
}

Choux::Choux(double poids_p, std::string const & variete_p, int diametre_p)
: Legumes(poids_p, variete_p), diametre_m(diametre_p)
{
}