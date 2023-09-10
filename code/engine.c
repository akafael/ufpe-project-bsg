#include "engine.h"
#include "calibration.h"


StateEngine getEngineState(Engine engine){

    if(engine.rpm == 0){
        return  ENGINE_OFF;
    }
    if (engine.rpm == EngineRPMMaximum){
        return ENGINE_RPM_MAXIMUM;
    }
    if(engine.rpm > 0){
        return  ENGINE_WORKING;
    }

    return ENGINE_OFF;
}
