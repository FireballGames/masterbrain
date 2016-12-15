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

        int LoadSprite();
        void MouseMove(sf::RenderWindow &window);
        void DrawCursor(sf::RenderWindow &window);

        void HideSystem(sf::RenderWindow &window);
        void ShowSystem(sf::RenderWindow &window);
    protected:
    private:
        sf::Texture PointerTexture;
        sf::Sprite PointerSprite;
};

#endif // MOUSEPOINTER_H
