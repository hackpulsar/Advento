#include "Tile.h"

#include "engine/defenitions/BASIC_WORLD_SETTINGS.h"

namespace Engine
{
	Tile::Tile(const sf::Texture& texture, sf::Vector2f pos)
		:_spr(new sf::Sprite(texture))
	{
		this->_spr->setPosition(pos);
	}

	Tile::~Tile()
	{
		delete this->_spr;
	}

	void Tile::update(float deltaTime)
	{
	}

	void Tile::render(sf::RenderTarget& target)
	{
		target.draw(*this->_spr);
	}

	bool Tile::isInBounds(const sf::FloatRect bounds)
	{
		return bounds.intersects(this->_spr->getGlobalBounds());
	}
}
