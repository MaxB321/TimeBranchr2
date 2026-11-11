#pragma once 

#include "pch.h"
#include "enums.h"


class TimerWidget
{
public:
    explicit TimerWidget(QLabel* timerLabel, QLabel* pauseLabel);

    void PauseTimer();
    void SetTimerColor(DisplayMode displayMode);
    void StartTimer();
    void StopTimer();

private:
    std::string DisplayTimer(uint32_t seconds);
    void Update_Timer();

    uint32_t m_elapsedSeconds{};
    QTimer m_timer{};
    QLabel* m_timerLabel{};
    QLabel* m_pauseLabel{};
};

