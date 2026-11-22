#include "pch.h"
#include "log_widget.h"


LogWidget::LogWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct, UserSettings& userSettingsStruct)
    : m_uiTreeWidget(uiTreeWidget), m_userData(userDataStruct), m_userSettingsStruct(userSettingsStruct)
{
    uiTreeWidget.viewport()->installEventFilter(this);


}

void LogWidget::AddLog()
{

}

void LogWidget::ClearLogView()
{

}

void LogWidget::DeleteLog()
{

}

void LogWidget::DisplayLogs()
{

}

void LogWidget::DisplayLogsAscending()
{

}

void LogWidget::DisplayLogsDescending()
{

}

void LogWidget::GetDatetime()
{

}

bool LogWidget::LogsDisplayed()
{

}

void LogWidget::LoadLogs()
{

}


// OVERRIDES

// enables deselect widget capability
bool LogWidget::eventFilter(QObject* object, QEvent* event)
{
    if (object == m_uiTreeWidget.viewport() && event->type() == QEvent::MouseButtonPress) {
        auto* mouseEvent = static_cast<QMouseEvent*>(event);

        if (!m_uiTreeWidget.itemAt(mouseEvent->position().toPoint()))
            m_uiTreeWidget.clearSelection();
    }

    return false;
}
