#include "restapp.h"


namespace wadl {
    RestApp::RestApp(const std::string &wadlFilename)
        :wadlFilename(wadlFilename)
    {
    }

    RestApp::Resources& RestApp::getResources(){
        return resources;
    }

    const RestApp::Resources& RestApp::getResources() const {
        return resources;
    }


    RestApp::Resources RestApp::getAllResources() const {
        Resources allResources;
        for (Resource* res : resources) {
            allResources.push_back(res);
            Resources resDescendants = res->getDescendants();
            allResources.insert(allResources.end(), resDescendants.begin(), resDescendants.end());
        }
        return allResources;
    }


}
