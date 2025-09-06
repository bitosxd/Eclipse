#include "Registry.h"
#include <string.h>

RegistryEntry root_registry = {
    .key = "ROOT",
    .value = "",
    .child_count = 0
};
