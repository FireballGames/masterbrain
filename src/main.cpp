#include <SFML/Graphics.hpp>
#include <time.h>
#include "settings.hpp"
#include "D2Window.h"
#include "win/MenuWindow.h"
#include "win/GameWindow.h"
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
    // D2Window CardsWin(window);

    sf::Texture tBackground = loadBackground();
    sf::Sprite sBackground(tBackground);

    sf::Texture tCardSet;
    if (!tCardSet.loadFromFile(cardSetFile))
        return EXIT_FAILURE;
    sf::Sprite sCard[40];

    int field[40];
    int selected[2] = { -1, -1};
    for(int i=0; i<40; i++)
    {
        field[i] = i / 2;
    }

    // Clear screen
    window.clear();

    // Draw the sprite
    window.draw(sBackground);

    int cardsCount = (level + 1) * 10;
    int columns = cardsCount / 5;
    for(int i=0; i<cardsCount; i++)
    {
        sCard[i].setTexture(tCardSet);
        sCard[i].setPosition((i % columns) * 36 + 4 + boxPos[0], (i / columns) * 36 + 4 + boxPos[1]);
        sCard[i].setTextureRect(sf::IntRect((i / 2) * 32, cardSetId * 32, 32, 32));
        window.draw(sCard[i]);
    }

	// Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
            if ((event.type == sf::Event::KeyPressed) || (event.type == sf::Event::MouseButtonPressed))
            {
                window.setMouseCursorVisible(true);
                return EXIT_SUCCESS;
            }
        }

        // Clear screen
        // window.clear();

        // Draw the sprite
        // window.draw(sBackground);

        // for(int i=0; i<cardsCount; i++)
        // {
        //    window.draw(sCard[i]);
        // }

        // Update the window
        window.display();
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
