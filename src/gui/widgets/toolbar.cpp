#include "pch.h"
#include "toolbar.h"

ToolbarWidget::ToolbarWidget(QWidget* parent)
    : QToolBar(parent)
{
    setMovable(false);
    setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);

    QAction* newCategoryButton = new QAction(QIcon(":/icons/plus32.png"), "New Category", this);
    newCategoryButton->setStatusTip("Creates New Category");
    QAction* deleteCategoryButton = new QAction(QIcon(":/icons/minus32.png"), "Delete Category", this);
    deleteCategoryButton->setStatusTip("Deletes Selected Category");
    QAction* startButton = new QAction(QIcon(":/icons/play.png"), "Start", this);
    startButton->setStatusTip("Start Timer");
    QAction* pauseButton = new QAction(QIcon(":/icons/pause.png"), "Pause/Resume", this);
    pauseButton->setStatusTip("Pause or Resume Timer");
    QAction* stopButton = new QAction(QIcon(":/icons/stop.png"), "Stop", this);
    stopButton->setStatusTip("Stop Timer");

    
    addAction(newCategoryButton);
    addAction(deleteCategoryButton);
    addAction(startButton);
    addAction(pauseButton);
    addAction(stopButton);
}