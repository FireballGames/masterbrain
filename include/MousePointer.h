#ifndef MOUSEPOINTER_H
#define MOUSEPOINTER_H

#include <SFML/Graphics.hpp>

class MousePointer
{
    public:
        sf::RenderWindow &window;

        /** Default constructor */
        MousePointer(sf::RenderWindow &window);
        /** Default destructor */
        virtual ~MousePointer();

        sf::Vector2f getMousePos();
        void DrawCursor();

        void HideSystem();
        void ShowSystem();
    protected:
        int LoadSprite();
    private:
        sf::Texture PointerTexture;
        sf::Sprite PointerSprite;

        void MouseMove();
};

#endif // MOUSEPOINTER_H
