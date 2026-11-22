#pragma once 

#include "pch.h"
#include "user_data.h"
#include "user_settings.h"
#include "enums.h"
#include "util.h"


class LogWidget : public QObject
{
    Q_OBJECT

public:
    explicit LogWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct, UserSettings& userSettingsStruct);
    void AddLog();
    void ClearLogView();
    void DeleteLog();
    void DisplayLogs();
    void DisplayLogsAscending();
    void DisplayLogsDescending();
    void GetDatetime();
    void InitLogTree();
    bool LogsDisplayed();
    void LoadLogs();


private:
    QTreeWidget& m_uiTreeWidget;
    UserData& m_userData;
    UserSettings& m_userSettingsStruct;


protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

};
