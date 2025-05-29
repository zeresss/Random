#ifndef UNIFORM_REAL_DISTRIBUTION_H
#define UNIFORM_REAL_DISTRIBUTION_H

#define DEFINE_UNIFORM_REAL_DISTRIBUTION(NAME, TYPE, GENERATOR)\
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
        return distribution->min + (((TYPE) next##GENERATOR(generator) - min##GENERATOR()) / (max##GENERATOR() - min##GENERATOR())) * (distribution->max - distribution->min);\
    }\

#endif