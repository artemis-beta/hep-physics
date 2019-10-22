#include "DataFrame.hxx"
#include <vector>

using namespace PHYS::Data;

int main()
{
    DataFrame* d = new DataFrame;
    d->addColumnBool("Test", {0,1});
    d->head();
}