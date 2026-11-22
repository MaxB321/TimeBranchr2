#pragma once

#include "pch.h"
#include "enums.h"


namespace Util
{
    uuids::uuid GenerateUuid();
    std::string GenerateUuidString();

    namespace Debug
    {
        void printItemMap(const std::unordered_map<std::string, QTreeWidgetItem*>& categoryItemMap);
        void printItemMap(const std::unordered_map<std::string, CategoryType>& categoryItemMap);
    }
}
