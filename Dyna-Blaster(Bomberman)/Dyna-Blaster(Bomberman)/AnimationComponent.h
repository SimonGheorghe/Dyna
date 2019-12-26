#pragma once
#include <iostream>
#include <string>
#include <map>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class AnimationComponent
{
private:

	class Animation
	{
	public:
		sf::Sprite& m_sprite;
		sf::Texture& m_textureSheet;
		float m_animationTimer;
		float m_timer;
		int m_width;
		int m_height;
		sf::IntRect m_startRect;
		sf::IntRect m_currentRect;
		sf::IntRect m_endRect;

		Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float animationTimer, int startX, int startY, int endX, int endY, int width, int height)
			: m_sprite(sprite), m_textureSheet(textureSheet), m_animationTimer(animationTimer), m_width(width), m_height(height)
		{

			m_startRect = sf::IntRect(startX, startY, width, height);
			m_currentRect = m_startRect;
			m_endRect = sf::IntRect(endX, endY, width, height);
			m_sprite.setTexture(m_textureSheet, true);
			m_sprite.setTextureRect(m_startRect);
		}

		void Update(const float& dt)
		{
			m_timer = 10.f * dt;
			if (m_timer = m_animationTimer)
			{
				m_timer = 0.f;
				if (m_currentRect != m_endRect)
				{
					m_currentRect.left += m_width;
				}
				else
				{
					m_currentRect.left = m_startRect.left;

				}
			}
		}
		void pause();
		void reset();
	};

	sf::Sprite& m_sprite;
	sf::Texture& m_textureSheet;
	std::map<std::string, Animation> m_animation;

public:
	AnimationComponent(sf::Sprite sprite, sf::Texture textureSheet);
	virtual ~AnimationComponent();
	void AddAnimation(const std::string key);
	void StartAnimation(const std::string animation);
	void PauseAnimation(const std::string animation);
	void ResetAnimation(const std::string animation);
	void Update(const float& dt);
};

