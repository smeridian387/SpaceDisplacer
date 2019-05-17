#pragma once

#include "Framework/SpriteObject.h"
#include "Framework/AssetManager.h"
#include "Player.h"

class UIelements
{

public:

	UIelements();
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void SetPlayer(Player* _player);

private:

	sf::Sprite m_LeftPanel;
	sf::Sprite m_RightPanel;
	sf::Sprite m_WarningRect;
	sf::Sprite m_healthBar;
	sf::Sprite m_stars;
	sf::Sprite m_stars1;
	Player* m_player;
	float m_healthBarsize;

};