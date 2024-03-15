//
// Created by stefantacu on 07.03.2024.
//
#include <Game.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_states/MenuState.hpp"

Game::Game() : m_game_state_manager(new GameStateManager()),
               m_window(sf::VideoMode(1280, 720), "Agar.io") {
	// m_window("Chapter 2", sf::Vector2u(1280, 720)) {
	m_window.setFramerateLimit(60);
	m_game_state_manager->setState(std::make_unique<MenuState>(m_game_state_manager, &m_window));
};

Game::~Game() = default;

void Game::handleEvent(const sf::Event &event) const {
	m_game_state_manager->handleEvent(event);
}

void Game::handleInput() {
}

void Game::update() {
	// m_window.update(); // Update window events.

	m_game_state_manager->update(m_elapsed);
}

void Game::render() {
	// m_window.clear();
	// m_window.beginDraw(); // Clear.
	//
	// m_game_state_manager->render();
	//
	// m_window.endDraw(); // Display.
	// m_window.display();
}

// SFML_Window *Game::getWindow() {
// 	// return &m_window;
// }

// bool Game::isWindowOpen() const {
//     return m_window.isOpen();
// }

sf::Time Game::getElapsed() const { return m_elapsed; }

void Game::restartClock() { m_elapsed = m_clock.restart(); }

void Game::start() {
	while (m_window.isOpen()) {
		sf::Event event{};
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				m_window.close();

			m_game_state_manager->handleEvent(event);
		}

		m_window.clear(sf::Color::White);
		m_game_state_manager->update(m_elapsed);
		m_game_state_manager->render();
		m_window.display();
		restartClock();
	}
}

