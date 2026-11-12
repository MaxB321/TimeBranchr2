#pragma once 

#include "pch.h"
#include "enums.h"


class TimerWidget : public QObject
{
    Q_OBJECT
public:
    explicit TimerWidget(QLabel* timerLabel, QLabel* pauseLabel);

    void PauseTimer();
    void SetTimerColor(DisplayMode displayMode);
    void StartTimer();
    void StopTimer();

private:
    std::string FormatTime(uint32_t seconds);
    void UpdateTimer();

    uint32_t m_elapsedSeconds{};
    QTimer m_timer{};
    QLabel* m_timerLabel{};
    QLabel* m_pauseLabel{};
};

