#pragma once 

#include "pch.h"

struct UserData
{
    std::unordered_map<std::string, std::string> categories{};
    std::unordered_map<std::string, std::string> subCategories{};
    std::unordered_map<std::string, QTreeWidgetItem*> categoryItemMap{};
    std::unordered_map<std::string, std::vector<int>> logs{};
    std::unordered_map<std::string, std::vector<std::chrono::system_clock::time_point>> logsDatetime{};

    std::string userName{};
};

namespace DataFile
{
    void CreateFile();
    bool FileExists();
    std::string GetUserName();
    void Load();
    void Save();
    void SetUserName(std::string& name);
}
