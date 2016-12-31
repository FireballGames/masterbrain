#ifndef CARDSWINDOW_H
#define CARDSWINDOW_H

#include "D2Window.h"


class CardsWindow : public D2Window
{
    public:
        CardsWindow(sf::RenderWindow &window);
        virtual ~CardsWindow();

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

#endif // CARDSWINDOW_H
