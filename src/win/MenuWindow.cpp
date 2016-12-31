#include "win/MenuWindow.h"
#include "globals.h"
#include "settings.hpp"

int logoTitlePos[2] = {boxPos[0], boxPos[1]};
sf::String logoTitle = "res/title.bmp";

int logoCreditsPos[2] = {boxPos[0], boxPos[1] + N - 40};
sf::String logoCredits = "res/credits.bmp";

sf::String fontFile = "res/zx_spectrum-7.ttf";
int fontSize = 24;
sf::Color fontColor = sf::Color::Yellow;

MenuWindow::MenuWindow(sf::RenderWindow &window): D2Window(window)
{
    //ctor
}

MenuWindow::~MenuWindow()
{
    //dtor
}

int MenuWindow::load()
{
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

    if (!tLogoTitle.loadFromFile(logoTitle))
        return EXIT_FAILURE;
    sLogoTitle = sf::Sprite(tLogoTitle);
    sLogoTitle.move(logoTitlePos[0], logoTitlePos[1]);

    if (!tLogoCredits.loadFromFile(logoCredits))
        return EXIT_FAILURE;
    sLogoCredits = sf::Sprite(tLogoCredits);
    sLogoCredits.move(logoCreditsPos[0], logoCreditsPos[1]);

    if (!mainFont.loadFromFile(fontFile))
        return EXIT_FAILURE;

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

    levelText.setFont(mainFont);
    levelText.setCharacterSize(fontSize);
    levelText.setColor(sf::Color::Cyan);
    levelText.move(boxPos[0] + 8 + 84, boxPos[1] + 16 * 3);

    cardSetText.setFont(mainFont);
    cardSetText.setCharacterSize(fontSize);
    cardSetText.setColor(sf::Color::Cyan);
    cardSetText.move(boxPos[0] + 8 + 112, boxPos[1] + 16 * 4);

    soundText.setFont(mainFont);
    soundText.setCharacterSize(fontSize);
    soundText.setColor(sf::Color::Cyan);
    soundText.move(boxPos[0] + 8 + 84, boxPos[1] + 16 * 5);

    cardMoveText.setFont(mainFont);
    cardMoveText.setCharacterSize(fontSize);
    cardMoveText.setColor(sf::Color::Cyan);
    cardMoveText.move(boxPos[0] + 8 + 148, boxPos[1] + 16 * 6);

    return 1;
}

void MenuWindow::show()
{
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
