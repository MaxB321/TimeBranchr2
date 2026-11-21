#pragma once

#include "pch.h"


namespace Util
{
    uuids::uuid GenerateUuid();
    std::string GenerateUuidString();

    namespace Debug
    {
        void printItemMap(const std::unordered_map<std::string, QTreeWidgetItem*>& categoryItemMap);
    }
}
