#include "bsg.h"
#include "utest/utest.h"

UTEST_MAIN();

UTEST(sum, exemple1) {
  const uint16_t expectedResult = 5;
  ASSERT_EQ(sum(2, 3), expectedResult);
}