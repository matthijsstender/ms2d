#ifndef ENTITY_H
#define ENTITY_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>

#include "sprite.h"

class Entity {
  Entity();
  ~Entity();
public:
  Sprite* sprite;

  // data structure
	/// @brief add an Entity as a child of this Entity.
	/// Defines the data structure (parent/children relationship)
	/// @param child The Entity you want to add as a child.
	/// @return void
  void addChild(Entity* child);
  /// @brief remove this Entity from list of children.
  /// @param child The Entity you want to remove from your children.
  /// @return void
  void removeChild(Entity* child);

  /// @brief get the parent of this Entity.
  /// @return Entity* _parent
  Entity* parent() { return _parent; };

private:
  // data structure
	Entity* _parent; ///< @brief The _parent of this Entity
	std::vector<Entity*> _children; ///< @brief The _children of this Entity

  glm::vec2 position;
  glm::vec2 scale;
  float rotation;
};
#endif /* ENTITY_H */
