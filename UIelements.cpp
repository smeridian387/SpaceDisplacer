#include "UIelements.h"
#include "Framework/AssetManager.h"
#include <iostream>

UIelements::UIelements()
	: m_healthBarsize(3.16f)
	, m_player(nullptr)
	, m_scale()
{
		m_LeftPanel.setTexture(AssetManager::GetTexture("graphics/LeftPanel.png"));
		m_LeftPanel.setPosition(0.0f, 0.0f);
		m_LeftPanel.setScale(0.666f, 0.666f);
		m_RightPanel.setTexture(AssetManager::GetTexture("graphics/RightPanel.png"));
		m_RightPanel.setPosition(1080.0f, 0.0f);
		m_RightPanel.scale(0.666f, 0.666f);
		m_WarningRect.setTexture(AssetManager::GetTexture("graphics/WarningRect.png"));
		m_WarningRect.setPosition(11.0f, 420.0f);
		m_WarningRect.setScale(0.26f, 0.4f);
		m_healthBar.setTexture(AssetManager::GetTexture("graphics/healthBar.png"));
		m_healthBar.setPosition(1235.0f, 710.0f);
		m_healthBar.setScale(0.125f, m_healthBarsize);
		m_healthBar.setOrigin(m_healthBar.getTextureRect().width / 2, m_healthBar.getTextureRect().height);
}

void UIelements::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_LeftPanel);
	_target.draw(m_RightPanel);
	_target.draw(m_WarningRect);
	_target.draw(m_healthBar);
}

void UIelements::SetPlayer(Player* _player)
{
	m_player = _player;
}

void UIelements::Update(sf::Time _frameTime)
{
	float currentHealth = m_player->GetHullIntergity();
	if (currentHealth < 100)
	{
		m_scale = (m_healthBarsize * ((currentHealth) / 100));
		m_healthBar.setScale(0.125f, m_scale);
	}
	if (currentHealth > 100)
	{
		m_healthBar.setScale(0.125f, 3.16f);
	}
	
}

