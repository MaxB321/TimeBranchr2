#pragma once

#include "pch.h"
#include "generated/ui_mainwindow.h"
#include "toolbar_widget.h"
#include "timer_widget.h"
#include "category_widget.h"
#include "log_widget.h"


class MainWindow : public QMainWindow, public Ui_MainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(UserData& userDataStruct, UserSettings& userSettingsStruct);

private:
    CategoryWidget* m_pCategoryWidget{};
    LogWidget* m_pLogWidget{};
    TimerWidget* m_pTimerWidget{};
    ToolbarWidget* m_pToolbarWidget{};
    
};



