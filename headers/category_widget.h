#pragma once

#include "pch.h"
#include "user_data.h"
#include "user_settings.h"
#include "enums.h"
#include "util.h"


class CategoryWidget : public QObject
{
    Q_OBJECT

public:
    explicit CategoryWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct, UserSettings& userSettingsStruct);
    void AddCategory();
    void AddSubCategory(QTreeWidgetItem* selectedItem);
    void CleanupChildItems(QTreeWidgetItem& item);
    void DeleteSelectedCategory();
    void DisplayTotalTime(QTreeWidgetItem& item, int& time); // will do after LogWidget
    void EditWidgetText();
    std::string FormatCategoryTime(int& time); // will do after LogWidget
    std::string GetCategoryId(QTreeWidgetItem* item);
    CategoryType GetCategoryType(QTreeWidgetItem& item);
    void HideSubcatTotal(); // MenuWidget will call this
    void InitCategoryTree();
    bool IsCurCategorySelected();
    bool IsInnerMostLayer(QTreeWidgetItem* item = nullptr);
    bool IsOuterMostLayer(QTreeWidgetItem* item = nullptr);
    void LoadCategories(); // will do after config
    void LoadSubCategories(); // will do after config
    void ShowSubcatTotalTime(); // MenuWidget will call this
    void SortCategories(); // will do after MenuWidget
    void UpdateCategoryTime(); // will do after LogWidget


private:
    QTreeWidget& m_uiTreeWidget;
    UserData& m_userData;
    UserSettings& m_userSettingsStruct;


protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

};

