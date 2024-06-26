//
// Created by stefantacu on 20.03.2024.
//

#ifndef SERVERLOBBYSTATE_H
#define SERVERLOBBYSTATE_H
#include "LobbyState.h"
#include "../Grid.hpp"
#include "../ui/Button.h"
#include "../ui/Label.h"
#include "../network/OnlinePlayerData.h"


class LobbyPlayerLabels;

class ServerLobbyState : public LobbyState {
private:
    std::unique_ptr<Label> m_lobby_label;
    std::vector<std::unique_ptr<Label> > player_labels;
    std::unique_ptr<LobbyPlayerLabels> m_player_labels;
    std::unique_ptr<Button> m_start_game_button;
    Grid m_grid;


    void onPlayerJoinedLobby(const OnlinePlayerData &player);

    void onStartButtonPressed();

    void onGameStarted(const std::map<std::string, OnlinePlayerData> &player_data);

public:
    ServerLobbyState(GameStateManager *manager,
                     sf::RenderWindow *window, std::string name);


    void handleEvent(const sf::Event &event) override;

    void render() override;

    void update(const sf::Time &deltaTime) override;
};


#endif //SERVERLOBBYSTATE_H
