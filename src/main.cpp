#include <SFML/Graphics.hpp>
#include <time.h>
#include "settings.hpp"
#include "win/MenuWindow.h"

int mainMenu(sf::RenderWindow &window)
{
    MenuWindow win(window);
	// Start the game loop
	win.run();
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
