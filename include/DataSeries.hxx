#ifndef __DATASERIES_HXX__
#define __DATASERIES_HXX__

#include "DynamicArray.hxx"

namespace PHYS
{
    namespace Data
    {
        template<class index_type, class data_type>
        class DataSeries : public DynamicArray<data_type>
        {
            private:
                DynamicArray<index_type> _index;
        };
    };
};

#endif