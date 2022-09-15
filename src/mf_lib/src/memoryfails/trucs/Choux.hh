#ifndef __CHOUX_HH__
#define __CHOUX_HH__

#include <memoryfails/trucs/Legumes.hh>

namespace memoryfails {

// une classe fille
class Choux : public Legumes
{
    private:
        int diametre_m;

    public:
        Choux();
        Choux(Choux const &);
        Choux& operator=(Choux const &);
        ~Choux();

        Choux(double poids_p, std::string const & variete_p, int diametre_p);
};

} // namespace memoryfails

#endif //__LEGUMES_HH__