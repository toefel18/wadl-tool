#include "modelparser.h"

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/parser/validating/parser.hxx>

#include "wadl.hxx"
#include "wadlparseexception.h"

#include <memory>
#include <iostream>
#include "resource.h"

using namespace std;

namespace wadl {

    ModelParser::ModelParser()
    {
    }

    RestApp* ModelParser::parseWadl(const string &location) {
        try {
            unique_ptr<wadlxsd::application> wadlParse(wadlxsd::parseApplication("D:/projects-cpp/wadltool/resources/application.wadl", xml_schema::flags::dont_validate)); // xml_schema::flags::dont_validate
            shared_ptr<wadlxsd::application> wadlApp(std::move(wadlParse)); //convert to shared ptr for code completion to work

            RestApp* app = new RestApp(location);
            for (auto wadlResources : wadlApp->getResources()) {
                std::string resourcesBase = *wadlResources.getBase();
                for (auto wadlResource : wadlResources.getResource()) {
                    Resource* resource = createResource(wadlResource, resourcesBase);
                    app->getResources().push_back(resource);
                }
            }
            return app;
        } catch (const xml_schema::exception& e) {
            cerr << e << endl;
            throw new WadlParseException(e.what(), __FILE__, __LINE__);
        }
    }

    Resource* ModelParser::createResource(wadlxsd::resource wadlResource, const std::string& basePath) {
        Resource* resource = new Resource(basePath + *wadlResource.getPath());
        configureResource(wadlResource, resource);
        return resource;
    }

    void ModelParser::createChildResource(wadlxsd::resource wadlResource, Resource *parent) {
        Resource* resource = new Resource(*wadlResource.getPath(), parent); // adds itself to children of parent
        configureResource(wadlResource, resource);
    }


    void ModelParser::configureResource(wadlxsd::resource wadlResource, Resource *resource) {
        std::vector<Method *> extractedMethods = extractMethods(wadlResource);
        resource->getMethods().insert(resource->getMethods().end(), extractedMethods.begin(), extractedMethods.end());

        std::vector<Param> params = extractParams(wadlResource);
        std::vector<Param> &rParams = resource->getParams();
        rParams.insert(rParams.end(), params.begin(), params.end());

        for (auto childResource: wadlResource.getResource1()) {
            createChildResource(childResource, resource);
        }
    }


    std::vector<Method *> ModelParser::extractMethods(wadlxsd::resource wadlResource) {
        std::vector<Method *> methods;
        for (auto wadlMethod: wadlResource.getMethod()) {
            Method *method = createMethod(wadlMethod);
            methods.push_back(method);
        }
        return methods;
    }

    Method *ModelParser::createMethod(wadlxsd::method wadlMethod) {
        Method * method = new Method(*wadlMethod.getId(), toHttpMethod(*wadlMethod.getName()));
        return method;
    }


    std::vector<Param> ModelParser::extractParams(wadlxsd::resource wadlResource)  {
        std::vector<Param> params;
        for (auto wadlParam: wadlResource.getParam()) {
            Param param = createParam(wadlParam);
            params.push_back(param);
        }
        return params;
    }

    Param ModelParser::createParam(wadlxsd::param wadlParam) {
        return Param(*wadlParam.getName(), *wadlParam.getStyle(), wadlParam.getType().text_content());
    }

}
