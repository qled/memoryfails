#include <memoryfails/Context.hh>
#include <memoryfails/algo/Ainejagne.hh>

#include <string>
#include <iostream>

using namespace memoryfails;

void help(std::string const & arg0_p)
{
    std::cout << "Usage: " << arg0_p << " <nimp file>" << std::endl;
}

int main (int argc, const char ** argv)
{
    if (argc == 1)
    {
        std::string arg0_l(argv[0]);
        help(arg0_l);
        return 1;
    }

    Context context_l;

    std::string arg1_l(argv[1]);
    Ainejagne engine_l(arg1_l);

    engine_l.runOnContext(&context_l);

    context_l.clean();

    return 0;
}

