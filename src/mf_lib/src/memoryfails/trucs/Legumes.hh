#ifndef __LEGUMES_HH__
#define __LEGUMES_HH__

#include <string>

namespace memoryfails {

// declaration d'une sous classe douteuse
struct Tracabilite
{
    std::string provenance_m;

    Tracabilite(std::string const & provenance_p)
    :provenance_m(provenance_p)
    {}
};

// une classe maman pas abstaite sinon c'est trop facile
class Legumes
{
    protected:
        double poids_m;
        std::string variete_m;
        Tracabilite * pTracabilite_m { nullptr };

    public:
        Legumes();
        Legumes(Legumes const &);
        Legumes& operator=(Legumes const &);
        ~Legumes();

        Legumes(double poids_p, std::string const & variete_p, Tracabilite * pTracabilite_p = nullptr);

        void setTracabilite(Tracabilite * pTracabilite_p) {pTracabilite_m = pTracabilite_p;}
};

} // namespace memoryfails

#endif //__LEGUMES_HH__