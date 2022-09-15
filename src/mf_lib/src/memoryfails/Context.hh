#ifndef __CONTEXT_HH__
#define __CONTEXT_HH__

#include <vector>
#include <map>

namespace memoryfails {

// predefinition
class Legumes;
class Tracabilite;

typedef std::map<Tracabilite const *, Legumes *> Brouette;

// C'est un contexte, voila quoi
class Context
{
private:
    Context(Context const &);
    Context & operator=(Context const &);

    Brouette brouette_m;

public:
    // constructeur
    Context();
    // destructeur
    ~Context();

    // une fonction clean qui n'est peut etre pas utile
    void clean();

    Brouette const & getBrouette() const { return brouette_m; }
    Brouette & getBrouette() { return brouette_m; }

};

} // namespace memoryfails

#endif // __CONTEXT_HH__