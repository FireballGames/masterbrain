#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "D2Window.h"

extern int logoTitlePos[2];
extern sf::String logoTitle;

extern int logoCreditsPos[2];
extern sf::String logoCredits;

extern sf::String fontFile;
extern int fontSize;
extern sf::Color fontColor;


class MenuWindow : public D2Window
{
    public:
        MenuWindow(sf::RenderWindow &window);
        virtual ~MenuWindow();

        int load();
        void show();
    protected:
        sf::Texture tLogoTitle;
        sf::Texture tLogoCredits;

        sf::Font mainFont;

        sf::Text menuPoints[7];

        sf::Text levelText;
        sf::Text cardSetText;
        sf::Text soundText;
        sf::Text cardMoveText;

        sf::Sprite sLogoTitle;
        sf::Sprite sLogoCredits;


    private:
};

#endif // MENUWINDOW_H
