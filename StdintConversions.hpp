#ifndef ORO_STDINT_CONVERSIONS_H_
#define ORO_STDINT_CONVERSIONS_H_

#include <stdint.h>

template <typename U, typename V>
V convertIntTypes(U i) { return V(i); };

#endif
