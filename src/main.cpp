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

int main()
{
    srand(time(0));

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(winSize[0], winSize[1]), gameTitle);

    // Load a sprite to display
    sf::Texture tBackground = loadBackground();
    sf::Sprite sBackground(tBackground);

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

    sf::Text testText;
    testText.setFont(mainFont);
    testText.setCharacterSize(fontSize);
    testText.setColor(fontColor);
    testText.move(boxPos[0] + 16, boxPos[1] + 16);
    testText.setString("Hello world");


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
        app.draw(sLogoTitle);
        app.draw(sLogoCredits);
        app.draw(testText);

        //  for(int i=0; i<n; i++)
        //  {
        //      app.draw(sBlock[i]);
        //  }

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
