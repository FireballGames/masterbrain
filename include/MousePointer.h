#ifndef MOUSEPOINTER_H
#define MOUSEPOINTER_H

#include <SFML/Graphics.hpp>

class MousePointer
{
    public:
        /** Default constructor */
        MousePointer();
        /** Default destructor */
        virtual ~MousePointer();

        sf::Vector2f getMousePos(sf::RenderWindow &window);
        void DrawCursor(sf::RenderWindow &window);

        void HideSystem(sf::RenderWindow &window);
        void ShowSystem(sf::RenderWindow &window);
    protected:
        int LoadSprite();
    private:
        sf::Texture PointerTexture;
        sf::Sprite PointerSprite;

        void MouseMove(sf::RenderWindow &window);
};

#endif // MOUSEPOINTER_H
