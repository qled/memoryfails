#ifndef __AINEJAYNE_HH__
#define __AINEJAYNE_HH__

#include <memoryfails/Context.hh>

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


        void runOnContext(Context * context_p);

};

} // namespace memoryfails

#endif //__AINEJAYNE_HH__