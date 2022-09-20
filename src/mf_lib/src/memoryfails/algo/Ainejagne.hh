#ifndef __AINEJAYNE_HH__
#define __AINEJAYNE_HH__

#include <memoryfails/Contexte.hh>

namespace memoryfails {

// une classe maman pas abstaite sinon c'est trop facile
class Ainejagne
{
    private:
        std::string fichier_m;

    public:
        Ainejagne(std::string const & fichier_p);
        Ainejagne(Ainejagne const &);
        Ainejagne& operator=(Ainejagne const &);
        ~Ainejagne();

        void applique_sur_contexte(Contexte * contexte_p);

};

} // namespace memoryfails

#endif //__AINEJAYNE_HH__