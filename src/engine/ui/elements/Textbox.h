#pragma once

#include "engine/ui/ISelectable.h"

namespace UI
{
	class Textbox :
		public UIElement, public ISelectable
	{
	private:
		// text data
		std::string _content;
		sf::Text* _text;
		unsigned int _maxCharacters = 20;

		// cursor
		sf::RectangleShape* _cursor;

	public:
		Textbox(GameDataRef data, sf::Vector2f pos, sf::Vector2f size);
		~Textbox();

		// setters
		void setMaxCharacters(unsigned int maxCharacters);

		void handleInput(const sf::Event ev);

		void update(float deltaTime) override;
		void render() const override;

	};
}
