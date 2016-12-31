#include <SFML/Graphics.hpp>
#include <time.h>
#include "settings.hpp"
#include "D2Window.h"
#include "win/MenuWindow.h"
#include "win/GameWindow.h"
#include "win/CardsWindow.h"
#include "background.h"
#include "globals.h"

bool isCollide(sf::Sprite s1, sf::Sprite s2)
{
    return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

int gameWindow(sf::RenderWindow &window, int players)
{
    GameWindow win(window);
    win.load();

	// Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            int action = win.OnEvent(event);
            if (action == 1)
            {
                win.mp.ShowSystem();
                return EXIT_SUCCESS;
            }
        }
        win.show();
    }

    win.mp.ShowSystem();
    return EXIT_SUCCESS;
}

int showCards(sf::RenderWindow &window)
{
    CardsWindow win(window);
    win.load();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            int action = win.OnEvent(event);
            if (action == 1)
            {
                return EXIT_SUCCESS;
            }
        }

        win.show();
    }

    return EXIT_SUCCESS;
}

int mainMenu(sf::RenderWindow &window)
{
    MenuWindow win(window);
    win.load();

	// Start the game loop
    while (win.window.isOpen())
    {
        // Process events
        sf::Event event;
        while (win.window.pollEvent(event))
        {
            int action = win.OnEvent(event);
            if (action == 1)
            {
                gameWindow(win.window, 1);
            }
            else if(action == 2)
            {
                gameWindow(win.window, 2);
            }
            else if(action == 3)
            {
                showCards(win.window);
            }
        }

        win.show();
    }

    return EXIT_SUCCESS;
}

int main()
{
    srand(time(0));

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(winSize[0], winSize[1]), gameTitle);

    int res = mainMenu(app);
    if(res != EXIT_SUCCESS)
        return res;

    return EXIT_SUCCESS;
}
