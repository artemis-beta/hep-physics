#include "Epoch.hxx"

#include <string>
#include <iostream>

using namespace PHYS::Chrono;

int main(int argc, char** argv)
{
    const DateTime time = fromString("10:01", "HH:MM");
    std::cout << time.time() << std::endl;
    std::cout << time.time().toString("HH:MM:SS") << std::endl;
}