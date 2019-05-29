#pragma once

#include "Framework/GameObject.h"
#include "Framework/TextObject.h"
#include "Framework/AnimationSystem.h"
#include "Framework/Animation.h"

class SpaceDisplacer
{

public:

	SpaceDisplacer();

	void Draw(sf::RenderTarget& _target);//main passes in the render target
	void Update(sf::Time _frameTime);//main passes in the frameTime
	void SetSDTemp(int _newTemp);//setter for the space displacers temperature
	void LNWarningMove();//setter for the warning bars position
	bool SDActive();//getter for wheather or not the space disaplcer is active
	bool IsActive();//getter for wheather or not the space disaplcer object is active
	void IsMainMenuActive(bool _mainmenu);//main passing wheather or not the mainmenu is active

private:

	int m_temp;
	bool m_active;
	int m_SDcasing;
	bool m_SDactive;
	bool m_SDfunctional;
	bool m_overHeating;
	int m_SDcolorchange;
	float m_warnRectIn;
	float m_LNPickUp;
	sf::Text m_SDtempText;
	sf::Text m_SDcasingText;
	sf::Sprite m_sprite;
	sf::Sprite m_warningRect;
	sf::Sprite m_lightFilter;
	sf::Sprite m_lights;
	AnimationSystem m_animation;
	Animation& m_idleSD;
	int m_millisecondsSinceSpacePressed;
	bool m_mainmenuActive;
	//timer variables
	bool m_timer;
	bool m_timer2;
	bool m_timer3;
	bool m_timer4;
	int m_preCurrentTime;
	int m_preCurrentTime2;
	int m_preCurrentTime3;
};
