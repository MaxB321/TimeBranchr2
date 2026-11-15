#include "pch.h"
#include "main_window.h"



MainWindow::MainWindow(UserData& userDataStruct, UserSettings& userSettingsStruct)
{
    setupUi(this);
    resize(1280, 720);
    setIconSize(QSize(25, 25));

    m_pTimerWidget = new TimerWidget(*timerLabel, *pauseLabel);
    m_pCategoryWidget = new CategoryWidget(*categoryTreeWidget, userDataStruct, userSettingsStruct);
    m_pToolbarWidget = new ToolbarWidget(*this, *m_pTimerWidget, *m_pCategoryWidget);
    addToolBar(m_pToolbarWidget);
}

