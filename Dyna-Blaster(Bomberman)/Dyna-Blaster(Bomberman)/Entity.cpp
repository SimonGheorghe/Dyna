#include "Entity.h"

void Entity::SetPosition(const float x, const float y)
{
	for(auto sprite: m_sprite)
		sprite.setPosition(x, y);
}

void Entity::Render(sf::RenderTarget& target, uint16_t state)
{
	target.draw(m_sprite[state]);
}

void Entity::SetTexture(std::vector<sf::Texture>& textures)
{
	for (auto texture : textures)
	{
		sf::Sprite sprite;
		sprite.setTexture(texture);
		m_sprite.push_back(sprite);
	}
}
