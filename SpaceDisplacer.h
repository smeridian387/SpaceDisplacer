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
	void SetSDTemp(int _newTemp);
	void SetSDcasing(int _repair);
	bool SDActive();
	bool IsActive();



private:

	int m_temp;
	bool m_active;
	int m_SDcasing;
	bool m_SDactive;
	bool m_SDfunctional;
	bool m_timer;
	bool m_timer2;
	int m_preCurrentTime;
	int m_SDcolorchange;
	float m_warnRectIn;
	sf::Text m_SDtempText;
	sf::Text m_SDcasingText;
	sf::Sprite m_sprite;
	sf::Sprite m_warningRect;
	AnimationSystem m_animation;
	Animation& m_idleSD;


};
