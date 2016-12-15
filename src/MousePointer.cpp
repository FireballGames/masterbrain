#include <SFML/Graphics.hpp>
#include "MousePointer.h"
#include "MouseSettings.h"

sf::Vector2f MousePointer::getMousePos(sf::RenderWindow &window)
{
    return static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
}

MousePointer::MousePointer()
{
    LoadSprite();
    //ctor
}

MousePointer::~MousePointer()
{
    //dtor
}

int MousePointer::LoadSprite()
{
    if (!PointerTexture.loadFromFile(cursorFilename))
        return EXIT_FAILURE;
    PointerSprite = sf::Sprite(PointerTexture);
    return EXIT_SUCCESS;
}

void MousePointer::MouseMove(sf::RenderWindow &window)
{
    // PointerSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
    PointerSprite.setPosition(getMousePos(window));
    PointerSprite.move(cursorPoint[0], cursorPoint[1]);
}

void MousePointer::DrawCursor(sf::RenderWindow &window)
{
    MouseMove(window);
    window.draw(PointerSprite);
}

void MousePointer::HideSystem(sf::RenderWindow &window)
{
    window.setMouseCursorVisible(false);
}

void MousePointer::ShowSystem(sf::RenderWindow &window)
{
    window.setMouseCursorVisible(true);
}
