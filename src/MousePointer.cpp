#include <SFML/Graphics.hpp>
#include "MousePointer.h"
#include "MouseSettings.h"

sf::Vector2f MousePointer::getMousePos()
{
    return static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
}

MousePointer::MousePointer(sf::RenderWindow &window): window(window)
{
    int status = LoadSprite();
    if(status != EXIT_SUCCESS)
    {
        throw status;
    }
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

void MousePointer::MouseMove()
{
    // PointerSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
    PointerSprite.setPosition(getMousePos());
    PointerSprite.move(cursorPoint[0], cursorPoint[1]);
}

void MousePointer::DrawCursor()
{
    MouseMove();
    window.draw(PointerSprite);
}

void MousePointer::HideSystem()
{
    window.setMouseCursorVisible(false);
}

void MousePointer::ShowSystem()
{
    window.setMouseCursorVisible(true);
}
