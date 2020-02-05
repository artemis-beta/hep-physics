#include "ExponentialPDF.hxx"
#include "Histogram.hxx"

#include <map>

using namespace PHYS::PDF;
using namespace PHYS::Data;

double simpleCDF(const double x)
{
    return x+2;
}

int main()
{
    std::cout << "Generating Exponential Data..." << std::endl;
    Histogram * histo = new Histogram(10,0,10);
    Exponential* pdf = new Exponential(0.8);
    std::vector<double> vals = pdf->generate(100);
    for(auto& val : vals)
    {
        histo->Fill(val);
    }

    std::cout << "HISTOGRAM\n\n" << std::endl;

    histo->consolePlot();

    return 0;
}
