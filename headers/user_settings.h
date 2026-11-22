#pragma once

#include "pch.h"

struct UserSettings
{
    bool DarkMode{true};
    bool CategorySortAscending{true};
    bool LogSortAscending{true};
    bool ShowSubcatTotals{true};
    bool ShowUsername{true};
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
