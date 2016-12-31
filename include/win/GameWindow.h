#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "D2Window.h"
#include "MousePointer.h"

class GameWindow : public D2Window
{
    public:
        GameWindow(sf::RenderWindow &window);
        virtual ~GameWindow();

        float timer;
        float delay;
        sf::Clock clock;
        int cardsCount;
        MousePointer mp;
        int selected[2] = { -1, -1};
        int field[40];

        sf::Texture tBackground;
        sf::Sprite sBackground;
        sf::Texture tCardSet;
        sf::Sprite sCard[40];

        int load();
        void show();
        int OnEvent(sf::Event event);
    protected:
    private:
};

#endif // GAMEWINDOW_H
