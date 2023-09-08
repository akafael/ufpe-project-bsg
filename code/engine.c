#include "engine.h"
#include "calibration.h"


StateEngine getEngineState(Engine engine){

    if(engine.rpm == 0){
        return  ENGINE_OFF;
    }
    if (engine.rpm == 7800){
        return ENGINE_MAXIMUM;
    }
    if(engine.rpm > 0){
        return  ENGINE_WORKING;
    }   
    return ENGINE_OFF;
}