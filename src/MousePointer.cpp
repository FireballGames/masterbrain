#include <SFML/Graphics.hpp>
#include "MousePointer.h"

MousePointer::MousePointer()
{
    ImageFile = "res/cursor.png";
    ActivePoint[0] = -16;
    ActivePoint[1] = -8;
    //ctor
    // LoadSprite();
}

MousePointer::~MousePointer()
{
    //dtor
}

int MousePointer::LoadSprite()
{
    if (!PointerTexture.loadFromFile(ImageFile))
        return EXIT_FAILURE;
    PointerSprite = sf::Sprite(PointerTexture);
    return EXIT_SUCCESS;
}

void MousePointer::MouseMoved(sf::Vector2f pos)
{
    PointerSprite.setPosition(pos);
    PointerSprite.move(ActivePoint[0], ActivePoint[1]);
}

void MousePointer::DrawCursor(sf::RenderWindow &window)
{
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
