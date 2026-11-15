#pragma once

#include "pch.h"

struct UserSettings
{
    bool CategorySortAscending{};
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
