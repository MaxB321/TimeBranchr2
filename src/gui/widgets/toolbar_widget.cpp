#include "pch.h"
#include "toolbar_widget.h"

ToolbarWidget::ToolbarWidget(QWidget& parent, TimerWidget& timerWidget)
    : QToolBar(&parent), m_timerWidget(&timerWidget)
{
    setMovable(false);
    setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);

    QAction* newCategoryButton = new QAction(QIcon(":/icons/plus32.png"), "New Category", this);
    newCategoryButton->setStatusTip("Creates New Category");
    addAction(newCategoryButton);

    QAction* deleteCategoryButton = new QAction(QIcon(":/icons/minus32.png"), "Delete Category", this);
    deleteCategoryButton->setStatusTip("Deletes Selected Category");
    addAction(deleteCategoryButton);

    QAction* startButton = new QAction(QIcon(":/icons/play.png"), "Start", this);
    startButton->setStatusTip("Start Timer");
    addAction(startButton);

    QAction* pauseButton = new QAction(QIcon(":/icons/pause.png"), "Pause/Resume", this);
    pauseButton->setStatusTip("Pause or Resume Timer");
    addAction(pauseButton);

    QAction* stopButton = new QAction(QIcon(":/icons/stop.png"), "Stop", this);
    stopButton->setStatusTip("Stop Timer");
    addAction(stopButton);

    connect(pauseButton, &QAction::triggered, this, &ToolbarWidget::PauseTimer);
    connect(startButton, &QAction::triggered, this, &ToolbarWidget::StartTimer);
    connect(stopButton, &QAction::triggered, this, &ToolbarWidget::StopTimer);
}

void ToolbarWidget::CreateCategory()
{

}

void ToolbarWidget::DeleteCategory()
{

}

void ToolbarWidget::PauseTimer()
{
    m_timerWidget->PauseTimer();
}

void ToolbarWidget::StartTimer()
{
    m_timerWidget->StartTimer();
}

void ToolbarWidget::StopTimer()
{
    m_timerWidget->StopTimer();
}
