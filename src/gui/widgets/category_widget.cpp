#include "pch.h"
#include "category_widget.h"


CategoryWidget::CategoryWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct, UserSettings& userSettingsStruct)
    : m_pUiTreeWidget(uiTreeWidget), m_pUserData(userDataStruct), m_pUserSettingsStruct(userSettingsStruct)
{

}

void CategoryWidget::AddCategory()
{

}

void CategoryWidget::AddSubCategory()
{

}

void CategoryWidget::CleanupChildItems()
{

}

void CategoryWidget::DisplayTotalTime(QTreeWidgetItem& item, int& time)
{

}

void CategoryWidget::EditWidgetText()
{

}

std::string CategoryWidget::FormatCategoryTime(int& time)
{
    return " ";
}

std::string CategoryWidget::GetCurCategoryId()
{
    return " ";
}

CategoryType CategoryWidget::GetCategoryType(QTreeWidgetItem& item)
{
    return CategoryType::MainCategory;
}

void CategoryWidget::HideSubcatTotal() 
{

}

void CategoryWidget::InitCategoryTree()
{

}

bool CategoryWidget::IsCategorySelected(QTreeWidgetItem& item)
{
    return true;
}

bool CategoryWidget::IsInnerMostLayer()
{
    return true;
}

bool CategoryWidget::IsOuterMostLayer()
{
    return true;
}

void CategoryWidget::LoadCategories()
{

}

void CategoryWidget::LoadSubCategories()
{

}

void CategoryWidget::ShowSubcatTotalTime()
{

}

void CategoryWidget::SortCategories()
{

}

void CategoryWidget::UpdateCategoryTime()
{

}
