#pragma once

#include "Framework/GameObject.h"
#include "Framework/TextObject.h"
#include "Framework/AnimationSystem.h"
#include "Framework/Animation.h"

class SpaceDisplacer
{

public:

	SpaceDisplacer();

	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	bool SDActive();



private:

	int m_temp;
	int m_SDcasing;
	bool m_SDactive;
	bool m_SDfunctional;
	bool m_timer;
	bool m_timer2;
	int m_preCurrentTime;
	int m_SDcolorchange;
	sf::Text m_text;
	sf::Sprite m_sprite;
	AnimationSystem m_animation;
	Animation& m_idleSD;


};
