#include "DebugInfo.h"

#include "engine/ecs/components/PositionComponent.h"

namespace Engine
{
	DebugInfo::DebugInfo(GameDataRef data, DebugData debugData)
		:UIElement(data, {}, {}), _debugData(debugData), _active(false)
	{
		// quick acess variables
		auto& entity_pos = this->_debugData._trackEntity.getComponent<PositionComponent>();

		// adding data to _texts
		this->_texts["FPS"] = new sf::Text(
			"FPS: " + std::to_string((int)_data->winConfig.fps),
			_data->assets.GetFont("menu font"), 24
		);
		this->_texts["FPS"]->setPosition(5.f, float((_texts.size() - 1) * 28));

		this->_texts["TILES"] = new sf::Text(
			"Tiles rendered: " + std::to_string(_debugData._map.tilesRendered()),
			_data->assets.GetFont("menu font"), 24
		);
		this->_texts["TILES"]->setPosition(5.f, float((_texts.size() - 1) * 28));

		// global position
		this->_texts["POSITION_GLOBAL"] = new sf::Text(
			"Global position (X:Y): " + std::to_string((int)entity_pos.getX())
				+ ":"
				+ std::to_string((int)entity_pos.getY()),
			_data->assets.GetFont("menu font"), 24
		);
		this->_texts["POSITION_GLOBAL"]->setPosition(5.f, float((_texts.size() - 1) * 28));

		// grid position
		this->_texts["POSITION_GRID"] = new sf::Text(
			"Grid position (X:Y): " + std::to_string(entity_pos.getGridPosition().x)
			+ ":"
			+ std::to_string(entity_pos.getGridPosition().y),
			_data->assets.GetFont("menu font"), 24
		);
		this->_texts["POSITION_GRID"]->setPosition(5.f, float((_texts.size() - 1) * 28));
	}

	DebugInfo::~DebugInfo()
	{ }

	bool DebugInfo::isActive() const
	{
		return this->_active;
	}

	void DebugInfo::setActive(bool value)
	{
		this->_active = value;
	}

	void DebugInfo::update(float deltaTime)
	{
		// quick acess variables
		auto& entity_pos = this->_debugData._trackEntity.getComponent<PositionComponent>();

		// updating texts data
		this->_texts["FPS"]->setString("FPS: " + std::to_string((int)_data->winConfig.fps));
		this->_texts["TILES"]->setString("Tiles rendered: " + std::to_string(_debugData._map.tilesRendered()));
		this->_texts["POSITION_GLOBAL"]->setString(
			"Global position (X:Y): " + std::to_string((int)entity_pos.getX())
				+ ":"
				+ std::to_string((int)entity_pos.getY())
		);

		this->_texts["POSITION_GRID"]->setString(
			"Grid position (X:Y): " + std::to_string(entity_pos.getGridPosition().x)
			+ ":"
			+ std::to_string(entity_pos.getGridPosition().y)
		);
	}

	void DebugInfo::render() const
	{
		for (const auto& [name, t] : _texts)
			this->_data->window.draw(*t);
	}
}
