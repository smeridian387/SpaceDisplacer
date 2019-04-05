#pragma once

#include "Framework/SpriteObject.h"
#include "UIelements.h"

class UserInterface : public SpriteObject
{
	
public:

	UserInterface();

	//functions
	void SetUI(UIelements* _m_UI);
	void Draw(sf::RenderTarget& _target);

private:

	bool m_active;
	UIelements* m_UIelements;
	std::vector< UIelements > m_UIvector;
	

};