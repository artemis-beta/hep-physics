#include "DataFrame.hxx"
#include <vector>

using namespace PHYS::Data;

int main()
{
    DataFrame* d = new DataFrame;
    d->addColumnBool("Test", {0,1,0,0,1,0,1});
    d->addColumnDouble("Test2", {2.3,2.3,3.54,1.3,1.53,6.7,3.4});
    d->head();
}