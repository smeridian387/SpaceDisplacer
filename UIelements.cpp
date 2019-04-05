#include "UIelements.h"
#include "Framework/AssetManager.h"

UIelements::UIelements()
{
	m_LeftPanel.setTexture(AssetManager::GetTexture("graphics/LeftPanel.png"));
	m_LeftPanel.setPosition(0.0f, 0.0f);
	m_LeftPanel.setScale(0.666f, 0.666f);
	m_RightPanel.setTexture(AssetManager::GetTexture("graphics/RightPanel.png"));
	m_RightPanel.setPosition(1080.0f, 0.0f);
	m_RightPanel.scale(0.666f, 0.666f);
	m_WarningRect.setTexture(AssetManager::GetTexture("graphics/WarningRect.png"));
	m_WarningRect.setPosition(15.0f, 420.0f);
	m_WarningRect.setScale(0.5f, 0.5f);

}

void UIelements::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_LeftPanel);
	_target.draw(m_RightPanel);
	_target.draw(m_WarningRect);

}

