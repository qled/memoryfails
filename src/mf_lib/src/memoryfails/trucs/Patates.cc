#include <memoryfails/trucs/Patates.hh>

using namespace memoryfails;

Patates::Patates()
{
}

Patates::Patates(Patates const & autre_p)
{
    *this = autre_p;
}

Patates& Patates::operator=(Patates const & autre_p)
{
    if(this != &autre_p)
    {
        this->poids_m = autre_p.poids_m;
        this->variete_m = autre_p.variete_m;
        // on aurait bien aimé faire un clone, mais dommage on n'en a pas
        this->pTracabilite_m = autre_p.pTracabilite_m;
        this->calibre_m = autre_p.calibre_m;
    }
    return *this;
}

Patates::~Patates()
{
}

Patates::Patates(double poids_p, std::string const & variete_p, int calibre_p)
: Legumes(poids_p, variete_p), calibre_m(calibre_p)
{
}