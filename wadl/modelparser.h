#ifndef MODELPARSER_H
#define MODELPARSER_H

#include "restapp.h"

#include <string>

namespace wadlxsd {
    class resource;
    class method;
    class param;
}

namespace wadl {

    class ModelParser {
    public:
        ModelParser();
        RestApp* parseWadl(const std::string& location);

    private:

        Resource *createResource(wadlxsd::resource wadlResource, const std::string& basePath);
        void createChildResource(wadlxsd::resource wadlResource, Resource *parent);
        void configureResource(wadlxsd::resource wadlResource, Resource *resource);

        std::vector<Method*> extractMethods(wadlxsd::resource wadlResource);
        Method* createMethod(wadlxsd::method wadlMethod);

        std::vector<Param> extractParams(wadlxsd::resource wadlResource);
        Param createParam(wadlxsd::param wadlParam);

//        void printResource(std::string prefix, wadlxsd::resource resource);
        //        std::string extractMethods(wadlxsd::resource method);
    };

}
#endif // MODELPARSER_H
