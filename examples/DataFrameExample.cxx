#include "DataFrame.hxx"
#include "Epoch.hxx"

using namespace PHYS::Data;
using namespace PHYS::Chrono;

int main(int argc, char** argv)
{
    DataFrame<Time>* d = new DataFrame<Time>;
    d->addColumnBool("Test", {0,1,0,0,1,0,1});
    d->addColumnDouble("Test2", {2.3,2.3,3.54,1.3,1.53,6.7,3.4});
    d->head();
    std::cout << d->getBoolColumn("Test") << std::endl;

    return 0;
}