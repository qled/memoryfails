#ifndef __PATATES_HH__
#define __PATATES_HH__

#include <memoryfails/trucs/Legumes.hh>

namespace memoryfails {

// une classe fille
class Patates : public Legumes
{
    private:
        int calibre_m;

    public:
        Patates();
        Patates(Patates const &);
        Patates& operator=(Patates const &);
        ~Patates();

        Patates(double poids_m, std::string const & variete_m, int calibre_p);
};

} // namespace memoryfails

#endif // __PATATES_HH__

