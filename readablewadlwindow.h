#ifndef READABLEWADLWINDOW_H
#define READABLEWADLWINDOW_H

#include <QMainWindow>
#include "wadl.hxx"
#include <string>

namespace Ui {
class ReadableWadlWindow;
}

class ReadableWadlWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReadableWadlWindow(QWidget *parent = 0);
    ~ReadableWadlWindow();

    void parseXml();
    void printResource(std::string prefix, wadl::resource resource);
    std::string extractMethods(wadl::resource::method_sequence method);

private:
    Ui::ReadableWadlWindow *ui;
};

#endif // READABLEWADLWINDOW_H
