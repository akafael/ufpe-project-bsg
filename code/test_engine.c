#include "engine.h"
#include "utest/utest.h"

UTEST_MAIN()

UTEST(engine, engineOff){
  Engine engine= {
    .rpm = 0,
    .velocity = 0,
    .gear = 1,
  };

  const StateEngine test_engine = getEngineState(engine);
  ASSERT_EQ(test_engine,ENGINE_OFF);
}
