#ifndef LAGGED_FIBBONACCI_GENERATOR_H
#define LAGGED_FIBBONACCI_GENERATOR_H

#define DEFINE_LAGGED_FIBBONACCI_GENERATOR(NAME, TYPE, INDEX_TYPE, WORD_SIZE, STATE_SIZE, SHORT_LAG, LONG_LAG, OPERATION, MULTIPLIER, INCREMENT, MODULUS)\
    typedef struct {\
        TYPE state[STATE_SIZE];\
        INDEX_TYPE stateIndex;\
    } NAME;\
    \
    void init##NAME(NAME* generator, TYPE seed) {\
        generator->stateIndex = 0;\
        generator->state[0] = seed;\
        for (INDEX_TYPE index = 1; index < STATE_SIZE; index += 1) {\
            seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;;\
            generator->state[index] = seed;\
        }\
    }\
    \
    TYPE next##NAME(NAME* generator) {\
        TYPE result = generator->state[(generator->stateIndex + STATE_SIZE - SHORT_LAG) % STATE_SIZE] OPERATION generator->state[(generator->stateIndex + STATE_SIZE - LONG_LAG) % STATE_SIZE];\
        generator->state[generator->stateIndex] = result;\
        generator->stateIndex = (generator->stateIndex + 1) % STATE_SIZE;\
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