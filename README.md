# UUID Generator

This repository provides a C library for generating Universally Unique Identifiers (UUIDs). UUIDs are 128-bit values used to uniquely identify information. This library offers a simple C API to generate UUIDs.

## Features

- Generates UUIDs in a standard 36-character string format.
- Simple C API for integration with C/C++ projects.

## Getting Started

### Prerequisites

- A C/C++ compiler.


### Using the Library

To use the UUID generation function in your project, include the header file `uuid.h` and link against the compiled object file.

#### Example Usage

```c
#include <stdio.h>
#include "uuid.h"

int main() {
    uuid_t uuid;
    uuid_t* result = uuid_gen(&uuid);

    if (result) {
        printf("Generated UUID: %s\n", *result);
    } else {
        printf("Failed to generate UUID.\n");
    }

    return 0;
}
```

### Output example
```
Generated UUID: c930620a-4cf4-4bff-afb1-5def003fcbef
```