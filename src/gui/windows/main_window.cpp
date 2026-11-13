#include "pch.h"
#include "main_window.h"



MainWindow::MainWindow()
{
    setupUi(this);
    resize(1280, 720);
    setIconSize(QSize(25, 25));

    m_timerWidget = new TimerWidget(timerLabel, pauseLabel);
    m_toolbarWidget = new ToolbarWidget(*this, *m_timerWidget);
    addToolBar(m_toolbarWidget);
}

