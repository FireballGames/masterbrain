#include <SFML/Graphics.hpp>
#include <time.h>
#include "settings.hpp"

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

    char levelStr[2];
    sprintf(levelStr, "%d", level);
    levelText.setString(levelStr);

    cardSetText.setString(cardSets[cardSetId]);
    soundText.setString(sound ? "ON" : "OFF");
    cardMoveText.setString(cardMove ? "YES" : "NO");

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
                    return EXIT_SUCCESS;
                if(event.key.code == sf::Keyboard::Num2)
                    return EXIT_SUCCESS;
                if(event.key.code == sf::Keyboard::Num3)
                    return EXIT_SUCCESS;
                if(event.key.code == sf::Keyboard::Num4)
                    return EXIT_SUCCESS;
                if(event.key.code == sf::Keyboard::Num5)
                    return EXIT_SUCCESS;
                if(event.key.code == sf::Keyboard::Num6)
                    return EXIT_SUCCESS;
                if(event.key.code == sf::Keyboard::Num7)
                    return EXIT_SUCCESS;
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        // Clear screen
        window.clear();

        // Draw the sprite
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

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}

int main()
{
    srand(time(0));

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(winSize[0], winSize[1]), gameTitle);

    // Load a sprite to display
    sf::Texture tBackground = loadBackground();
    sf::Sprite sBackground(tBackground);

    int res = mainMenu(app);
    if(res != EXIT_SUCCESS)
        return res;

    //  int n = 0;
    //  for(int i=1; i<blockCols; i++)
    //      for(int j=1; j<blockRows; j++)
    //      {
    //          sBlock[n].setTexture(tBlock);
    //          sBlock[n].setPosition(i * blockW, j * blockH);
    //          n++;
    //      }

    //  sf::Texture tBall;
    //  if (!tBall.loadFromFile(ball))
    //      return EXIT_FAILURE;
    //  sf::Sprite sBall(tBall);
    //  sBall.setPosition(ballPos[0], ballPos[1]);

    //  sf::Texture tPaddle;
    //  if (!tPaddle.loadFromFile(paddle))
    //       return EXIT_FAILURE;
    //  sf::Sprite sPaddle(tPaddle);
    //  sPaddle.setPosition(paddlePos[0], paddlePos[1]);

    // float dx = ballSpeed[0];
    // float dy = ballSpeed[1];

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                app.close();
        }

        //  sBall.move(dx, 0);
        //  for(int i=0; i<n; i++)
        //      if(isCollide(sBall, sBlock[i]))
        //      {
        //          sBlock[i].setPosition(posNowhere[0], posNowhere[1]);
        //          dx = -dx;
        //      }

        //  sBall.move(0, dy);
        //  for(int i=0; i<n; i++)
        //      if(isCollide(sBall, sBlock[i]))
        //      {
        //          sBlock[i].setPosition(posNowhere[0], posNowhere[1]);
        //          dy = -dy;
        //      }

        //  sf::Vector2f b = sBall.getPosition();
        //  if(b.x < 0 || b.x > N)
        //      dx = -dx;
        //  if(b.y < 0 || b.y > M)
        //      dy = -dy;

        //  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        //      sPaddle.move( 6, 0);
        //  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        //      sPaddle.move(-6, 0);

        //  if(isCollide(sPaddle, sBall))
        //      dy = -(rand() % 5 + 2);

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sBackground);

        //  for(int i=0; i<n; i++)
        //  {
        //      app.draw(sBlock[i]);
        //  }

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
