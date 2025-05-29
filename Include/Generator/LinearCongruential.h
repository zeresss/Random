#ifndef LINEAR_CONGRUENTIAL_GENERATOR_H
#define LINEAR_CONGRUENTIAL_GENERATOR_H

#define DEFINE_LINEAR_CONGRUENTIAL_GENERATOR(NAME, TYPE, MULTIPLIER, INCREMENT, MODULUS)\
    typedef struct {\
        TYPE seed;\
    } NAME;\
    \
    void init##NAME(NAME* generator, TYPE seed) {\
        generator->seed = seed;\
    }\
    \
    TYPE next##NAME(NAME* generator) {\
        generator->seed = (MULTIPLIER * generator->seed + INCREMENT) % MODULUS;\
        return generator->seed;\
    }\
    \
    TYPE min##NAME() {\
        return 0;\
    }\
    \
    TYPE max##NAME() {\
        return MODULUS - 1;\
    }\
    
#endif