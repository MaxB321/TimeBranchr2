#include "pch.h"
#include "timer_widget.h"

//Public 
TimerWidget::TimerWidget(QLabel* timerLabel, QLabel* pauseLabel)
    : m_timerLabel(timerLabel), m_pauseLabel(pauseLabel)
{
    m_pauseLabel->setVisible(false);
    m_timer.setInterval(1000);

    QObject::connect(&m_timer, &QTimer::timeout, this, &TimerWidget::UpdateTimer);
}

void TimerWidget::PauseTimer()
{
    if (m_timer.isActive())
    {
        m_timer.stop();
        m_pauseLabel->setVisible(true);
    }
    else if (!m_timer.isActive() && m_timerLabel->text() != "00:00:00")
    {
        m_timer.start();
        m_pauseLabel->setVisible(false);
    }
}

void TimerWidget::SetTimerColor(DisplayMode displayMode)
{

}

void TimerWidget::StartTimer()
{
    if (!m_timer.isActive() && m_timerLabel->text() == "00:00:00")
        m_timer.start();
}

void TimerWidget::StopTimer()
{
    m_timer.stop();
    m_elapsedSeconds = 0;
    m_timerLabel->setText("00:00:00");
    m_pauseLabel->setVisible(false);
}


// Private
std::string TimerWidget::FormatTime(uint32_t seconds)
{
    uint32_t s{seconds % 60};
    uint32_t minutes{static_cast<uint32_t>(std::floor((seconds % 3600) / 60))};
    uint32_t hours{static_cast<uint32_t>(std::floor(seconds / 3600))};

    return std::format("{:02}:{:02}:{:02}", hours, minutes, s);
}

void TimerWidget::UpdateTimer()
{
    m_elapsedSeconds += 1;
    m_timerLabel->setText(QString::fromStdString(FormatTime(m_elapsedSeconds)));
}
