#include "restapp.h"


namespace wadl {
    RestApp::RestApp()
    {
    }

    RestApp::Resources& RestApp::getResources(){
        return resources;
    }

    const RestApp::Resources& RestApp::getResources() const {
        return resources;
    }
}
