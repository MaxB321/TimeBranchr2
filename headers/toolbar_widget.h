#pragma once 

#include "pch.h"
#include "timer_widget.h"
#include "category_widget.h"
#include "log_widget.h"


class ToolbarWidget : public QToolBar
{
    Q_OBJECT

public:
    explicit ToolbarWidget(QWidget& parent, TimerWidget& timerWidget, CategoryWidget& categoryWidget, LogWidget& logWidget);
    void CreateCategory();
    void DeleteCategory();
    void PauseTimer();
    void StartTimer();
    void StopTimer();

private:
    TimerWidget& m_timerWidget;
    CategoryWidget& m_categoryWidget;
    LogWidget& m_logWidget;

};
