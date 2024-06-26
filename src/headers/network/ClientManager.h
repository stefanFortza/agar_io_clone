//
// Created by stefantacu on 15.03.2024.
//

#ifndef CLIENT_H
#define CLIENT_H

#include "ServerManager.h"
#include "SFML/Network/Packet.hpp"
#include "OnlinePlayerData.h"
#include "../utils/Signal.h"


class GameState;

class ClientManager {
    sf::UdpSocket m_socket;
    sf::Packet m_packet;
    std::map<std::string, OnlinePlayerData> m_online_players;
    std::string m_client_id;
    bool m_is_running;

public:
    Signal<const std::map<std::string, OnlinePlayerData> &> onJoinedLobby;
    Signal<const OnlinePlayerData &> onPlayerJoinedLobby;
    Signal<const std::map<std::string, OnlinePlayerData> &> onGameStarted;
    Signal<const OnlinePlayerData &> onPlayerDataReceived;
    Signal<sf::Vector2f> onFoodSpawned;
    Signal<const OnlinePlayerData &, int> onFoodEaten;
    Signal<const OnlinePlayerData &, const OnlinePlayerData &> onPlayerEaten;
    Signal<const std::string &> onPlayerDisconnected;


    std::string getClientId();

    void disconnect();

    void sendLocalDataToServer(OnlinePlayerData data);

    static ClientManager &getInstance();

    bool isRunning() const;

    void handlePlayerJoinedLobby(sf::Packet &packet);

    void handleJoinedLobby(sf::Packet &packet);

    void start(std::string name);

    void handleGameStarted();

    void handleFoodSpawned(sf::Vector2f pos);

    void handleFoodEaten(OnlinePlayerData data, int id);

    void handlePlayerEaten(const OnlinePlayerData &player1, const OnlinePlayerData &player2);

    void handlePlayerDisconnected(const std::string &id);

    void receiveData();

    void sendData();

    void sendPacketToServer(sf::Packet &packet);

private:
    ClientManager();
};


#endif //CLIENT_H
