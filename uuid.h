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

#ifndef UUID_H
#define UUID_H
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file uuid.h
 * @brief Functions for generating UUIDs (Universally Unique Identifiers).
 *
 * This library provides an interface for generating UUIDs in the standard 128-bit format
 * as a string. The generated UUID follows the RFC 4122 standard.
 */

/**
 * @brief Data type to represent a UUID as a string.
 *
 * A UUID is represented as a string of 37 characters, which includes 32 hexadecimal
 * characters and 4 hyphens (`-`), in the format `xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx`.
 */
typedef char uuid_t[37];

/**
 * @brief Generates a UUID and stores it in the provided parameter.
 *
 * This function generates a random UUID (version 4) and formats it as a string with
 * hyphens, according to the RFC 4122 standard. The generated UUID is then stored in the
 * provided `uuid_t` variable.
 *
 * @param uuid A pointer to a `uuid_t` variable where the generated UUID string will be stored.
 * @return A pointer to the `uuid_t` variable containing the generated UUID string.
 *
 * @note The UUID string will be 37 characters long (32 hexadecimal digits and 4 hyphens).
 */
uuid_t* uuid_gen(uuid_t* uuid);

#ifdef __cplusplus
}
#endif
#endif // UUID_H
