#ifndef REPOSITORY_BASE_HPP
#define REPOSITORY_BASE_HPP

#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <SQLiteCpp/SQLiteCpp.h>

#define DATABASE_NAME "sprint-manager-db.db3"

template <typename T>
class RepositoryBase
{
protected:
    std::string tableName;
    std::map<std::string, std::string> tableColumns;
    SQLite::Database db;

    virtual T mapToEntity(SQLite::Statement &query) = 0;
    void createTable();
    void setEntityId(T &entity, long newId)
    {
        entity.id = newId;
    }

public:
    RepositoryBase(const std::string &name, const std::map<std::string, std::string> &columns) : db(DATABASE_NAME, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE)
    {
        db.exec("PRAGMA foreign_keys = ON;");
        tableName = name;
        tableColumns = columns;
        createTable();
    }

    virtual ~RepositoryBase() = default;

    virtual bool save(T &entity) = 0;
    T findById(long id);
    std::vector<T> findAll();
    bool deleteById(long id);
};

// Implementações genéricas devem ficar aqui, pois RepositoryBase é uma classe abstrata

template <typename T>
void RepositoryBase<T>::createTable()
{
    std::string sqlCreateTable = "CREATE TABLE IF NOT EXISTS " + tableName + " (";

    bool first = true;
    for (const auto &column : tableColumns)
    {
        if (!first)
        {
            sqlCreateTable += ", ";
        }
        sqlCreateTable += column.first + " " + column.second;
        first = false;
    }
    sqlCreateTable += ");";

    db.exec(sqlCreateTable);
}

template <typename T>
T RepositoryBase<T>::findById(long id)
{
    SQLite::Statement query(db, "SELECT * FROM " + tableName + " WHERE id = ?");
    query.bind(1, static_cast<int>(id));

    if (query.executeStep())
    {
        return mapToEntity(query);
    }

    throw std::runtime_error("Entity not found");
}

template <typename T>
std::vector<T> RepositoryBase<T>::findAll()
{
    std::vector<T> results;
    SQLite::Statement query(db, "SELECT * FROM " + tableName);

    while (query.executeStep())
    {
        results.push_back(mapToEntity(query));
    }

    return results;
}

template <typename T>
bool RepositoryBase<T>::deleteById(long id)
{
    SQLite::Statement query(db, "DELETE FROM " + tableName + " WHERE id = ?");
    query.bind(1, static_cast<int>(id));

    int rowsModified = query.exec();
    return rowsModified > 0;
}

#endif // REPOSITORY_BASE_HPP