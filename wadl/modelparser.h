#ifndef MODELPARSER_H
#define MODELPARSER_H

#include <string>
namespace wadl {
    class resource;
}

class ModelParser
{
public:
    ModelParser();

    void parseXml();

private:
    void printResource(std::string prefix, wadl::resource resource);
    std::string extractMethods(wadl::resource method);
};

#endif // MODELPARSER_H
