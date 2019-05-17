#include "UIelements.h"
#include "Framework/AssetManager.h"
#include <iostream>

UIelements::UIelements()
	: m_healthBarsize(3.16f)
	, m_player(nullptr)
	, m_SD(nullptr)
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

		m_starsn.setTexture(AssetManager::GetTexture("graphics/starsa.png"));
		m_starsn.setPosition(200.0f, 0.0f);
		m_starsn.setScale(3.3f,3.3f);

		m_starsn2.setTexture(AssetManager::GetTexture("graphics/starsa.png"));
		m_starsn2.setPosition(200.0f, -720.0f);
		m_starsn2.setScale(3.3f, 3.3f);

		m_starsf.setTexture(AssetManager::GetTexture("graphics/stars2.png"));
		m_starsf.setPosition(200.0f, 0.0f);
		m_starsf.setScale(1.6f, 1.6f);

		m_starsf2.setTexture(AssetManager::GetTexture("graphics/stars2.png"));
		m_starsf2.setPosition(200.0f, -720.0f);
		m_starsf2.setScale(1.6f, 1.6f);
}

void UIelements::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_starsn);
	_target.draw(m_starsf);
	_target.draw(m_starsn2);
	_target.draw(m_starsf2);
	_target.draw(m_LeftPanel);
	_target.draw(m_RightPanel);
	_target.draw(m_WarningRect);
	_target.draw(m_healthBar);
}

void UIelements::SetPlayer(Player* _player)
{
	m_player = _player;
}

void UIelements::SetSpaceDisplacer(SpaceDisplacer* _SD)
{
	m_SD = _SD;
}

void UIelements::Update(sf::Time _frameTime)
{
	bool m_SDactive = m_SD->SDActive();
	if (m_SDactive == false)
	{
		m_starsn.move(0.0f, 0.03f);
		m_starsn2.move(0.0f, 0.03f);
		m_starsf.move(0.0f, 0.01f);
		m_starsf2.move(0.0f, 0.01f);
	}
	if (m_starsn.getPosition().y > 750)
	{
		m_starsn.setPosition(200.0f, -720.0);
	}
	if (m_starsn2.getPosition().y > 750)
	{
		m_starsn2.setPosition(200.0f, -720.0);
	}
	if (m_starsf.getPosition().y > 750)
	{
		m_starsf.setPosition(200.0f, -720.0);
	}
	if (m_starsf2.getPosition().y > 750)
	{
		m_starsf2.setPosition(200.0f, -720.0);
	}
	float currentHealth = m_player->GetHullIntergity();
	if (currentHealth < 100)
	{
		float m_scale;
		m_scale = (m_healthBarsize * ((currentHealth) / 100));
		m_healthBar.setScale(0.125f, m_scale);
	}
	if (currentHealth > 100)
	{
		m_healthBar.setScale(0.125f, 3.16f);
	}
	MovingObject::Update(_frameTime);
}

