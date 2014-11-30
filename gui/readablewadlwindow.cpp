#include "readablewadlwindow.h"
#include "ui_readablewadlwindow.h"
#include <iostream>
#include <memory>

#include <modelparser.h>

using namespace std;

ReadableWadlWindow::ReadableWadlWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReadableWadlWindow) {
    ui->setupUi(this);

    wadl::ModelParser parser;
    wadl::RestApp *app = parser.parseWadl("dummy");
    for (wadl::Resource* res : app->getAllResources()) {
        cout << res->getFullPath() << endl;
    }

}

ReadableWadlWindow::~ReadableWadlWindow()
{
    delete ui;
}



