#pragma once

#include "engine/ecs/Entity.h"

#include "engine/ecs/components/PositionComponent.h"
#include "engine/ecs/components/SpriteComponent.h"
#include "engine/ecs/components/MovementComponent.h"
#include "engine/ecs/components/AnimationComponent.h"
#include "engine/ecs/components/HitboxComponent.h"

#define PLAYER_HITBOX_SIZE_X 64.f
#define PLAYER_HITBOX_SIZE_Y 128.f

class Player
	: public Engine::Entity
{
public:
	Player(GameDataRef data, sf::Vector2f pos);
	~Player();

	void update(float deltaTime) override;
	void render() const override;

};
