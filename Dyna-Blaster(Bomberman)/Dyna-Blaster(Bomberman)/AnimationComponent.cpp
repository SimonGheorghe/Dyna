#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite sprite, sf::Texture textureSheet):
	m_sprite(sprite), m_textureSheet(textureSheet)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : m_animation)
	{
		delete i.second;
	}
}

void AnimationComponent::AddAnimation(
	const std::string key,
	float animationTimer,
	int startFrameX, int startFrameY, int framesX, int framesY, int width, int height)
{
	m_animation[key] =new Animation(
		m_sprite, m_textureSheet, 
		animationTimer, 
		startFrameX, startFrameY, framesX, framesY, width, height);
}

void AnimationComponent::Play(const std::string key, const float& dt)
{
	m_animation[key]->Play(dt);
}