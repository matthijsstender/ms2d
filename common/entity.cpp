#include <common/entity.h>

Entity::Entity()
{
  xpos = 0.0f;
  ypos = 0.0f;
  xscale = 0.0f;
  yscale = 0.0f;
  rotation = 0.0f;
}

void Entity::addChild(Entity* child)
{
	if(child->_parent != NULL) {
		child->_parent->removeChild(child);
	}
	child->_parent = this;
	this->_children.push_back(child);
}
