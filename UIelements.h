#pragma once

#include "Framework/SpriteObject.h"
#include "Framework/AssetManager.h"

class UIelements
{

public:

	UIelements();
	void SetTexture(sf::String _sprite);
	void SetPosition(sf::Vector2f _position);
	void Draw(sf::RenderTarget& _target);


private:

	/*sf::Sprite m_LeftPanel;
	sf::Sprite m_RightPanel;
	sf::Sprite m_WarningRect;*/
	sf::Sprite m_UIelement;

};