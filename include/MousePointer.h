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

        sf::String ImageFile; //!< Member variable "ImageFile"
        int LoadSprite();
        void MouseMoved(sf::Vector2f pos);
        void DrawCursor(sf::RenderWindow &window);

        void HideSystem(sf::RenderWindow &window);
        void ShowSystem(sf::RenderWindow &window);
    protected:
    private:
        int ActivePoint[2]; //!< Member variable "ActivePoint[2]"

        sf::Texture PointerTexture;
        sf::Sprite PointerSprite;
};

#endif // MOUSEPOINTER_H
