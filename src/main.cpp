#include "Game.h"

int main()
{
    //// tentar o usar ifstream do C++, nao fileopen do C

    ////RectangleShape r;
    ////r.move();

    //const int width = 500;
    //const int height = 500;
    //sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    //EntityManager entityManager;
    //auto e = entityManager.addEntity("Circle");

    //abyss::math::Vector2 test1(3, 3);
    //std::cout << "Valores iniciais: " << test1;
    //abyss::math::Vector2 test2(4, 4);
    //std::cout << "Valores iniciais: " << test2;

    //test1 += test2;
    //std::cout << test1;
    //test1 -= test2;
    //std::cout << test1;
    //test2 /= 2;
    //std::cout << test2;
    //test1 *= 2;
    //std::cout << test1;

    //sf::CircleShape shape(40.f);
    //shape.setFillColor(sf::Color::Green);
    ////shape.setPosition(300.0f, 300.0f);
    //float circleMoveSpeed = 0.01f;

    //sf::Font aleatoriusFont;
    //if (!aleatoriusFont.loadFromFile("fonts/sylfaen.ttf"))
    //{
    //    std::cerr << "Could not load font!\n";
    //    exit(-1);
    //}

    //sf::Text text("Sample text", aleatoriusFont, 24);
    //text.setPosition(0, height - (float)text.getCharacterSize());

    //while (window.isOpen())
    //{
    //    entityManager.update();
    //    // chama os sistemas

    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //        {
    //            window.close();
    //        }

    //        if (event.type == sf::Event::KeyPressed)
    //        {
    //            std::cout << "Key pressed with code = " << event.key.code << '\n';
    //            if (event.key.code == sf::Keyboard::X)
    //            {
    //                circleMoveSpeed *= -1.0f;
    //            }
    //        }
    //    }

    //    shape.setPosition(shape.getPosition() + sf::abyss::math::Vector2f(circleMoveSpeed, circleMoveSpeed));

    //    window.clear();
    //    window.draw(shape);
    //    window.draw(text);
    //    window.display();
    //}

    Game game("config/config.txt");
    game.run();

    return 0;
}