#include "Entity.h"

void Entity::SetPosition(const float x, const float y)
{
	for(auto sprite: m_sprites)
		sprite.setPosition(x, y);
}

void Entity::Render(sf::RenderTarget& target, uint16_t state)
{
	target.draw(m_sprites[state]);
}

