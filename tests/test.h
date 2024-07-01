#pragma once
#include <stdio.h>
#include <string.h>

extern int checks;
extern int failures;
#define CHECK(EXPR) \
    do { \
        ++checks; \
        if (!(EXPR)) { \
            fprintf(stderr, "%s(%d): check %s FAILED!\n", __FILE__, __LINE__, #EXPR); \
            ++failures;\
        } \
    } while(0)

inline void noop() {
}

extern void module2();
