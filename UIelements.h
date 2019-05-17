#pragma once

#include "Framework/SpriteObject.h"
#include "Framework/AssetManager.h"
#include "Player.h"
#include "MovingObject.h"
#include "SpaceDisplacer.h"

class UIelements : MovingObject
{

public:

	UIelements();
	void SetSpaceDisplacer(SpaceDisplacer* _SD);
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void SetPlayer(Player* _player);

private:

	sf::Sprite m_LeftPanel;
	sf::Sprite m_RightPanel;
	sf::Sprite m_WarningRect;
	sf::Sprite m_healthBar;
	sf::Sprite m_starsn;
	sf::Sprite m_starsn2;
	sf::Sprite m_starsf;
	sf::Sprite m_starsf2;
	Player* m_player;
	SpaceDisplacer* m_SD;
	float m_healthBarsize;

};