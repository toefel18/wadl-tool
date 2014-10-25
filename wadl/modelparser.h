#ifndef MODELPARSER_H
#define MODELPARSER_H

#include "restapp.h"

#include <string>

namespace wadlxsd {
    class resource;
}

namespace wadl {

    class ModelParser {
    public:
        ModelParser();

        void parseXml();

        RestApp parseWadl(const std::string& location);

    private:

        void addResource(RestApp& app, Resource& parent);


        void printResource(std::string prefix, wadlxsd::resource resource);
        std::string extractMethods(wadlxsd::resource method);
    };

}
#endif // MODELPARSER_H
