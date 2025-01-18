#include <stdio.h>
#include "uuid.h"

int main() {
    uuid_t uuid;
    uuid_t* result = uuid_gen(&uuid);

    if (result) {
        printf("%s\n", *result);
    } else {
        printf("Failed to generate UUID.\n");
    }

    return 0;
}