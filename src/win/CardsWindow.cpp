#include "CardsWindow.h"
#include "settings.hpp"
#include "globals.h"
#include "background.h"

CardsWindow::CardsWindow(sf::RenderWindow &window): D2Window(window)
{
    //ctor
}

CardsWindow::~CardsWindow()
{
    //dtor
}

int CardsWindow::load()
{
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
}

void CardsWindow::show()
{
    window.display();
}

int CardsWindow::OnEvent(sf::Event event)
{
    if (event.type == sf::Event::Closed)
        window.close();
    if ((event.type == sf::Event::KeyPressed) || (event.type == sf::Event::MouseButtonPressed))
    {
        window.setMouseCursorVisible(true);
        return 1;
    }

    return 0;
}
