#ifndef REGISTRY_H
#define REGISTRY_H

#include <stddef.h>

#define MAX_KEYS 64   // just... the maximum amount of keys, 
#define MAX_KEY_LEN 32 // okay if you didn't know what these variables I'm documenting do,
#define MAX_VALUE_LEN 64 // I'm sorry but you're STUPI- OnO
#define MAX_CHILDREN 16

typedef struct RegistryEntry {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];

    // Children, YAY registry is a tree, but made of keys
    struct RegistryEntry* children[MAX_CHILDREN];
    int child_count;
} RegistryEntry;

extern RegistryEntry root_registry;

#endif
