#include "engine.h"
#include "calibration.h"



StateEngine getEngineState(Engine engine){
    StateEngine stateEngine = ENGINE_OFF;

    if( engine.rpm == 0 ){
        stateEngine = ENGINE_OFF;
    }
    else{
        if( engine.rpm >= EngineRPMMaximum ){
        stateEngine = ENGINE_RPM_MAXIMUM;
        }
        else 
        {
        stateEngine = ENGINE_WORKING;
        }
    }
    return stateEngine;
    
}
