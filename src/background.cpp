#include <SFML/Graphics.hpp>
// #include "settings.hpp"
#include "background.h"

int backgroundsCount = 10;
sf::String backgrounds[10] = {
    "res/background/1.png",
    "res/background/2.png",
    "res/background/3.png",
    "res/background/4.png",
    "res/background/5.png",
    "res/background/6.png",
    "res/background/7.png",
    "res/background/8.png",
    "res/background/9.png",
    "res/background/10.png",
};

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

