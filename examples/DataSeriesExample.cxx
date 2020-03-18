#include "DataSeries.hxx"
#include "Epoch.hxx"

using namespace PHYS::Data;
using namespace PHYS::Chrono;

int main(int argc, char** argv)
{
	DataSeries<int, int> a({10,23,4,45}),
		   b({3,4,5,6});

	a = a.append(b);

	std::cout << a << std::endl;
	a.Print();

	DataSeries<Time, int> c({0,2,3,4,5}, Time(60), fromString("10:30", "HH:MM").time());

	c.Print();

	return 0;
}
