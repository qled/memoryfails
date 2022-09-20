#ifndef __GRAPHE_HH__
#define __GRAPHE_HH__

#include <vector>
#include <set>
#include <memory>
#include <string>

namespace memoryfails {

// declaration d'une sous classe douteuse
struct Noeud
{
    size_t id_m;
    std::string label_m;
    int couleur_m;

    std::set<std::shared_ptr<Noeud>> adjacence_m;
};

typedef std::vector<std::shared_ptr<Noeud>> NoeudVector;

// une classe maman pas abstaite sinon c'est trop facile
class Graphe
{
    protected:
        NoeudVector noeuds_m;

    public:
        Graphe();
        Graphe(Graphe const &);
        Graphe& operator=(Graphe const &);
        ~Graphe();

        NoeudVector const & getNoeuds() const { return noeuds_m; }
        NoeudVector & getNoeuds() { return noeuds_m; }
};

} // namespace memoryfails

#endif //__GRAPHE_HH__