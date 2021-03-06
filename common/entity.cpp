#include <common/entity.h>

Entity::Entity()
{
  this->rotation = glm::vec3(0,0,0);
  this->position = glm::vec3(0,0,0);
  this->scale = glm::vec3(1,1,1);

  _sprite = NULL;
}

Entity::~Entity()
{
	deleteSprite();
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

void Entity::addSprite(Sprite* spr)
{
	deleteSprite();
	//_sprite = new Sprite("");
	_sprite = spr;
}

void Entity::addSprite(const std::string& filename)
{
	this->addSprite(filename, 0.5f, 0.5f);
}

void Entity::addSprite(const std::string& filename, float pivotx, float pivoty)
{
	deleteSprite();
	_sprite = new Sprite(filename);
}
