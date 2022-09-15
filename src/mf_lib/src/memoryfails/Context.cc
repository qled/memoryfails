#include <memoryfails/Context.hh>

using namespace memoryfails;

Context::Context()
{

}

Context::~Context()
{
    clean();
}

void Context::clean()
{
    for(auto & item_l : brouette_m) {
        delete item_l.second;
    }
    brouette_m.clear();

}