#pragma once

#include "pch.h"
#include "user_data.h"
#include "user_settings.h"
#include "enums.h"


class CategoryWidget : public QObject
{
    Q_OBJECT

public:
    explicit CategoryWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct, UserSettings& userSettingsStruct);
    void AddCategory();
    void AddSubCategory();
    void CleanupChildItems();
    void DisplayTotalTime(QTreeWidgetItem& item, int& time);
    void EditWidgetText();
    std::string FormatCategoryTime(int& time);
    std::string GetCurCategoryId();
    CategoryType GetCategoryType(QTreeWidgetItem& item);
    void HideSubcatTotal(); // may put this in CategoryMenu TU later
    void InitCategoryTree();
    bool IsCategorySelected(QTreeWidgetItem& item);
    bool IsInnerMostLayer();
    bool IsOuterMostLayer();
    void LoadCategories();
    void LoadSubCategories();
    void ShowSubcatTotalTime(); // may put this in CategoryMenu TU later
    void SortCategories();
    void UpdateCategoryTime();


private:
    QTreeWidget& m_pUiTreeWidget;
    UserData& m_pUserData;
    UserSettings& m_pUserSettingsStruct;

};

