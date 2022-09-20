#ifndef __CONTEXT_HH__
#define __CONTEXT_HH__

#include <vector>
#include <map>
#include <string>

namespace memoryfails {

// predefinition
class Legumes;
class Tracabilite;

struct StatItem {

    std::string const label_m;
    double valeur_m;

    StatItem(std::string const & label_p, double valeur_p)
    :label_m(label_p), valeur_m(valeur_p)
    {}
};

typedef std::map<Tracabilite const *, Legumes *> BrouetteMap;
typedef std::vector<StatItem const *> StatsVector;
typedef std::map<std::string, std::string> AffiniteMap;

// C'est un contexte, voila quoi
class Contexte
{
private:
    Contexte(Contexte const &);
    Contexte & operator=(Contexte const &);

    BrouetteMap brouette_m;
    StatsVector stats_m;
    AffiniteMap affinites_m;

public:
    // constructeur
    Contexte();
    // destructeur
    ~Contexte();

    void init();

    // une fonction clean qui n'est peut etre pas utile
    void clean();

    BrouetteMap const & getBrouette() const { return brouette_m; }
    BrouetteMap & getBrouette() { return brouette_m; }

    StatsVector const & getStats() const { return stats_m; }
    StatsVector & getStats() { return stats_m; }

    AffiniteMap const & getAffinites() const { return affinites_m; }
    AffiniteMap & getAffinites() { return affinites_m; }

};

} // namespace memoryfails

#endif // __CONTEXT_HH__