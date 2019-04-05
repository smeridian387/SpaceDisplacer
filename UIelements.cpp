#include "UIelements.h"
#include "Framework/AssetManager.h"

UIelements::UIelements()
	:m_UIelement()
{
	m_UIelement.setTexture(AssetManager::GetTexture(""));
}

void UIelements::SetTexture(sf::String _sprite)
{
	m_UIelement.setTexture(AssetManager::GetTexture(_sprite));
}

void UIelements::SetPosition(sf::Vector2f _position)
{
	m_UIelement.setPosition(_position);
}

void UIelements::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_UIelement);
}

