#include "modelparser.h"

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/parser/validating/parser.hxx>

#include "wadl.hxx"

#include <memory>
#include <iostream>

using namespace std;

ModelParser::ModelParser()
{
}

void ModelParser::parseXml(){
    try {

        unique_ptr<wadl::application> wadlParse(wadl::parseApplication("D:/projects-cpp/wadltool/application.wadl", xml_schema::flags::dont_validate)); // xml_schema::flags::dont_validate
        shared_ptr<wadl::application> app(std::move(wadlParse)); //convert to shared ptr for code completion to work

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

void ModelParser::printResource(string prefix, wadl::resource resource) {
    string path = "";
    if(resource.getPath()) {
        path = resource.getPath().get();
    }

    cout << prefix << path << extractMethods(resource) << endl;

    for (wadl::resources::resource_const_iterator resourceItr = resource.getResource1().begin(); resourceItr != resource.getResource1().end(); ++resourceItr) {
        printResource(prefix + path, *resourceItr);
    }
}

string ModelParser::extractMethods(wadl::resource resource) {
    auto methods = resource.getMethod();

    string methodSum = "   ";
    for(wadl::resource::method_const_iterator method = methods.begin(); method != methods.end(); ++method) {
        methodSum += method->getName().get() + " " + method->getId().get() + "()   ";
    }
    return methodSum;
}
