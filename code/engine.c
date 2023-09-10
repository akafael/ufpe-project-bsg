#include "engine.h"
#include "calibration.h"


StateEngine getEngineState(Engine engine){

    if(engine.rpm == 0){
        return  ENGINE_OFF;
    }
    if (engine.rpm == 7700){
        return ENGINE_RPM_MAXIMUM;
    }
    if(engine.rpm > 0){
        return  ENGINE_WORKING;
    }   
}
