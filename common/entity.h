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

#include "common/sprite.h"

class Entity {
public:
  Entity(); ///< @brief Constructor of an Entity
  virtual ~Entity(); ///< @brief Destructor of an Entity

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
  // sprite
	/// @brief get the Sprite from this Entity.
	/// @return Sprite* _sprite
	Sprite* sprite_1() { return _sprite; };
	/// @brief add a Sprite to this Entity by Sprite*.
	/// @param spr A pointer to a Sprite.
	/// @return void
	void addSprite(Sprite* spr);
	/// @brief add a Sprite to this Entity by filename.
	/// @param filename The filename of the image you want to add as a Sprite.
	/// @return void
	void addSprite(const std::string& filename);
  /// @brief add a Sprite to this Entity.
  /// @param filename The filename of the image you want to add as a Sprite.
  /// @param pivotx The x component of the pivotpoint.
  /// @param pivoty The y component of the pivotpoint.
  /// @return void
  void addSprite(const std::string& filename, float pivotx, float pivoty);
  /// @brief get the parent of this Entity.
  /// @return Entity* _parent
  Entity* parent() { return _parent; };

private:
  // data structure
	Entity* _parent; ///< @brief The _parent of this Entity
	std::vector<Entity*> _children; ///< @brief The _children of this Entity

  // sprite
  Sprite* _sprite; ///< @brief The _sprite of this Entity

  glm::vec2 position;
  glm::vec2 scale;
  float rotation;

  /// @brief delete the Sprite of this Entity.
  /// @return void
  void deleteSprite() {
    if (_sprite != NULL) {
      delete _sprite;
      _sprite = NULL;
    }
  };
};
#endif /* ENTITY_H */
