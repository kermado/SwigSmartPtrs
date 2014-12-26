#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>

#include "watch_ptr.hpp"
#include "Watchable.hpp"

class Entity : public Watchable
{
public:
    Entity() = default;
    ~Entity() = default;

    std::string value() const
    {
        return "Entity::value()";
    }
};

Entity* create_entity_pointer()
{
    return new Entity();
}

watch_ptr<Entity> create_entity_watch_pointer()
{
    return watch_ptr<Entity>(new Entity());
}

#endif