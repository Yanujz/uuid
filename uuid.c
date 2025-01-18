/*
 * MIT License
 *
 * Copyright (c) 2025 Yanujz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "uuid.h"
#include <stdbool.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#define NBYTES    16
#define ARRAY_SIZE(x)    (sizeof(x) / sizeof(x[0]))

uuid_t* uuid_gen(uuid_t* uuid)
{
    unsigned char rnd[NBYTES];
    char          str_hex[2 * NBYTES + 1]; // Hex string will be 32 characters long + null terminator
    char          hex_digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    static bool   srand_init   = false;

    if(!srand_init)
    {
        srand_init = true;

        #ifdef _WIN32
        FILETIME ft;
        GetSystemTimeAsFileTime(&ft);
        unsigned long long time = (((unsigned long long)ft.dwHighDateTime) << 32) | ft.dwLowDateTime;
        srand((unsigned int)(time & 0xFFFFFFFF));  // Use lower 32 bits for seeding
        #else
        struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);
        srand((unsigned int)(ts.tv_nsec + ts.tv_sec));  // Use high-resolution time for seeding
        #endif
    }

    // 1. Generate 16 random bytes = 128 bits
    for(int i = 0; i < ARRAY_SIZE(rnd); ++i)
    {
        rnd[i] = rand() & 0xFF;
    }

    // 2. Adjust certain bits according to RFC 4122 section 4.4
    // (a) set the high nibble of the 7th byte equal to 4
    // (b) set the two most significant bits of the 9th byte to 10'B
    rnd[6] = 0x40 | (rnd[6] & 0xf);  // Set version to 4
    rnd[8] = 0x80 | (rnd[8] & 0x3f); // Set variant to 10

    // 3. Convert the adjusted bytes to hex values
    for(int i = 0, j = 0; i < 16; ++i, j += 2)
    {
        char byte = rnd[i];
        char hi   = ((byte >> 4) & 0xF);
        char lo   = byte & 0xF;
        str_hex[j]     = hex_digits[hi];
        str_hex[j + 1] = hex_digits[lo];
    }
    str_hex[32] = '\0';  // Null-terminate the string

    // 4. Add four hyphen '-' characters manually to match UUID format
    // Format: xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
    memset(uuid, '\0', sizeof(uuid_t));

    // Copying hex string parts into UUID format
    strncpy((char*)uuid, str_hex, 8);       // First 8 characters
    strncat((char*)uuid, "-", 1);           // Hyphen
    strncat((char*)uuid, &str_hex[8], 4);   // Next 4 characters
    strncat((char*)uuid, "-", 1);           // Hyphen
    strncat((char*)uuid, &str_hex[12], 4);  // Next 4 characters
    strncat((char*)uuid, "-", 1);           // Hyphen
    strncat((char*)uuid, &str_hex[16], 4);  // Next 4 characters
    strncat((char*)uuid, "-", 1);           // Hyphen
    strncat((char*)uuid, &str_hex[20], 12); // Last 12 characters

    // Return the UUID string
    return uuid;
}
