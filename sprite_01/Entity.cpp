
#include "Entity.hpp"

#include "Component.hpp"

#include <string>
#include <iostream>

Entity::Entity(EntityManager& manager)
: manager(manager)
{}

Entity::Entity(std::string name, EntityManager& manager)
: name(name), manager(manager)
{}

void Entity::update(const float dt)
{
   for(auto& component: components) {
      component->update(dt);
   }
}

void Entity::render()
{
   for (auto& component: components) {
      component->render();
   }
}

void Entity::destroy()
{
   active = false;
}

void Entity::list_all_components() const
{
   for (auto& map_element: component_type_map) {
      std::cout << "  Component<" << map_element.first->name() << ">" << std::endl;
   }
}

void Entity::initialize() {
   for (auto& map_element: component_type_map) {
      map_element.second->initialize();
   }
}

