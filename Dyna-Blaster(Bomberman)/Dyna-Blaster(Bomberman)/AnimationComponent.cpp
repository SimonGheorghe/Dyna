#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
	:m_sprite(sprite), m_textureSheet(textureSheet), lastAnimation(NULL), priorityAnimation(NULL)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : m_animations)
	{
		delete i.second;
	}
}

const bool& AnimationComponent::isDone(const std::string key)
{
	return m_animations[key]->isDone();
}

void AnimationComponent::AddAnimation(const std::string key,
	float animationTimer,
	int startFrameX, int startFrameY, int framesX, int framesY, int width, int height
)
{
	m_animations[key] = new Animation(
		m_sprite, m_textureSheet,
		animationTimer,
		startFrameX, startFrameY, framesX, framesY, width, height
	);
}

const bool& AnimationComponent::Play(const std::string key, const float& dt, const bool priority)
{
	if (this->priorityAnimation)
	{
		if (this->priorityAnimation == m_animations[key])
		{
			if (this->lastAnimation != m_animations[key])
			{
				if (this->lastAnimation == NULL)
					this->lastAnimation = m_animations[key];
				else
				{
					this->lastAnimation->Reset();
					this->lastAnimation = m_animations[key];
				}
			}

			if (m_animations[key]->Play(dt))
			{
				this->priorityAnimation = NULL;
			}
		}
	}
	else
	{
		if (priority)
		{
			this->priorityAnimation = m_animations[key];
		}

		if (this->lastAnimation != m_animations[key])
		{
			if (this->lastAnimation == NULL)
				this->lastAnimation = m_animations[key];
			else
			{
				this->lastAnimation->Reset();
				this->lastAnimation = m_animations[key];
			}
		}

		m_animations[key]->Play(dt);
	}

	return m_animations[key]->isDone();
}

const bool& AnimationComponent::Play(const std::string key, const float& dt, const float& modifier, const float& modifier_max, const bool priority)
{
	if (this->priorityAnimation)
	{
		if (this->priorityAnimation == m_animations[key])
		{
			if (this->lastAnimation != m_animations[key])
			{
				if (this->lastAnimation == NULL)
					this->lastAnimation = m_animations[key];
				else
				{
					this->lastAnimation->Reset();
					this->lastAnimation = m_animations[key];
				}
			}

			if (m_animations[key]->Play(dt, abs(modifier / modifier_max)))
			{
				this->priorityAnimation = NULL;
			}
		}
	}
	else
	{
		if (priority)
		{
			this->priorityAnimation = m_animations[key];
		}

		if (this->lastAnimation != m_animations[key])
		{
			if (this->lastAnimation == NULL)
				this->lastAnimation = m_animations[key];
			else
			{
				this->lastAnimation->Reset();
				this->lastAnimation = m_animations[key];
			}
		}

		m_animations[key]->Play(dt, abs(modifier / modifier_max));
	}

	return m_animations[key]->isDone();
}
