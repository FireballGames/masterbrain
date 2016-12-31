#include <SFML/Graphics.hpp>
#include <time.h>
#include "settings.hpp"
#include "MousePointer.h"
#include "D2Window.h"
#include "win/MenuWindow.h"
#include "background.h"
#include "globals.h"

bool isCollide(sf::Sprite s1, sf::Sprite s2)
{
    return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

int gameWindow(sf::RenderWindow &window, int players)
{
    // D2Window GameWin(window);

    float timer = 0;
    float delay = 1;
    sf::Clock clock;

    // Load a sprite to display
    sf::Texture tBackground = loadBackground();
    sf::Sprite sBackground(tBackground);

    sf::Texture tCardSet;
    if (!tCardSet.loadFromFile(cardSetFile))
        return EXIT_FAILURE;
    sf::Sprite sCard[40];

    MousePointer mp(window);
    mp.HideSystem();

    int field[40];
    int selected[2] = { -1, -1};
    for(int i=0; i<40; i++)
    {
        field[i] = i / 2;
    }

    int cardsCount = (level + 1) * 10;
    int columns = cardsCount / 5;
    for(int i=0; i<cardsCount; i++)
    {
        std::swap(field[i], field[rand() % cardsCount]);
    }

    for(int i=0; i<cardsCount; i++)
    {
        sCard[i].setTexture(tCardSet);
        sCard[i].setPosition((i % columns) * 36 + 4 + boxPos[0], (i / columns) * 36 + 4 + boxPos[1]);
        sCard[i].setTextureRect(sf::IntRect(20 * 32, cardSetId * 32, 32, 32));
    }

	// Start the game loop
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                mp.ShowSystem();
                return EXIT_SUCCESS;
            }
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        for(int i=0; i<cardsCount; i++)
                        {
                            if(sCard[i].getGlobalBounds().contains(mp.getMousePos()))
                                if (selected[0] < 0)
                                {
                                    selected[0] = i;
                                }
                                else
                                {
                                    if((selected[1] < 0) && (selected[0] != i))
                                    {
                                        selected[1] = i;
                                        timer = 0;
                                    }
                                    else
                                    {
                                        timer = delay + 1;
                                    }
                                }
                        }
                    }
        }

        if(timer > delay)
        {
            if(selected[1] >= 0)
            {
                if(field[selected[0]] == field[selected[1]])
                {
                    sCard[selected[0]].setPosition(-32, -32);
                    sCard[selected[1]].setPosition(-32, -32);
                    field[selected[0]] = -1;
                    field[selected[1]] = -1;
                }
                else
                {
                    sCard[selected[0]].setTextureRect(sf::IntRect(20 * 32, cardSetId * 32, 32, 32));
                    sCard[selected[1]].setTextureRect(sf::IntRect(20 * 32, cardSetId * 32, 32, 32));
                }
                selected[0] = -1;
                selected[1] = -1;
            }

            timer = 0;
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sBackground);

        for(int i=0; i<cardsCount; i++)
        {
            if((selected[0] == i) || (selected[1] == i))
                sCard[i].setTextureRect(sf::IntRect(field[i] * 32, cardSetId * 32, 32, 32));
            window.draw(sCard[i]);
        }

        mp.DrawCursor();

        // Update the window
        window.display();
    }

    mp.ShowSystem();

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
