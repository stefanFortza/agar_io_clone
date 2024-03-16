//
// Created by stefantacu on 13.03.2024.
//

#pragma once
#include <ostream>
#include <SFML/Graphics.hpp>

#include "../SFML_Window.hpp"
#include "GameStateManager.h"


class GameStateManager;
class SFML_Window;

class State {
protected:
	GameStateManager *m_game_state_manager;
	sf::RenderWindow *m_window;

public:
	State(GameStateManager *manager, sf::RenderWindow *window);

	virtual void handleEvent(const sf::Event &event) = 0;

	virtual void render() = 0;

	virtual void update(const sf::Time &deltaTime) = 0;

	friend std::ostream &operator<<(std::ostream &os, const State &/*obj*/) {
		return os << "State" << '\n';
	}

	virtual ~State() = 0;
};

