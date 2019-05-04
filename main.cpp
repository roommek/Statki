#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

#include "Game.h"
#include "Ship.h"
#include "Jednomasztowiec.h"
#include "Dwumasztowiec.h"
#include "Trojmasztowiec.h"
#include "Czteromasztowiec.h"
#include "Player.h"
#include "BigField.h"
#include "GameText.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>

int main(){
    sf::RenderWindow window(sf::VideoMode(1080, 720, 32), "Battle Ships", sf::Style::None);
    sf::Font font;
    font.loadFromFile("SqueakyChalkSound.ttf");

    try{
        if(!font.loadFromFile("SqueakyChalkSound.ttf"))
            throw(font);
    }

    catch(Font){
        std::ofstream errorFile ("logs.txt");
        errorFile << "error font is missing" << std::endl;
        errorFile.close();
        exit(0);
    }

    Game game;
    while (window.isOpen()){
        sf::Event event;
        int menuChoice = game.menu(window);
        switch(menuChoice){
        case 1:{
            game.setPlayers(window);
            while( window.isOpen() ){
                srand (time(NULL));
                int win, i = rand() % 2;
                game.setShips( window, 0);
                game.setShips( window, 1);
                game.setField();
                while(!(win = game.isOver()) ){
                    sf::String moveString = "Ruch gracza " + game.getPlayer(i)->getName();
                    GameText moveText(moveString, font, 60, sf::Vector2f(540, 640), sf::Text::Bold, sf::Color(255, 153, 51));
                    game.drawAll(window);
                    window.draw(moveText.text);
                    window.display();
                    if(game.turn(window, i ))
                        continue;
                    i=(i+1)%2;
                }

                ofstream zapis("stats.txt");
                zapis<<game.getPlayer(win-1)->getName()<<"  Wygranko"<<endl<<endl<<game.getPlayer(win%2)->getName()<<"  Przegranko";
                zapis.close();

                sf::String winnerString = "Zwyciezyl gracz " + game.getPlayer(win-1)->getName();
                GameText winnerText(winnerString, font, 50, sf::Vector2f(540, 640), sf::Text::Bold, sf::Color(255, 153, 51));
                game.drawAll(window, 1);
                window.draw(winnerText.text);

                window.display();
                while (window.waitEvent(event)){
                    if (event.type == sf::Event::KeyPressed && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space )
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::Return )))
                        break;
                    if (event.type == sf::Event::Closed){
                        window.close();
                        exit(0);
                    }
                }
                break;
            }
            break;
        }
        case 2:{
            sf::Texture textureBackground;
            textureBackground.loadFromFile( "table.jpg" );
            try{
            if (!textureBackground.loadFromFile("table.jpg"))
                throw(textureBackground);
            }
            catch(Texture){
            std::ofstream errorFile ("logs.txt");
            errorFile << "error texture is missing" << std::endl;
            errorFile.close();
            exit(0);
    }
            sf::Sprite tableSprite;
            tableSprite.setTexture( textureBackground );
            window.draw(tableSprite);

            fstream file;
            try{
                file.open( "stats.txt", ios::in );
                sf::String lastBattleString = "Ostatni pojedynek";

                GameText lastBattle( lastBattleString, font, 60, sf::Vector2f(540, 150), sf::Text::Bold, sf::Color(255, 153, 51));
                window.draw(lastBattle.text);
                if(file.good() == true){
                    int x=0;
                    for(int i=0; i<5; i++){
                        std::string data;
                        getline(file, data);
                        sf::String formattedData(data);
                        GameText infoText(formattedData, font, 60, sf::Vector2f(540, 300+x), sf::Text::Bold, sf::Color::White);
                        window.draw(infoText.text);
                        window.display();
                        x+=50;
                    }
                    file.close();
                }
                else{
                    sf::String errorString = "NIKT JESZCZE NIE ZAGRAL W GRE!";
                    throw errorString;
                }

            }
            catch(sf::String errorString){
                GameText errorText(errorString, font, 60, sf::Vector2f(540, 150), sf::Text::Bold, sf::Color::White);
                window.draw(errorText.text);
                window.display();
            }
            catch(...){

            exit(0);

            }
            while (window.waitEvent(event)){
                if (event.type == sf::Event::KeyPressed && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space )
                    || sf::Keyboard::isKeyPressed(sf::Keyboard::Return )))
                    break;
                }
            break;
        }
        default:
            window.close();
            exit(0);
            break;
        }
    }

    return 0;
}

