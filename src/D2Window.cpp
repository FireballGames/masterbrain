#include "D2Window.h"

D2Window::D2Window(sf::RenderWindow &window): window(window)
{
    //ctor
}

D2Window::~D2Window()
{
    //dtor
}

int D2Window::run()
{
    load();
    while (running && window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            int action = OnEvent(event);
        }

        show();
    }
}
