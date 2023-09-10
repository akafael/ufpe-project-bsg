#include "engine.h"
#include "utest/utest.h"

UTEST_MAIN();

UTEST(engine, engineOff){
  Engine engine= {
    .rpm = 25,
    .velocity = 150,
    .gear = 4,
  };

  const StateEngine test_engine = getEngineState(engine);
  ASSERT_EQ(test_engine,ENGINE_OFF);
}
