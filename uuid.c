#include "uuid.h"
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define NBYTES 16
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

uuid_t *uuid_gen(uuid_t *uuid)
{
    unsigned char rnd[NBYTES];
    char strHex[2 * NBYTES + 1];
    char v[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    static bool srandInit = false;

    if (false == srandInit)
    {
        srandInit = true;
        auto val = (unsigned int)time(NULL);
        srand(val);
    }

    // 1. Generate 16 random bytes = 128 bits
    for (int i = 0; i < ARRAY_SIZE(rnd); ++i)
    {
        rnd[i] = rand() & 0xFF;
    }

    // 2. Adjust certain bits according to RFC 4122 section 4.4.
    // This just means do the following
    // (a) set the high nibble of the 7th byte equal to 4 and
    // (b) set the two most significant bits of the 9th byte to 10'B,
    //     so the high nibble will be one of {8,9,A,B}.
    rnd[6] = 0x40 | (rnd[6] & 0xf);
    rnd[8] = 0x80 | (rnd[8] & 0x3f);

    // 3. Convert the adjusted bytes to hex values
    for (int i = 0, j = 0, dashIdx = 0; i < 16; ++i, j += 2)
    {
        char byte = rnd[i];
        char hi = ((byte >> 4) & 0xF);
        char lo = byte & 0xF;
        strHex[j] = v[hi];
        strHex[j + 1] = v[lo];
    }

    // 4. Add four hyphen '-' characters
    memset(uuid, '\0', sizeof(uuid_t));
    strncpy(uuid, strHex, 8);
    strncat(uuid, "-", 1);
    strncat(uuid, &strHex[8], 4);
    strncat(uuid, "-", 1);
    strncat(uuid, &strHex[12], 4);
    strncat(uuid, "-", 1);
    strncat(uuid, &strHex[16], 4);
    strncat(uuid, "-", 1);
    strncat(uuid, &strHex[20], 12);

    // Return the UUID string
    return uuid;
}
