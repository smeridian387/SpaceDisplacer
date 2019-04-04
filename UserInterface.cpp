#include "UserInterface.h"
#include "Framework/AssetManager.h"
#include "Framework/SpriteObject.h"


UserInterface::UserInterface()
	:m_active(true)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/GradedUnitUI.png"));
	m_sprite.setPosition(sf::Vector2f(0, 0));
	m_sprite.setScale(0.666, 0.666f);
	
}

