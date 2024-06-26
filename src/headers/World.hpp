#ifndef WORLD_HPP
#define WORLD_HPP
#include <SFML/Graphics.hpp>
#include "SceneNode.hpp"
#include "player/Player.hpp"
#include "PlayerCamera.hpp"
#include "player/RemotePlayer.h"
#include "network/ServerManager.h"


class World : public SceneNode {
    // public:
    //     explicit World(GameStateManager *manager, sf::RenderWindow *window);
    //
    //     void handlePlayerJoined(std::string &id);
    //
    //     void handlePlayerPosition(std::string &id, sf::Vector2f vector2);
    //
    //     void handleConnectedToServer(std::map<std::string, std::unique_ptr<OnlinePlayerData> > &map);
    //
    //     void handlePlayerDisconected(const std::string &id);
    //
    //     void setPlayers(const std::map<std::string, OnlinePlayerData> &players_data);
    //
    // private:
    //     Player *m_player;
    //     std::map<std::string, RemotePlayer *> m_remote_players;
    //     PlayerCamera *m_player_camera;
    //     float m_grid_spacing = 100.f;
    //     sf::Vector2u m_windowSize;
    //     sf::Vector2i m_world_size;
    //     sf::CircleShape m_appleShape;
    //     sf::RectangleShape m_vertical_grid[100];
    //     sf::RectangleShape m_horizontal_grid[100];
    //     sf::Color m_grid_color;
    //     sf::RectangleShape m_origin;
    //
    //     void updateCurrent(const sf::Time &delta) override;
    //
    //     void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;
    //
    //     void handleEventCurrent(const sf::Event &event) override;
    //
    //     void setOnlinePlayersData();
    //
    //     void initializeGrid();
};

#endif
