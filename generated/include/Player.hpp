#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "Game.hpp"

class Player : public Entity {
public:
    explicit Player(GameStateManager *manager, sf::RenderWindow *window);

    ~Player();

    // const sf::View &GetView() const;

private:
    sf::CircleShape m_player_shape;
    sf::Vector2f dir;
    sf::View m_view;
    sf::RenderWindow *m_window;
    float m_speed = 200;

    void handleEventCurrent(const sf::Event &event) override;

    void updateCurrent(const sf::Time &delta) override;

    void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif
