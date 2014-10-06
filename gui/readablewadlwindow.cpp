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

    ModelParser parser;
    parser.parseXml();
}

ReadableWadlWindow::~ReadableWadlWindow()
{
    delete ui;
}

