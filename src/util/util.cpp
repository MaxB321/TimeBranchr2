#include "pch.h"
#include "util.h"

static std::mt19937 CreateSeededEngine()
{
    std::random_device rd;
    std::array<std::mt19937::result_type, std::mt19937::state_size> seedData{};
    std::generate(seedData.begin(), seedData.end(), std::ref(rd));
    std::seed_seq seq(seedData.begin(), seedData.end());
    return std::mt19937(seq);
}

uuids::uuid Util::GenerateUuid()
{
    static std::mt19937 engine = CreateSeededEngine();
    static uuids::uuid_random_generator generator(engine);

    return generator();
}

std::string Util::GenerateUuidString()
{
    return uuids::to_string(GenerateUuid());
}

void Util::Debug::printItemMap(const std::unordered_map<std::string, QTreeWidgetItem*>& categoryItemMap)
{
    qDebug() << "categoryItemMap size:" << categoryItemMap.size();

    for (const auto& [key, item] : categoryItemMap) 
    {
        qDebug() << "Key:" << QString::fromStdString(key)
                 << "| Val:" << item
                 << "| Text:" << (item ? item->text(0) : "<null>");
    }
}

void Util::Debug::printItemMap(const std::unordered_map<std::string, CategoryType>& categoryItemMap)
{
    qDebug() << "categoryItemMap size:" << categoryItemMap.size();

    for (const auto& [key, val] : categoryItemMap) 
    {
        qDebug() << "Key:" << QString::fromStdString(key)
                 << "| Type:" << static_cast<uint8_t>(val);
    }
}
