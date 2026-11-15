#include "pch.h"
#include "main_window.h"



MainWindow::MainWindow()
{
    setupUi(this);
    resize(1280, 720);
    setIconSize(QSize(25, 25));

    m_pTimerWidget = new TimerWidget(timerLabel, pauseLabel);
    m_pToolbarWidget = new ToolbarWidget(*this, *m_pTimerWidget);
    addToolBar(m_pToolbarWidget);
}

