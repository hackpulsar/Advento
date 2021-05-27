#pragma once

#include "Game.h"
#include "State.h"

#include "engine/ui/elements/Textbox.h"
#include "engine/ui/elements/Button.h"

// State for choosing world generation settings
class GenerationState :
    public State
{
private:
    GameDataRef _data;

    // background
    sf::Sprite* _background;

    // ui elements
    std::map<std::string, UI::Textbox*> _textboxes; // textboxes
    std::map<std::string, UI::Button*> _buttons; // buttons
    std::map<std::string, sf::Text*> _titles; // titles

    std::string getRandomSeed(unsigned int count) const;

public:
    GenerationState(GameDataRef data);
    ~GenerationState();

    void Init() override;
    
    void HandleInput() override;

    // basic functions
    void Update(float deltaTime) override;
    void Render() const override;

};
