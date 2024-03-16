//
// Created by stefantacu on 13.03.2024.
//

#include "../../headers/game_states/MenuState.hpp"
#include <iostream>
#include "../../headers/game_states/GameState.h"
#include "../../headers/network/Server.h"


MenuState::MenuState(GameStateManager *manager,
                     sf::RenderWindow *window): State(manager, window),
                                                playBtn([this] { play(); }),
                                                hostBtn([this] { host(); }) {
	// font.loadFromFile("assets/roboto/Roboto-Light.ttf");
	font.loadFromFile("assets/roboto/Roboto-Light.ttf");
	playBtn.setFont(font);
	playBtn.setString("Play");
	playBtn.setCharacterSize(50);
	playBtn.setPosition(m_window->getSize().x / 2 - playBtn.getGlobalBounds().width / 2 + 100,
	                    m_window->getSize().y / 2 - playBtn.getGlobalBounds().height / 2);


	hostBtn.setFont(font);
	hostBtn.setString("Host");
	hostBtn.setCharacterSize(50);
	hostBtn.setPosition(m_window->getSize().x / 2 - playBtn.getGlobalBounds().width / 2 - 100,
	                    m_window->getSize().y / 2 - playBtn.getGlobalBounds().height / 2);
}

void MenuState::handleEvent(const sf::Event &event) {
	playBtn.handleEvent(event);
	hostBtn.handleEvent(event);
}

void MenuState::render() {
	m_window->draw(playBtn);
	m_window->draw(hostBtn);
	// window->draw(playBtn);
}

void MenuState::update(const sf::Time &/*deltaTime*/) {
}

void MenuState::host() {
	// m_game_state_manager->setState(std::make_unique<ConnectionState>(manager, window));
	changeState(true);
}

void MenuState::play() {
	changeState(false);
}

void MenuState::changeState(bool isServer) {
	if (isServer)
		std::cout << "host pressed" << '\n';
	else
		std::cout << "pressed" << '\n';

	auto g_state = std::make_unique<GameState>(m_game_state_manager, m_window);
	m_game_state_manager->setNetworkManager(
		std::make_unique<NetworkManager>(m_game_state_manager, isServer, g_state.get()));
	m_game_state_manager->setState(std::move(g_state));
}

MenuState::~MenuState() = default;
