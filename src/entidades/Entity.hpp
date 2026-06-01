#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <set>

class Entity
{
protected:
    long id;

public:
    Entity(long id) : id(id)
    {
    }

    long getId() const
    {
        return id;
    };

    template <typename T>
    friend class RepositoryBase;
};
#endif // ENTITY_HPP