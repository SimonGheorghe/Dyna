#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite sprite, sf::Texture textureSheet):
	m_sprite(sprite), m_textureSheet(textureSheet), lastAnimation(NULL), priorityAnimation(NULL)
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
	m_animation[key] = new Animation(
		m_sprite, m_textureSheet, 
		animationTimer, 
		startFrameX, startFrameY, framesX, framesY, width, height);
}

void AnimationComponent::Play(const std::string key, const float& dt, const bool priority)
{
	if (this->lastAnimation != m_animation[key])
	{
		if(this->lastAnimation == NULL)
			this->lastAnimation = m_animation[key];
		else
		{
			this->lastAnimation->Reset();
			this->lastAnimation = m_animation[key];
		}
	}
	m_animation[key]->Play(dt);
}

void AnimationComponent::Play(const std::string key, const float& dt, const float& modifier, const float& modifier_max, const bool priority)
{
	if (this->priorityAnimation)
	{
		if (this->priorityAnimation == m_animation[key])
		{
			if (this->lastAnimation != m_animation[key])
			{
				if (this->lastAnimation == NULL)
					this->lastAnimation = m_animation[key];
				else
				{
					this->lastAnimation->Reset();
					this->lastAnimation = m_animation[key];
				}
			}

			if (m_animation[key]->Play(dt))
			{
				this->priorityAnimation = NULL;
			}
		}
	}
	m_animation[key]->Play(dt, abs(modifier/ modifier_max));
}
