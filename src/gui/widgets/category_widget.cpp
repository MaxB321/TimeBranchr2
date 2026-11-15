#include "pch.h"
#include "category_widget.h"


CategoryWidget::CategoryWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct)
    : m_pUiTreeWidget(&uiTreeWidget), m_pUserData(&userDataStruct)
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

}

std::string CategoryWidget::GetCurCategoryId()
{

}

CategoryType CategoryWidget::GetCategoryType(QTreeWidgetItem& item)
{

}

void CategoryWidget::HideSubcatTotal() 
{

}

void CategoryWidget::InitCategoryTree()
{

}

bool CategoryWidget::IsCategorySelected(QTreeWidgetItem& item)
{

}

bool CategoryWidget::IsInnerMostLayer()
{

}

bool CategoryWidget::IsOuterMostLayer()
{

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
