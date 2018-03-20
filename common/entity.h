#ifndef ENTITY_H
#define ENTITY_H

#include <GL/glew.h>
#include <glfw3.h>
#include "sprite.h"

class Entity {
  Entity();
  ~Entity();
public:
  Sprite* sprite;
  float xpos;
  float ypos;
  float xscale
  float yscale;
  float rotation;

  void addChild(Entity* child);

  Entity* parent() { return _parent; };

private:
  Entity* _parent;
  std::vector<Entity*> _children;
};
#endif /* ENTITY_H */
