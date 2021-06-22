#include "IteratorBase.h"
IteratorBase& IteratorBase::operator++(int dummy)
{
        data++;
        idx++;
        return *this;
}
