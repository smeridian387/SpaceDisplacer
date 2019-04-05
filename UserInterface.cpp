#include "UserInterface.h"
#include "Framework/SpriteObject.h"


UserInterface::UserInterface()
	:m_active(true)
	, m_UIvector()
{
	//m_sprite.setTexture(AssetManager::GetTexture("graphics/GradedUnitUI.png"));
	//m_sprite.setPosition(sf::Vector2f(0, 0));
	//m_sprite.setScale(0.666, 0.666f);
	m_UIvector.push_back(UIelements());
	m_UIvector.push_back(UIelements());
	m_UIvector.push_back(UIelements());
}

void UserInterface::SetUI(UIelements* _m_UI)
{
	m_UIelements = _m_UI;
}

void UserInterface::Draw(sf::RenderTarget& _target)
{
	m_UIelements[0].SetTexture("graphics/LeftPanel");
	m_UIelements[0].SetPosition(sf::Vector2f(1.0f,1.0f));
	for (int i = 0; i < m_UIvector.size(); i++)
	{
		m_UIvector[i].Draw(_target);

	}
}

