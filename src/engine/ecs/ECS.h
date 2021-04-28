#pragma once

#include <bitset>
#include <array>

#include <SFML/Graphics.hpp>

namespace Engine
{
	class Entity; // entity class include (solution for double include)

	class Component
	{
	protected:
		Entity* _entity; // entity, component is relied to

	public:
		Component(Entity* e) : _entity(e) {  }
		virtual ~Component() {  }

		// basic functions
		virtual void update(float deltaTime) {  }
		virtual void render(sf::RenderTarget& target) const {  }

		friend class Entity;
	};

	constexpr std::size_t maxComponents = 32;

	using ComponentID = std::size_t;
	using ComponentBetset = std::bitset<maxComponents>;
	using ComponentArray = std::array<Component*, maxComponents>;

	inline ComponentID getComponentTypeID()
	{
		static ComponentID lastID = 0;
		return lastID++;
	}

	template<class T>
	inline ComponentID getComponentTypeID() noexcept
	{
		static ComponentID typeID = getComponentTypeID();
		return typeID;
	}

}
