#ifndef D2WINDOW_H
#define D2WINDOW_H

#include <SFML/Graphics.hpp>

class D2Window
{
    public:
        sf::RenderWindow &window;

        D2Window(sf::RenderWindow &window);
        virtual ~D2Window();

        virtual int load() =0;
        virtual void show() =0;
    protected:
    private:
};

#endif // D2WINDOW_H
