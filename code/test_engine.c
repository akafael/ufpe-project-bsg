#include "calibration.h"
#include "engine.h"
#include "utest/utest.h"

UTEST_MAIN()

UTEST(engine, engineOff) {
  Engine engine = {
      .rpm = 0,
      .velocity = 0,
      .gear = 0,
  };

  const StateEngine test_engine = getEngineState(engine);
  ASSERT_EQ(test_engine, ENGINE_OFF);
}

UTEST(engine, engineWorking) {
  Engine engine = {
      .rpm = 25,
      .velocity = 150,
      .gear = 4,
  };

  const StateEngine test_engine = getEngineState(engine);
  ASSERT_EQ(test_engine, ENGINE_WORKING);
}

UTEST(engine, maxRPM) {
  Engine engine = {
      .rpm = EngineRPMMaximum,
      .velocity = 150,
      .gear = 4,
  };

  const StateEngine test_engine = getEngineState(engine);
  ASSERT_EQ(test_engine, ENGINE_RPM_MAXIMUM);
}
