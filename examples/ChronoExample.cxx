#include "Epoch.hxx"
#include "Units.hxx"

#include <string>
#include <iostream>

using namespace PHYS::Chrono;
using namespace PHYS::Units;

int main(int argc, char** argv)
{
    const DateTime time = fromString("10:01", "HH:MM");
    std::cout << time.time() << std::endl;
    std::cout << time.time().toString("HH:MM:SS") << std::endl;

    std::cout << "5s + 3hrs = " << Time(5*sec)+Time(3*hr) << std::endl;

    DateTime _test =  fromString("01-01-1993", "DD-mm-YYYY");
    std::cout << "Test Date: " << _test << std::endl;

    return 0;
}