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
    void DisplayTotalTime(QTreeWidgetItem& item, int& time);
    void EditWidgetText();
    std::string FormatCategoryTime(int& time);
    std::string GetCategoryId(QTreeWidgetItem* item);
    CategoryType GetCategoryType(QTreeWidgetItem& item);
    void HideSubcatTotal(); // may put this in CategoryMenu TU later
    void InitCategoryTree();
    bool IsCurCategorySelected();
    bool IsInnerMostLayer(QTreeWidgetItem* item = nullptr);
    bool IsOuterMostLayer(QTreeWidgetItem* item = nullptr);
    void LoadCategories();
    void LoadSubCategories();
    void ShowSubcatTotalTime(); // may put this in CategoryMenu TU later
    void SortCategories();
    void UpdateCategoryTime();


private:
    QTreeWidget& m_uiTreeWidget;
    UserData& m_userData;
    UserSettings& m_userSettingsStruct;


protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

};

