#pragma once

#include "pch.h"
#include "generated/ui_mainwindow.h"
#include "toolbar_widget.h"
#include "timer_widget.h"


class MainWindow : public QMainWindow, public Ui_MainWindow
{
    Q_OBJECT
public:
    explicit MainWindow();

private:
    TimerWidget* m_timerWidget{};
    ToolbarWidget* m_toolbarWidget{};
};



