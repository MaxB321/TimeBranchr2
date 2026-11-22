#include "pch.h"
#include "category_widget.h"


CategoryWidget::CategoryWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct, UserSettings& userSettingsStruct)
    : m_uiTreeWidget(uiTreeWidget), m_userData(userDataStruct), m_userSettingsStruct(userSettingsStruct)
{
    uiTreeWidget.viewport()->installEventFilter(this);
    CategoryWidget::InitCategoryTree();

    connect(&m_uiTreeWidget, &QTreeWidget::itemDoubleClicked, this, &CategoryWidget::EditWidgetText);
}

void CategoryWidget::AddCategory()
{
    if (IsCurCategorySelected())
    {
        CategoryWidget::AddSubCategory(m_uiTreeWidget.currentItem());
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

void CategoryWidget::AddSubCategory(QTreeWidgetItem* selectedItem)
{
    if (CategoryWidget::IsInnerMostLayer())
        return;
     
    // self.cat_tree.blockSignals(True)

    QTreeWidgetItem* childItem = new QTreeWidgetItem();
    childItem->setText(0, "Child Item");
    childItem->setText(1, "0 Sec"); 
    childItem->setFlags(childItem->flags() | Qt::ItemFlag::ItemIsEditable);
    selectedItem->addChild(childItem);
    std::string childItemText = childItem->text(0).toStdString();

    std::string categoryId{Util::GenerateUuidString()};
    childItem->setData(0, Qt::ItemDataRole::UserRole, QString::fromStdString(categoryId));
    m_userData.categoryItemMap[categoryId] = childItem;


    // parent_id = selected_item.data(0, Qt.ItemDataRole.UserRole)

    // self.cat_tree.blockSignals(False)
    // log_widget.init_subcategory(category_id, parent_id, child_item_text, self.user_id)
    // self.sort_display()
}

void CategoryWidget::CleanupChildItems(QTreeWidgetItem& item)
{
    int childCount = item.childCount();
    if (childCount == 0)
        return;
    
    uint32_t i{0};
    uint32_t j{0};

    while (i < childCount)
    {
        QTreeWidgetItem* curChild = item.child(0);

        j = 0;
        int innerChildCount = curChild->childCount();
        while (j < innerChildCount)
        {
            QTreeWidgetItem* innerChild = curChild->child(0);
            std::string categoryId = innerChild->data(0, Qt::ItemDataRole::UserRole).toString().toStdString();
            curChild->removeChild(innerChild);
            delete innerChild;
            m_userData.categoryItemMap.erase(categoryId);
            ++j;
        }
        std::string categoryId = curChild->data(0, Qt::ItemDataRole::UserRole).toString().toStdString();
        item.removeChild(curChild);
        delete curChild;
        m_userData.categoryItemMap.erase(categoryId);
        ++i;
    }
    // put config deletion/update func here (prob multithreading)
}

void CategoryWidget::DeleteSelectedCategory()
{
    QTreeWidgetItem* curItem{m_uiTreeWidget.currentItem()};
    if (curItem && curItem->isSelected())
    {
        std::string categoryId = CategoryWidget::GetCategoryId(curItem);

        // log_widget._user_logs.pop(category_id, None)
        QTreeWidgetItem* parent = curItem->parent();
        
        if (CategoryWidget::IsOuterMostLayer(curItem))
        {
            CategoryWidget::CleanupChildItems(*curItem);
            delete m_uiTreeWidget.takeTopLevelItem(m_uiTreeWidget.indexOfTopLevelItem(curItem));
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
        m_userData.categoryItemMap.erase(categoryId);
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

CategoryType CategoryWidget::GetCategoryType(std::string& categoryId)
{
    return m_userData.categoryTypeMap[categoryId];
}

void CategoryWidget::HideSubcatTotal() 
{

}

void CategoryWidget::InitCategoryTree()
{
    QHeaderView* header = m_uiTreeWidget.header();
    header->setStretchLastSection(false);
    header->setSectionResizeMode(0, header->ResizeMode::Stretch);
    header->setSectionResizeMode(1, header->ResizeMode::Custom);
    m_uiTreeWidget.setColumnWidth(1, 125);
    
    // CategoryWidget::SortCategories();
}

bool CategoryWidget::IsCurCategorySelected()
{
    QTreeWidgetItem* curItem{m_uiTreeWidget.currentItem()};
    if (curItem && curItem->isSelected())
        return true;
    
    return false;
}

bool CategoryWidget::IsInnerMostLayer(QTreeWidgetItem* item)
{
    if (!item)
    {
        QTreeWidgetItem* curItem = m_uiTreeWidget.currentItem();
        QTreeWidgetItem* parent = curItem->parent();
        if (!parent)
            return false;

        if (parent->parent())
            return true;
        return false;
    }

    QTreeWidgetItem* parent = item->parent();
    if (parent)
    {
        if (parent->parent())
            return true;
        else
            return false;
    }

    return false;
}

bool CategoryWidget::IsOuterMostLayer(QTreeWidgetItem* item)
{
    if (!item)
    {
        QTreeWidgetItem* curItem = m_uiTreeWidget.currentItem();
        QTreeWidgetItem* parent = curItem->parent();
        if (!parent)
            return true;

        return false;
    }

    QTreeWidgetItem* parent = item->parent();
    if (!parent)
        return true;

    return false;

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


// OVERRIDES

// enables deselect widget capability
bool CategoryWidget::eventFilter(QObject* object, QEvent* event)
{
    if (object == m_uiTreeWidget.viewport() && event->type() == QEvent::MouseButtonPress) {
        auto* mouseEvent = static_cast<QMouseEvent*>(event);

        if (!m_uiTreeWidget.itemAt(mouseEvent->position().toPoint()))
            m_uiTreeWidget.clearSelection();
    }

    return false;
}