#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow *window;
    window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (1)
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->draw(shape);
        window->display();
    }

    return 0;
}