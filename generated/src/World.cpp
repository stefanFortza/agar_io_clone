//
// Created by stefantacu on 07.03.2024.
//
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <World.hpp>

World::World(GameContext &context) : SceneNode(context), m_player(nullptr),
                                     m_player_camera(nullptr),
                                     m_world_size(50000, 50000),
                                     m_grid_color(220, 220, 220, 255),
                                     m_origin(sf::Vector2f(60.f, 60.f)) {
    // Set children
    std::unique_ptr<Player> player(new Player(context));
    m_player = player.get();
    this->attachChild(std::move(player));


    std::unique_ptr<PlayerCamera> player_camera(new PlayerCamera(context));
    m_player_camera = player_camera.get();
    this->attachChild(std::move(player_camera));
    this->m_player_camera->setTarget(m_player);

    this->m_origin.setOrigin(sf::Vector2f(30.f, 30.f));
    this->m_origin.setFillColor(sf::Color::Red);

    initializeGrid();
};


void World::updateCurrent(sf::Time delta) {
}

void World::drawCurrent(sf::RenderTarget &target, const sf::RenderStates states) const {
    // TODO Here draw UI
    sf::CircleShape shape(100, 100);
    shape.setFillColor(sf::Color::Black);
    auto win = m_context.getSFMLWindow();

    target.setView(win->GetRenderWindow().getDefaultView());
    target.draw(shape);
    target.setView(m_player_camera->getView());


    for (const auto &i: this->m_vertical_grid) {
        target.draw(i, states);
    }

    for (const auto &i: this->m_horizontal_grid) {
        target.draw(i, states);
    }

    // std::cout << states.transform.getMatrix();

    target.draw(m_origin, states);
}

sf::View &World::getNodeView() {
    return m_player_camera->getView();
}

void World::initializeGrid() {
    // initialize grid

    // vertical
    for (size_t i = 0; i < 100; i++) {
        this->m_vertical_grid[i].setSize(sf::Vector2f(1.5f, 2000.f));
        this->m_vertical_grid[i].setFillColor(this->m_grid_color);
        this->m_vertical_grid[i].setPosition(sf::Vector2f(m_grid_spacing * i, -500.f));
    }

    // horizontal
    for (size_t i = 0; i < 100; i++) {
        sf::Color color(220, 220, 220, 255);
        this->m_horizontal_grid[i].setSize(sf::Vector2f(1.5f, 2000.f));
        this->m_horizontal_grid[i].setFillColor(this->m_grid_color);
        this->m_horizontal_grid[i].setPosition(sf::Vector2f(1000.f, m_grid_spacing * i));
        this->m_horizontal_grid[i].setRotation(90.f);
    }
}
