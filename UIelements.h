#pragma once

#include "Framework/SpriteObject.h"
#include "Framework/AssetManager.h"

class UIelements
{

public:

	UIelements();
	void Draw(sf::RenderTarget& _target);


private:

	sf::Sprite m_LeftPanel;
	sf::Sprite m_RightPanel;
	sf::Sprite m_WarningRect;

};