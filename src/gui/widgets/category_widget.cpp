#include "pch.h"
#include "category_widget.h"


CategoryWidget::CategoryWidget(QTreeWidget& uiTreeWidget, UserData& userDataStruct, UserSettings& userSettingsStruct)
    : m_uiTreeWidget(uiTreeWidget), m_userData(userDataStruct), m_userSettings(userSettingsStruct)
{
    uiTreeWidget.viewport()->installEventFilter(this);
    InitCategoryTree();

    connect(&m_uiTreeWidget, &QTreeWidget::itemDoubleClicked, this, &CategoryWidget::EditWidgetText);
}

void CategoryWidget::AddCategory()
{
    if (IsCurCategorySelected())
    {
        AddSubCategory(m_uiTreeWidget.currentItem());
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
    m_userData.categoryTypeMap[categoryId] = CategoryType::MainCategory;
    
    // m_uiTreeWidget.blockSignals(false);
    // log_widget.init_category(category_id, child_item_text, self.user_id)
    // self.sort_display()
}

void CategoryWidget::AddSubCategory(QTreeWidgetItem* selectedItem)
{
    if (IsInnerMostLayer())
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
    m_userData.categoryTypeMap[categoryId] = CategoryType::SubCategory;

    // parent_id = selected_item.data(0, Qt.ItemDataRole.UserRole)

    // self.cat_tree.blockSignals(False)
    // log_widget.init_subcategory(category_id, parent_id, child_item_text, self.user_id)
    // self.sort_display()
}

void CategoryWidget::CleanupChildItems(QTreeWidgetItem& item)
{
    while (item.childCount() > 0)
    {
        QTreeWidgetItem* curChild = item.child(0);
        CleanupChildItems(*curChild);
        FreeItem(GetCategoryId(curChild), curChild);
    }
    // put config deletion/update func here (prob multithreading)
}

void CategoryWidget::DeleteSelectedCategory()
{
    QTreeWidgetItem* curItem{m_uiTreeWidget.currentItem()};
    if (curItem && curItem->isSelected())
    {
        std::string categoryId = GetCategoryId(curItem);

        // log_widget._user_logs.pop(category_id, None)
        
        if (IsOuterMostLayer(curItem))
        {
            CleanupChildItems(*curItem);
            FreeItem(categoryId, curItem);
        }
        else
        {
            QTreeWidgetItem* parent = curItem->parent();
            // int oldTime = response.json()["category_time"]
            CleanupChildItems(*curItem);
            FreeItem(categoryId, curItem);

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
                // std::string outermostId = GetCategoryId(outmostItem);
                // outermost_time = response.json()["category_time"]
                // new_time = outermost_time - old_time
                // cat_widget.update_category_time(log_widget, CategoryType.MainCategory, outermost_item)
            }
                
        }
    }

    Util::Debug::printItemMap(m_userData.categoryItemMap);
    Util::Debug::printItemMap(m_userData.categoryTypeMap);
    
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

void CategoryWidget::FreeItem(const std::string& categoryId, QTreeWidgetItem* item)
{
    if (!item)
    {
        item = m_userData.categoryItemMap.at(categoryId);

        delete item;
        m_userData.categoryItemMap.erase(categoryId);
        m_userData.categoryTypeMap.erase(categoryId);
        return;
    }

    delete item;
    m_userData.categoryItemMap.erase(categoryId);
    m_userData.categoryTypeMap.erase(categoryId);
}

std::string CategoryWidget::GetCategoryId(QTreeWidgetItem* item)
{
    return item->data(0, Qt::ItemDataRole::UserRole).toString().toStdString();
}

CategoryType CategoryWidget::GetCategoryType(std::string& categoryId)
{
    return m_userData.categoryTypeMap[categoryId];
}

QTreeWidgetItem* CategoryWidget::GetSelectedCategory()
{
    return m_uiTreeWidget.currentItem();
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