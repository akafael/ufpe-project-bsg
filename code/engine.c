#include "engine.h"
#include "calibration.h"


StateEngine getEngineState(Engine engine){

    if(engine.rpm == 0){
        return  ENGINE_OFF;
    }
    else if (engine.rpm == EngineRPMMaximum){
        return ENGINE_RPM_MAXIMUM;
    }
    else if(engine.rpm > 0){
        return  ENGINE_WORKING;
    }
    else{
        return ENGINE_OFF;
    }
}
