#pragma once

#include "engine/ui/elements/UIElement.h"

class InputManager
{
public:
	static sf::Vector2i getMousePosition(const sf::Window& window);
	static sf::Vector2i getMousePosition();

	static bool isMouseButtonPressed(sf::Mouse::Button button);
	static bool isElementHovered(UI::UIElement* element, const sf::Window& window);
	static bool isElementPressed(UI::UIElement* element, const sf::Window& window, sf::Mouse::Button button);

	static bool isSpriteHovered(const sf::Sprite* sprite, const sf::Window& window);
};
