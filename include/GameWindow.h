#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


class GameWindow : public sf::RenderWindow
{
    public:
        GameWindow(sf::VideoMode, const String, sf::Uint32 style);
        virtual ~GameWindow();
        bool isOpen();
    protected:
    private:
};

#endif // GAMEWINDOW_H
