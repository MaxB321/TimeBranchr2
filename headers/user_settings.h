#pragma once

#include "pch.h"

struct UserSettings
{
    bool DarkMode{};
    bool CategorySortAscending{};
    bool LogSortAscending{};
    bool ShowSubcatTotals{};
    bool ShowUsername{};
};


namespace SettingsFile
{
    void CreateFile();
    bool FileExists();
    bool GetFlag();
    void Load();
    void Save();
    void SetFlag();
}
