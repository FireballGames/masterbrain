#include "GameWindow.h"
#include "settings.hpp"
#include "globals.h"
#include "background.h"

GameWindow::GameWindow(sf::RenderWindow &window): D2Window(window), mp(window)
{
    timer = 0;
}

GameWindow::~GameWindow()
{
    //dtor
}

int GameWindow::load()
{
    delay = 1;

    // Load a sprite to display
    tBackground = loadBackground();
    sBackground = sf::Sprite(tBackground);

    if (!tCardSet.loadFromFile(cardSetFile))
        return EXIT_FAILURE;

    mp.HideSystem();

    // selected = { -1, -1};
    for(int i=0; i<40; i++)
    {
        field[i] = i / 2;
    }

    cardsCount = (level + 1) * 10;
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
}

void GameWindow::show()
{
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    // ----------------------

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

int GameWindow::OnEvent(sf::Event event)
{
    // Close window : exit
    if (event.type == sf::Event::Closed)
        window.close();

    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
    {
        mp.ShowSystem();
        running = false;
        return 1;
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
    return 0;
}
