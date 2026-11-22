#include "pch.h"
#include "log_widget.h"


LogWidget::LogWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct, UserSettings& userSettingsStruct)
    : m_uiTreeWidget(uiTreeWidget), m_userData(userDataStruct), m_userSettingsStruct(userSettingsStruct)
{
    uiTreeWidget.viewport()->installEventFilter(this);
    InitLogTree();

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

std::string LogWidget::GetCurCategoryId()
{
    return m_curCategoryId;
}

void LogWidget::GetDatetime()
{

}

void LogWidget::InitLogTree()
{
    QHeaderView* header = m_uiTreeWidget.header();
    header->setStretchLastSection(false);
    header->setSectionResizeMode(0, header->ResizeMode::Stretch);
    header->setSectionResizeMode(1, header->ResizeMode::Custom);
    m_uiTreeWidget.setColumnWidth(1, 125);
}

bool LogWidget::LogsDisplayed()
{
    return true;
}

void LogWidget::LoadLogs()
{

}

void LogWidget::SetCurCategoryId(std::string& categoryId)
{
    m_curCategoryId = categoryId;
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
