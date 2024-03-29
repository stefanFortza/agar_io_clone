#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>

#include "GameContext.hpp"
#include "SFML_Window.hpp"
#include "World.hpp"

class Game {
public:
    Game();

    ~Game();

    void HandleInput();

    void Update();

    void Render();

    SFML_Window *GetWindow();

    sf::Time GetElapsed() const;

    void RestartClock();

private:
    GameContext m_context;
    SFML_Window m_window;
    sf::RenderStates m_states;
    // add UI
    World m_world;
    sf::Clock m_clock;
    sf::Time m_elapsed;
};
#endif // GAME_HPP
