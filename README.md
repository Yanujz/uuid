# UUID Generator

This repository provides a C library for generating Universally Unique Identifiers (UUIDs). UUIDs are 128-bit values used to uniquely identify information. This library offers a simple C API to generate UUIDs.

## Features

- Generates UUIDs in a standard 36-character string format (e.g., `xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx`).
- Simple and easy-to-use C API for integration with C/C++ projects.
- Cross-platform: works on both Unix-like systems (Linux, macOS) and Windows.

## Getting Started

### Prerequisites

- A C/C++ compiler (e.g., GCC, Clang, MSVC).
- CMake 3.10 or higher to build the project.

### Building the Library

1. Clone the repository:
```bash
   git clone https://github.com/Yanujz/uuid.git
   cd uuid-generator
```

2.  Create a build directory and configure the project with CMake:
```bash
mkdir build
cd build
cmake ..
```

3. Build the project

``` bash
cmake --build .
```

4. (Optional) Install the library to a system directory:

```bash
sudo cmake --install .
```
This will install the library and headers to default system directories like /usr/local/lib and /usr/local/include. You can modify the installation paths in the CMakeLists.txt if necessary.


### Using the Library
To use the UUID generation function in your project, include the header file uuid.h and link against the compiled object file or the installed library.

1. Include the header file in your C code:
```c
#include "uuid.h"
```
2. Link the library when compiling your project. You can either link the static library (libuuid.a) or compile uuid.c directly in your project.

### Example Usage
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

### Output Example:
```
Generated UUID: c930620a-4cf4-4bff-afb1-5def003fcbef
```


## CMake Integration Example
If you want to use the UUID library as a submodule in another CMake-based project, add the UUID library as a subdirectory in your main CMakeLists.txt file:
```
cmake_minimum_required(VERSION 3.10)

project(example VERSION 1.0 LANGUAGES C)

# Add subdirectory for UUID library (adjust path as needed)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../uuid ${CMAKE_BINARY_DIR}/uuid_build)

# Create the executable for your project
add_executable(${PROJECT_NAME} main.c)

# Link against the UUID library
target_link_libraries(${PROJECT_NAME} PUBLIC uuid)
```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.