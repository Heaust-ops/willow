#include "engine.h"
#include "Log.h"


int main()
{    
    Willow::Log::Init();
    WI_INFO("Logger Started");
    Initialise();
    WI_CORE_WARN("Starting App");
    AppInit();
    WI_CORE_WARN("Exited App");

    return 0;
}
