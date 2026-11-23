#pragma once 

#include "pch.h"
#include "user_data.h"
#include "user_settings.h"
#include "timer_widget.h"
#include "enums.h"
#include "util.h"


class LogWidget : public QObject
{
    Q_OBJECT

public:
    explicit LogWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct, UserSettings& userSettingsStruct, TimerWidget& timerWidget);
    void AddLog();
    void ClearLogView();
    void DeleteLog();
    void DisplayLogs();
    void DisplayLogsAscending();
    void DisplayLogsDescending();
    std::string GetCurCategoryId();
    void GetDatetime();
    void InitLogTree();
    bool LogsDisplayed();
    void LoadLogs();
    void SetCurCategoryId(std::string& categoryId);


private:
    std::string m_curCategoryId{};
    TimerWidget& m_timerWidget;
    QTreeWidget& m_uiTreeWidget;
    UserData& m_userData;
    UserSettings& m_userSettings;


protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

};
