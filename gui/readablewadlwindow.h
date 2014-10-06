#ifndef READABLEWADLWINDOW_H
#define READABLEWADLWINDOW_H

#include <QMainWindow>
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


private:
    Ui::ReadableWadlWindow *ui;
};

#endif // READABLEWADLWINDOW_H
