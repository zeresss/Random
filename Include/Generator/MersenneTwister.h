#ifndef MERSENNE_TWISTER_GENERATOR_H
#define MERSENNE_TWISTER_GENERATOR_H

#define DEFINE_MERSENNE_TWISTER_GENERATOR(NAME, TYPE, INDEX_TYPE, WORD_SIZE, STATE_SIZE, MIDDLE_WORD, UPPER_MASK, LOWER_MASK, XOR_MASK, A, B, C, D, E, F, MULTIPLIER)\
    typedef struct {\
        TYPE state[STATE_SIZE];\
        INDEX_TYPE stateIndex;\
    } NAME;\
    \
    void init##NAME(NAME* generator, TYPE seed) {\
        generator->stateIndex = 0;\
        generator->state[0] = seed;\
        for (INDEX_TYPE index = 1; index < STATE_SIZE; index += 1) {\
            seed = MULTIPLIER * (seed ^ (seed >> (WORD_SIZE - 2))) + index;\
            generator->state[index] = seed;\
        }\
    }\
    \
    TYPE next##NAME(NAME* generator) {\
        TYPE result = (generator->state[generator->stateIndex] & UPPER_MASK) | (generator->state[(generator->stateIndex + 1) % STATE_SIZE] & LOWER_MASK);\
        TYPE twist = result >> 1;\
        if (result & 1) {\
            twist ^= XOR_MASK;\
        }\
        result = generator->state[(generator->stateIndex + MIDDLE_WORD) % STATE_SIZE] ^ twist;\
        generator->state[generator->stateIndex] = result;\
        generator->stateIndex = (generator->stateIndex + 1) % STATE_SIZE;\
        result ^= (result >> A);\
        result ^= (result << B) & C;\
        result ^= (result << D) & E;\
        result ^= (result >> F);\
        return result;\
    }\
    \
    TYPE min##NAME() {\
        return 0;\
    }\
    \
    TYPE max##NAME() {\
        return (1 << WORD_SIZE) - 1;\
    }\

#endif