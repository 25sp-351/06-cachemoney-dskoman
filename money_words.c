#include "money_words.h"
#include <stdio.h>

#define MAX_UNIT_STRING_LENGTH 10

char small_units[20][MAX_UNIT_STRING_LENGTH] = {
    "",        "one",     "two",       "three",    "four",
    "five",    "six",     "seven",     "eight",    "nine",
    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

char tens_units[10][MAX_UNIT_STRING_LENGTH] = {
    "",      "",      "twenty",  "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"};

char big_units[4][MAX_UNIT_STRING_LENGTH] = {"", "thousand", "million",
                                             "billion"};

void print_englishified_number(int num) {
  if (num == 0) {
    printf("zero\n");
    return;
  }

  int big_unit_index = 0;
  while (num > 0) {
    int small_unit = num % 1000;
    if (small_unit > 0) {

      if (big_unit_index > 0 && small_unit > 0) {
        printf(", ");
      }

      if (small_unit > 0) {
        int hundreds = small_unit / 100;

        if (hundreds > 0) {
          printf("%s hundred", small_units[hundreds]);
          if (small_unit % 100 > 0) {
            printf(" and ");
          }
        }

        int tens = small_unit % 100;
        if (tens < 20) {
          printf("%s", small_units[tens]);
        } else {
          int tens_digit = tens / 10;
          int ones_digit = tens % 10;
          printf("%s", tens_units[tens_digit]);

          if (ones_digit > 0) {
            printf("-%s", small_units[ones_digit]);
          }
        }

        if (big_unit_index > 0) {
          printf(" %s", big_units[big_unit_index]);
        }
      }
    }
    num /= 1000;
    big_unit_index++;
  }
  printf("\n");
}