#ifndef UNIFORM_INTEGER_DISTRIBUTION_H
#define UNIFORM_INTEGER_DISTRIBUTION_H

#define DEFINE_UNIFORM_INTEGER_DISTRIBUTION(NAME, TYPE, GENERATOR)\
    typedef struct {\
        TYPE min;\
        TYPE max;\
    } NAME;\
    \
    void init##NAME(NAME* distribution, TYPE min, TYPE max) {\
        distribution->min = min;\
        distribution->max = max;\
    }\
    \
    TYPE next##NAME(NAME* distribution, GENERATOR* generator) {\
        TYPE result;\
        do {\
            result = next##GENERATOR(generator);\
        } while (result - min##GENERATOR() >= (max##GENERATOR() - min##GENERATOR()) - (max##GENERATOR() - min##GENERATOR()) % (distribution->max - distribution->min + 1));\
        return distribution->min + (result - min##GENERATOR()) % (distribution->max - distribution->min + 1);\
    }\

#endif