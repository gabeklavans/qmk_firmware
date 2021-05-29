#ifndef NUMPADULATOR_H
#define NUMPADULATOR_H

#include "quantum.h"

#define ___ KC_NO

#define LAYOUT( \
    K00,           K01, \
    K10, K11, K12, K13, \
    K20, K21, K22,      \
    K30, K31, K32, K33, \
    K40, K41, K42,      \
    K50,      K51
    ) { \
  { K00, ___, ___, K03 },  \
  { K10, K11, K12, K13 },  \
  { K20, K21, K22, ___ },  \
  { K30, K31, K32, K33 },  \
  { K40, K41, K42, ___ },  \
  { K50, ___, K51, ___ },  \
}

#endif
