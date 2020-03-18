#include "DataSeries.hxx"
#include "Epoch.hxx"

using namespace PHYS::Data;
using namespace PHYS::Chrono;

int main(int argc, char** argv)
{
	DataSeries<int, int> a({10,23,4,45}),
		   b({3,4,5,6});

	std::cout << "Series 'A': \n";
	std::cout << a << std::endl;
	std::cout << "Series 'B': \n";
	std::cout << b << std::endl;
	std::cout << "Append 'B' to 'A':\n";

	a = a.append(b);

	std::cout << a << std::endl;

	std::cout << "Print 'A':\n";

	a.Print();

	std::cout << "DataSeries Using Days:\n";

	DataSeries<Date, int> c({0,2,3,4,5}, Date(1), fromString("01-01-1990", "DD-mm-YYYY").date());

	c.Print();

	std::cout << "DataSeries Using Time:\n";

	DataSeries<Time, int> d({0,2,3,4,5}, Time(1), fromString("10:00", "HH:MM").time());

	d.Print();

	return 0;
}
