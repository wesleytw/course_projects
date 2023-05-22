#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "canvas.h"

#include <QMainWindow>
#include <QMenu>
#include <QToolBar>
#include <QEventLoop>
#include <QCloseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void open();
    void quit();
    void createRectangle();
    void createBoundary();
    void createPath();
    void zoomIn();
    void zoomOut();
    void zoomFit();
    void panUp();
    void panDown();
    void panLeft();
    void panRight();
    void clear();
    void deleteObject();
    void query();
    void myQueryLoop();
    void closeEvent(QCloseEvent *);

private:
    void createActions();

private:
    Canvas * _canvas;
    QMenu * _fileMenu;
    QMenu * _editMenu;
    QMenu * _viewMenu;
    QToolBar * _fileToolbar;
    QToolBar * _editToolbar;
    QToolBar * _viewToolbar;
};

#endif // MAIN_WINDOW_H
