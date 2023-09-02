#include "bsg.h"
#include <assert.h>
#include <stdio.h>

int main() {

  printf("[TEST] Hello, BSG!\n");

  assert(sum(2, 3) == 5);

  return 0;
}
