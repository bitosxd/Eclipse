#ifndef REGISTRY_H
#define REGISTRY_H

#define MAX_KEY_LEN 32
#define MAX_VALUE_LEN 64
#define MAX_CHILDREN 16

typedef struct RegistryEntry {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];

    // Now we have children, YAY, and this utility is made for enabling some beta things
    struct RegistryEntry* children[MAX_CHILDREN];
    int child_count;
} RegistryEntry;

extern RegistryEntry root_registry;

// This creates a key
RegistryEntry* create_key(RegistryEntry* parent, const char* name, const char* value);

#endif
