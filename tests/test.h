#pragma once
#include <stdio.h>

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

extern void test_vk_1_0();
extern void test_vk_1_1();
extern void test_vk_1_2();
extern void test_vk_1_3();
