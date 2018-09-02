#pragma once

#include "quefrency.h"

#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
  #include <avr/io.h>
  #include <avr/interrupt.h>
#endif
#endif

#define LAYOUT( \
  LA1, LA2, LA3, LA4, LA5, LA6, LA7, RA1, RA2, RA3, RA4, RA5, RA6,      RA8, \
  LB1, LB2, LB3, LB4, LB5, LB6,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, \
  LC1, LC2, LC3, LC4, LC5, LC6,      RC1, RC2, RC3, RC4, RC5, RC6,      RC8, \
  LD1,      LD3, LD4, LD5, LD6, LD7, RD1, RD2, RD3, RD4,      RD6, RD7, RD8, \
       LE2, LE3,      LE5,      LE7, RE1,           RE4, RE5,      RE7 \
  ) \
  { \
  /* left half */ \
    { LA1,   LA2,   LA3,   LA4,   LA5,   LA6,   LA7,   KC_NO }, \
    { LB1,   LB2,   LB3,   LB4,   LB5,   LB6,   KC_NO, KC_NO }, \
    { LC1,   LC2,   LC3,   LC4,   LC5,   LC6,   KC_NO, KC_NO }, \
    { LD1,   KC_NO, LD3,   LD4,   LD5,   LD6,   LD7,   KC_NO }, \
    { KC_NO, LE2,   LE3,   KC_NO, LE5,   KC_NO, LE7,   KC_NO }, \
    /* right half */ \
    { RA1,   RA2,   RA3,   RA4,   RA5,   RA6,   KC_NO, RA8 }, \
    { RB1,   RB2,   RB3,   RB4,   RB5,   RB6,   RB7,   RB8 }, \
    { RC1,   RC2,   RC3,   RC4,   RC5,   RC6,   KC_NO, RC8 }, \
    { RD1,   RD2,   RD3,   RD4,   KC_NO, RD6,   RD7,   RD8 }, \
    { RE1,   KC_NO, KC_NO, RE4,   RE5,   KC_NO, RE7,   KC_NO } \
  }
