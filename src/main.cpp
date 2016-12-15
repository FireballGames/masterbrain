#include <SFML/Graphics.hpp>
#include <time.h>
#include "settings.hpp"
#include "MousePointer.h"

bool isCollide(sf::Sprite s1, sf::Sprite s2)
{
    return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

sf::String backgroundFile()
{
    int backgroundId = rand() % backgroundsCount;

    return backgrounds[backgroundId];
}

sf::Texture loadBackground()
{
    sf::Texture tBackground;
    tBackground.loadFromFile(backgroundFile());

    return tBackground;
}

sf::Vector2f getMousePos(sf::RenderWindow &window)
{
    return static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
}

int gameWindow(sf::RenderWindow &window, int players)
{
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

    MousePointer mp;
    mp.LoadSprite();
    mp.HideSystem(window);

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
                mp.ShowSystem(window);
                return EXIT_SUCCESS;
            }
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        for(int i=0; i<cardsCount; i++)
                        {
                            if(sCard[i].getGlobalBounds().contains(getMousePos(window)))
                                if (selected[0] < 0)
                                {
                                    selected[0] = i;
                                }
                                else
                                {
                                    if(selected[1] < 0)
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

        mp.DrawCursor(window);

        // Update the window
        window.display();
    }

    mp.ShowSystem(window);

    return EXIT_SUCCESS;
}

int showCards(sf::RenderWindow &window)
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
    sf::Texture tLogoTitle;
    if (!tLogoTitle.loadFromFile(logoTitle))
        return EXIT_FAILURE;
    sf::Sprite sLogoTitle(tLogoTitle);
    sLogoTitle.move(logoTitlePos[0], logoTitlePos[1]);

    sf::Texture tLogoCredits;
    if (!tLogoCredits.loadFromFile(logoCredits))
        return EXIT_FAILURE;
    sf::Sprite sLogoCredits(tLogoCredits);
    sLogoCredits.move(logoCreditsPos[0], logoCreditsPos[1]);

    sf::Font mainFont;
    if (!mainFont.loadFromFile(fontFile))
        return EXIT_FAILURE;

    char menuStrings[8][64] = {
        "START ONE PLAYER GAME\n",
        "START TWO PLAYER GAME\n",
        "LEVEL\n",
        "CARD SET\n",
        "SOUND\n",
        "CARDS MOVING\n",
        "VIEW CARD SET\n",
        "ESC\tEXIT\n"
    };

    sf::Text menuPoints[7];
    for(int i=0; i < 7; i++)
    {
        char menu[32];
        sprintf(menu, "%d. %s\n", i + 1, menuStrings[i]);

        menuPoints[i].setFont(mainFont);
        menuPoints[i].setCharacterSize(fontSize);
        menuPoints[i].setColor(fontColor);
        menuPoints[i].move(boxPos[0] + 8, boxPos[1] + 16 * (i + 1));
        menuPoints[i].setString(menu);
    }

    sf::Text levelText;
    levelText.setFont(mainFont);
    levelText.setCharacterSize(fontSize);
    levelText.setColor(sf::Color::Cyan);
    levelText.move(boxPos[0] + 8 + 84, boxPos[1] + 16 * 3);

    sf::Text cardSetText;
    cardSetText.setFont(mainFont);
    cardSetText.setCharacterSize(fontSize);
    cardSetText.setColor(sf::Color::Cyan);
    cardSetText.move(boxPos[0] + 8 + 112, boxPos[1] + 16 * 4);

    sf::Text soundText;
    soundText.setFont(mainFont);
    soundText.setCharacterSize(fontSize);
    soundText.setColor(sf::Color::Cyan);
    soundText.move(boxPos[0] + 8 + 84, boxPos[1] + 16 * 5);

    sf::Text cardMoveText;
    cardMoveText.setFont(mainFont);
    cardMoveText.setCharacterSize(fontSize);
    cardMoveText.setColor(sf::Color::Cyan);
    cardMoveText.move(boxPos[0] + 8 + 148, boxPos[1] + 16 * 6);

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
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Num1)
                    gameWindow(window, 1);
                if(event.key.code == sf::Keyboard::Num2)
                    gameWindow(window, 2);
                if(event.key.code == sf::Keyboard::Num3)
                    level = (level < 3) ? level + 1 : 1;
                if(event.key.code == sf::Keyboard::Num4)
                    cardSetId = (cardSetId < 3) ? cardSetId + 1 : 0;
                if(event.key.code == sf::Keyboard::Num5)
                    sound = not sound;
                if(event.key.code == sf::Keyboard::Num6)
                    cardMove = not cardMove;
                if(event.key.code == sf::Keyboard::Num7)
                    showCards(window);
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        char levelStr[2];
        sprintf(levelStr, "%d", level);
        levelText.setString(levelStr);

        cardSetText.setString(cardSets[cardSetId]);
        soundText.setString(sound ? "ON" : "OFF");
        cardMoveText.setString(cardMove ? "YES" : "NO");

        window.clear();

        window.draw(sLogoTitle);
        window.draw(sLogoCredits);
        for(int i=0; i < 7; i++)
        {
            window.draw(menuPoints[i]);
        }

        window.draw(levelText);
        window.draw(cardSetText);
        window.draw(soundText);
        window.draw(cardMoveText);

        window.display();
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
