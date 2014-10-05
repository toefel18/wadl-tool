#include "readablewadlwindow.h"
#include "ui_readablewadlwindow.h"
#include <iostream>
#include <memory>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/parser/validating/parser.hxx>

using namespace std;

ReadableWadlWindow::ReadableWadlWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReadableWadlWindow) {
    ui->setupUi(this);

    parseXml();
}

ReadableWadlWindow::~ReadableWadlWindow()
{
    delete ui;
}

void ReadableWadlWindow::parseXml(){
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

void ReadableWadlWindow::printResource(string prefix, wadl::resource resource) {
    string path = "";
    if(resource.getPath()) {
        path = resource.getPath().get();
    }

    cout << prefix << path << extractMethods(resource.getMethod()) << endl;

    for (wadl::resources::resource_const_iterator resourceItr = resource.getResource1().begin(); resourceItr != resource.getResource1().end(); ++resourceItr) {
        printResource(prefix + path, *resourceItr);
    }
}

string ReadableWadlWindow::extractMethods(wadl::resource::method_sequence methods) {
    string methodSum = "   ";
    for(wadl::resource::method_const_iterator method = methods.begin(); method != methods.end(); ++method) {
        methodSum += method->getName().get() + " " + method->getId().get() + "()   ";
    }
    return methodSum;
}
