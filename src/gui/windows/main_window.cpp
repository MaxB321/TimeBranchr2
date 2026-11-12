#include "pch.h"
#include "main_window.h"
#include "toolbar_widget.h"
#include "timer_widget.h"


MainWindow::MainWindow()
{
    setupUi(this);
    resize(1280, 720);
    setIconSize(QSize(25, 25));

    

    ToolbarWidget* toolbar = new ToolbarWidget(this);
    addToolBar(toolbar);


}

