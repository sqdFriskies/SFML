#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;


int main() {
   
    RenderWindow win(VideoMode(1000,1000),"mq");
    win.setFramerateLimit(150);
    CircleShape circ;
    circ.setRadius(100);
    circ.setPosition(0, 300);
    circ.setFillColor(Color(166, 35, 35));


    Clock clk;

    int c = 0;
    int prev = 0;
    while (win.isOpen())
    {
        Event ev;
        while (win.pollEvent(ev))
        {
            if (ev.type == Event::Closed)
            {
                win.close();
            }
        }

        circ.move(1, 0);

        win.clear(Color(62, 143, 51));

        win.draw(circ);

        win.display();
        int time = clk.getElapsedTime().asSeconds();
        if (time != prev)
        {
            std::cout << "FPS:"<<c<<std::endl;
            c = 0;
            prev = time;
        }
        c++;
    }
    return 0;
}