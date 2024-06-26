//
// Created by stefantacu on 15.03.2024.
//
#pragma once
#include <ostream>

#include "../network/ServerManager.h"
#include "SFML/Network/Packet.hpp"
#include "SFML/System/Vector2.hpp"

template<class T>
std::ostream &operator<<(std::ostream &os, const sf::Vector2<T> &vector) {
    os << "(" << vector.x << ", " << vector.y << ")";
    return os;
}


template<class T>
sf::Packet &operator<<(sf::Packet &packet, const sf::Vector2<T> &vector) {
    packet << vector.x << vector.y;
    return packet;
}

template<class T>
sf::Packet &operator>>(sf::Packet &packet, sf::Vector2<T> &vector) {
    packet >> vector.x >> vector.y;
    return packet;
}


namespace NetworkUtils {
    std::string getIdFromAdressAndPort(sf::IpAddress sender, unsigned short port);

    sf::IpAddress getAdressFromId(const std::string &id);

    sf::Uint32 getPortFromId(const std::string &id);
}
