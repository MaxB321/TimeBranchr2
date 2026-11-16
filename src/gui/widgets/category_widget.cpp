#include "pch.h"
#include "category_widget.h"


CategoryWidget::CategoryWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct, UserSettings& userSettingsStruct)
    : m_uiTreeWidget(uiTreeWidget), m_userData(userDataStruct), m_userSettingsStruct(userSettingsStruct)
{
    connect(&m_uiTreeWidget, &QTreeWidget::itemDoubleClicked, this, &CategoryWidget::EditWidgetText);
}

void CategoryWidget::AddCategory()
{
    if (IsCurCategorySelected())
    {
        CategoryWidget::AddSubCategory();
        return;
    }

    // m_uiTreeWidget.blockSignals(true);

    QTreeWidgetItem* childItem = new QTreeWidgetItem(&m_uiTreeWidget);
    childItem->setText(0, "New Category");
    childItem->setText(1, "0 Sec"); 
    childItem->setFlags(childItem->flags() | Qt::ItemFlag::ItemIsEditable);

    std::string childItemText{childItem->text(0).toStdString()};

    std::string categoryId{Util::GenerateUuidString()};
    childItem->setData(0, Qt::ItemDataRole::UserRole, QString::fromStdString(categoryId));
    m_userData.categoryItemMap[categoryId] = childItem;


    
    // m_uiTreeWidget.blockSignals(false);
    // log_widget.init_category(category_id, child_item_text, self.user_id)
    // self.sort_display()
}

void CategoryWidget::AddSubCategory()
{

}

void CategoryWidget::CleanupChildItems(QTreeWidgetItem& item)
{

}

void CategoryWidget::DeleteSelectedCategory()
{
    QTreeWidgetItem* curItem{m_uiTreeWidget.currentItem()};
    if (curItem && curItem->isSelected())
    {
        std::string categoryId = CategoryWidget::GetCategoryId(curItem);

        // log_widget._user_logs.pop(category_id, None)
        QTreeWidgetItem* parent = curItem->parent();
        
        if (CategoryWidget::IsOuterMostLayer())
        {
            CategoryWidget::CleanupChildItems(*curItem);
            m_uiTreeWidget.takeTopLevelItem(m_uiTreeWidget.indexOfTopLevelItem(curItem));
            // remove from UserData->categoryItemMap
        }
        else
        {
            // int oldTime = response.json()["category_time"]
            std::string parentId = CategoryWidget::GetCategoryId(parent);
            CategoryWidget::CleanupChildItems(*curItem);
            parent->removeChild(curItem);

            if (!parent->parent()) // middle layer
            {
                // parent_time = response.json()["category_time"]
                // new_time = parent_time - old_time
                // cat_widget.update_category_time(log_widget, CategoryType.MainCategory, parent)
            } 
            else // inner layer
            {
                // parent_time = response.json()["category_time"]
                // new_time = parent_time - old_time
                // cat_widget.update_category_time(log_widget, CategoryType.SubCategory, parent)

                // QTreeWidgetItem* outmostItem = parent->parent();
                // std::string outermostId = CategoryWidget::GetCategoryId(outmostItem);
                // outermost_time = response.json()["category_time"]
                // new_time = outermost_time - old_time
                // cat_widget.update_category_time(log_widget, CategoryType.MainCategory, outermost_item)
            }
                
        }
            
    } 
    
    // if (m_uiTreeWidget.topLevelItemCount() == 0)
        // log_widget.clear_log_view()
}

void CategoryWidget::DisplayTotalTime(QTreeWidgetItem& item, int& time)
{

}

void CategoryWidget::EditWidgetText()
{
    QTreeWidgetItem* curItem{m_uiTreeWidget.currentItem()};
    m_uiTreeWidget.editItem(curItem, 0);
}

std::string CategoryWidget::FormatCategoryTime(int& time)
{
    return " ";
}

std::string CategoryWidget::GetCategoryId(QTreeWidgetItem* item)
{
    return item->data(0, Qt::ItemDataRole::UserRole).toString().toStdString();
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

bool CategoryWidget::IsCurCategorySelected()
{
    QTreeWidgetItem* curItem{m_uiTreeWidget.currentItem()};
    if (curItem && curItem->isSelected())
        return true;
    
    return false;
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
