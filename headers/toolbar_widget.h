#pragma once 

#include "pch.h"
#include "timer_widget.h"

class ToolbarWidget : public QToolBar
{
    Q_OBJECT
public:
    explicit ToolbarWidget(QWidget& parent, TimerWidget& timerWidget);
    void CreateCategory();
    void DeleteCategory();
    void PauseTimer();
    void StartTimer();
    void StopTimer();

private:
    TimerWidget* m_timerWidget{};

};
