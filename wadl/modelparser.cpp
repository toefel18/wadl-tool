#include "modelparser.h"

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/parser/validating/parser.hxx>

#include "wadl.hxx"

#include <memory>
#include <iostream>
#include "resource.h"

using namespace std;

namespace wadl {

    ModelParser::ModelParser()
    {
    }

    void ModelParser::parseXml(){
        try {

            unique_ptr<wadlxsd::application> wadlParse(wadlxsd::parseApplication("D:/projects-cpp/wadltool/resources/application.wadl", xml_schema::flags::dont_validate)); // xml_schema::flags::dont_validate
            shared_ptr<wadlxsd::application> app(std::move(wadlParse)); //convert to shared ptr for code completion to work

            //foreach (auto resourcesItr, app->getResources()) { // also works!
           for (auto resourcesItr = app->getResources().begin(); resourcesItr != app->getResources().end(); ++resourcesItr){
                cout << resourcesItr->getBase() << endl;
                for (auto resourceItr = resourcesItr->getResource().begin(); resourceItr != resourcesItr->getResource().end(); ++resourceItr) {
                    string path = resourcesItr->getBase().get();
                    path.pop_back();
                    printResource(path, *resourceItr);
                }
            }
        } catch (const xml_schema::exception& e) {
            cerr << e << endl;
        }

    }

    void ModelParser::printResource(string prefix, wadlxsd::resource resource) {
        string path = "";
        if(resource.getPath()) {
            path = resource.getPath().get();
        }

        cout << prefix << path << extractMethods(resource) << endl;

        for (wadlxsd::resources::resource_const_iterator resourceItr = resource.getResource1().begin(); resourceItr != resource.getResource1().end(); ++resourceItr) {
            printResource(prefix + path, *resourceItr);
        }
    }

    string ModelParser::extractMethods(wadlxsd::resource resource) {
        auto methods = resource.getMethod();

        string methodSum = "   ";
        for(wadlxsd::resource::method_const_iterator method = methods.begin(); method != methods.end(); ++method) {
            methodSum += method->getName().get() + " " + method->getId().get() + "()   ";
        }
        return methodSum;
    }


    RestApp ModelParser::parseWadl(const string &location) {
        RestApp app;

        Resource resource("test");
        Method method(HttpMethod::GET);
        QueryParam queryParam("start", "string");
        method.getQueryParams().push_back(queryParam);
        resource.getMethods().push_back(method);
        app.getResources().push_back(resource);

        return app;
    }

    void ModelParser::addResource(RestApp &app, Resource &parent){

    }

}
