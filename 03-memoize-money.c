#include <stdio.h>

#include "money_words.h"
#include "memoize.h"

#define CACHE_TEST_SIZE 10000

void memoize_test() {
  memoize_cache_t *my_cache = memoize_init(200, 0);
  int num_map[CACHE_TEST_SIZE];

  long long int user_input = 0;

  for (int scanf_result;
       (printf(">> "), scanf_result = scanf("%lld", &user_input)) != EOF;) {
    int cache_index = memoize_insert(my_cache, user_input);
    print_englishified_number(user_input);
  }
  memoize_free(my_cache);
}

int main(int argc, char *argv[]) {
  memoize_test();
  return 0;
}
