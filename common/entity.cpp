#include <common/entity.h>

Entity::Entity()
{
  this->rotation = 0;
  this->position = glm::vec2(0,0);
  this->scale = glm::vec2(1,1);
}

void Entity::addChild(Entity* child)
{
	if(child->_parent != NULL) {
		child->_parent->removeChild(child);
	}
	child->_parent = this;
	this->_children.push_back(child);
}

void Entity::removeChild(Entity* child)
{
	std::vector< Entity* >::iterator it = _children.begin();
	while (it != _children.end()) {
		if ((*it) == child) {
			child->_parent = NULL;
			it = _children.erase(it);
		} else {
			++it;
		}
	}
}
