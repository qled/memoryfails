#include <memoryfails/Contexte.hh>
#include <memoryfails/trucs/Legumes.hh>

using namespace memoryfails;

Contexte::Contexte()
{

}

Contexte::~Contexte()
{
    clean();
}

void Contexte::init()
{
    clean();
}

void Contexte::clean()
{
    for(auto & item_l : brouette_m) {
        delete item_l.second;
    }
    brouette_m.clear();
    for(auto & item_l : stats_m) {
        delete item_l;
    }
    stats_m.clear();
}