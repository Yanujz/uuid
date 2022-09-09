#pragma once
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef char uuid_t[37];


uuid_t* uuid_gen(uuid_t* uuid);

#ifdef __cplusplus
}
#endif

