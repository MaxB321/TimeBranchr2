#include "pch.h"
#include "main_window.h"
#include "toolbar_widget.h"


MainWindow::MainWindow()
{
    setupUi(this);

    ToolbarWidget* toolbar = new ToolbarWidget(this);
    addToolBar(toolbar);
}

