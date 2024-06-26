//
// Created by stefantacu on 14.03.2024.
//

#pragma once
#include "State.hpp"
#include "../Command.h"
#include "../Grid.hpp"
// #include "../World.hpp"
#include "../PlayerCamera.hpp"
#include "../entities/FoodManager.h"
#include "../player/PlayersManager.h"
#include "../ui/LeaderBoards.h"


class PlayersManager;

class GameState :
		public State {
protected:
	std::unique_ptr<PlayersManager> m_players_manager;
	Grid m_grid;
	PlayerCamera m_player_camera;
	FoodManager m_food_manager;
	LeaderBoards m_leaderboards;
	const std::map<std::string, OnlinePlayerData> &players_data;
	bool gameEnd = false;

public:
	GameState(GameStateManager *manager, sf::RenderWindow *window,
	          const std::map<std::string, OnlinePlayerData> &players_data);

	void handleEvent(const sf::Event &event) override;

	void update(const sf::Time &deltaTime) override;

	void render() override;

	~GameState();
};



