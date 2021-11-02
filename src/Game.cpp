#include "../include/Game.h"
#include <fstream>

    Game::Game(){
    //ctor
}
    Game::~Game(){
    delete players[0];
    delete players[1];
}
int Game::menu(RenderWindow & window){
    sf::Font font;

    try{
        if(!font.loadFromFile("assets/SqueakyChalkSound.ttf"))
            throw(font);
    }
    catch(Font){
        std::ofstream errorFile ("logs.txt");
        errorFile << "error font is missing" << std::endl;
        errorFile.close();
        exit(0);
    }
    sf::String newGameString = "GRAJ";
    sf::String statsString = "HISTORIA";
    sf::String endGameString = "KONIEC";
    sf::String titleString = "STATKI by M.B and M.R";

    GameText newGame( newGameString, font, 60, sf::Vector2f(540, 390), sf::Text::Bold, sf::Color::White);
    GameText stats( statsString, font, 30, sf::Vector2f(540, 490), sf::Text::Bold, sf::Color::White);
    GameText endGame( endGameString, font, 30, sf::Vector2f(540, 590), sf::Text::Bold, sf::Color::White);
    GameText title( titleString, font, 60, sf::Vector2f(540, 180), sf::Text::Bold, sf::Color(255, 153, 51));

    while(window.isOpen()){
        sf::Texture textureBackground;
        textureBackground.loadFromFile( "assets/table.jpg" );
        try{
            if (!textureBackground.loadFromFile("assets/table.jpg"))
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
        window.draw(title.text);
        window.draw(newGame.text);
        window.draw(stats.text);
        window.draw(endGame.text);
        window.display();
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                exit(0);
            }

            if( newGame.isHover(window) ){
                newGame.text.setFillColor(sf::Color(255, 153, 51));
                if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left )
                    return 1;
            }
            else
                newGame.text.setFillColor(sf::Color::White);

            if( stats.isHover(window) ){
                stats.text.setFillColor(sf::Color(255, 153, 51));
                if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left )
                    return 2;
            }
            else
                stats.text.setFillColor(sf::Color::White);

            if( endGame.isHover(window) ){
                endGame.text.setFillColor(sf::Color(255, 153, 51));
                if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left )
                    return 3;
            }
            else
                endGame.text.setFillColor(sf::Color::White);
        }
    }
    return 0;
}

string Game::setPlayer(RenderWindow & window){

    std::size_t maxTextLength = 8;

	std::string name;
	sf::Text text;

	sf::Font font;
	font.loadFromFile("assets/SqueakyChalkSound.ttf");
	try{
        if(!font.loadFromFile("assets/SqueakyChalkSound.ttf"))
            throw(font);
    }
    catch(Font){
        std::ofstream errorFile ("logs.txt");
        errorFile << "error font is missing" << std::endl;
        errorFile.close();
        exit(0);
    }

	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(450, 250);

	sf::Texture textureBackground;
    textureBackground.loadFromFile( "assets/table.jpg" );
    try{
            if (!textureBackground.loadFromFile("assets/table.jpg"))
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

    sf::String askString = "Podaj imie:";
    GameText askText(askString, font, 60, sf::Vector2f(540, 150), sf::Text::Bold, sf::Color::White);

    sf::String applyString = "Po wpisaniu kliknij ENTER";
    GameText applyText(applyString, font, 30, sf::Vector2f(540, 630), sf::Text::Bold, sf::Color(255, 153, 51));

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
            if (event.type == sf::Event::Closed){
                window.close();
                exit(0);
            }
            if( event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace )
                && name.size() > 0){

                name.erase(name.size() - 1, 1);
                text.setString(name);
            }

			else if (event.type == Event::TextEntered)
			{
				sf::Uint32 unicode = event.text.unicode;
				if (((unicode >= 48 && unicode <= 57) || (unicode >= 65 && unicode <= 90) ||
					(unicode >= 97 && unicode <= 122)) && name.size() < maxTextLength)
				{
					name += static_cast<char>(unicode);
					text.setString(name);
				}
			}
		}
		window.draw(tableSprite);
        window.draw(askText.text);
		window.draw(text);
        window.draw(applyText.text);

        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Space ) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return ) ){
            if( name.size() > 0 )
                return name;
            else{
                sf::String errorString = "MUSISZ PODAC MINIMUM JEDNA LITERKE";
                GameText errorText(errorString, font, 30, sf::Vector2f(540, 670), sf::Text::Bold, sf::Color::Red);
                window.draw(errorText.text);
            }
        }
        window.display();
	}
	exit(0);


}
void Game::draw(RenderWindow & window, int playerNum ){
    sf::Texture textureBackground;
    textureBackground.loadFromFile( "assets/table.jpg" );


    sf::Sprite tableSprite;
    tableSprite.setTexture( textureBackground );

    sf::Texture textureBigfield;
    textureBigfield.loadFromFile( "assets/playground.png" );
    try{
            if (!textureBigfield.loadFromFile("assets/playground.png"))
                throw(textureBigfield);
        }
        catch(Texture){
            std::ofstream errorFile ("logs.txt");
            errorFile << "error texture is missing" << std::endl;
            errorFile.close();
            exit(0);
    }

    sf::Sprite bigfieldSprite;
    bigfieldSprite.setTexture( textureBigfield );
    bigfieldSprite.setPosition( sf::Vector2f( 70, 160 ) );

    window.draw(tableSprite);
    window.draw(bigfieldSprite);
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            window.draw( *players[playerNum]->getBigField()->getField(i,j)->getDrawing());
        }
    }
    for(int i=0; i<10; i++)
            window.draw( players[playerNum]->getBigField()->getShip(i)->getDrawing()) ;
}
void Game::setShips(RenderWindow & window, int playerNum ){
    bool isInside = false;
    sf::Font font;
    font.loadFromFile("assets/SqueakyChalkSound.ttf");

    while( window.isOpen() ){
        Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    exit(0);
                    break;
                case sf::Event::KeyPressed:
                    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Space ) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return ) ){
                        for(int i=0; i<10; i++){
                            if(i==9) return;
                            if(!players[playerNum]->getBigField()->getShip(i)->getAssigned()) break;
                        }
                        /*
                        String errorString = "NAJPIERW USTAW WSZYSTKIE STATKI.";
                        GameText errorText(errorString, font, 25, sf::Vector2f(540, 670), sf::Text::Bold, sf::Color::Red);
                        window.draw(errorText);
                        */
                    }
                    break;
                default:
                    break;
            }
        }


        sf::String setString = "Statki ustawia gracz " + players[playerNum]->getName() + "\n Po ustawieniu kliknij ENTER";
        GameText setText(setString, font, 30, sf::Vector2f(540, 630), sf::Text::Bold, sf::Color(255, 153, 51));
        draw(window, playerNum);
        window.draw(setText.text);
        for(int i=0; i<10; i++){
            if(players[playerNum]->getBigField()->getShip(i)->isHover(window) ){
                while(window.pollEvent(event)){
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right){
                        players[playerNum]->getBigField()->getShip(i)->setRotation();
                        players[playerNum]->getBigField()->setEmpty(i);
                        assignField(window, *(players[playerNum]->getBigField()), isInside, i);
                    }
                }
                if( setShipPosition(window, playerNum, i) ){
                    isInside = false;
                    if(players[playerNum]->getBigField()->getShip(i)->getAssigned()){
                        players[playerNum]->getBigField()->setEmpty(i);
                    }
                    assignField(window, *(players[playerNum]->getBigField()), isInside, i);
                    if(!isInside){
                        players[playerNum]->getBigField()->getShip(i)->goHome();
                    }

                }
            }
        }
        window.display();
    }
    exit(0);
}
bool Game::setShipPosition(RenderWindow & window, int playerNum, int n ){

    if( sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                players[playerNum]->getBigField()->getShip(n)->setPosition(0, Mouse::getPosition(window).x);
                players[playerNum]->getBigField()->getShip(n)->setPosition(1, Mouse::getPosition(window).y);
                players[playerNum]->getBigField()->getShip(n)->setDrawing()->setPosition(players[playerNum]->getBigField()->getShip(n)->getPosition().x, players[playerNum]->getBigField()->getShip(n)->getPosition().y);
                draw(window, playerNum);
                window.display();
            }
            return true;
    }
    return false;
}
int  Game::isOver(){
    if(players[0]->getHits() == 20) return 1;
    else if(players[1]->getHits() == 20) return 2;
    return 0;
}
bool Game::turn(RenderWindow & window, int i ){
    Event event;
    while(1){
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
             window.close();
             exit(0);
        }

        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
            Vector2i temp = sf::Mouse::getPosition(window);
            switch(i){
                case 0:
                if(temp.x>=600){
                for(int k=0; k<10;k++){
                    if( players[1]->getBigField()->getField(0,k)->getPosition().x <= temp.x && players[1]->getBigField()->getField(0,k)->getPosition().x  + 40 > temp.x){
                        for(int j=0; j<10;j++){
                            if( players[1]->getBigField()->getField(j,k)->getPosition().y <= temp.y && players[1]->getBigField()->getField(j,k)->getPosition().y + 40> temp.y){
                                if(!players[1]->getBigField()->getField(j,k)->getBoom()){
                                    players[1]->getBigField()->getField(j,k)->setBoom(true);
                                    if(players[1]->getBigField()->getField(j,k)->getAssigned() && players[1]->getBigField()->getField(j,k)->getMember() != nullptr){
                                        players[1]->getBigField()->getField(j,k)->getTexture()->loadFromFile("assets/red.png");
                                        players[1]->getBigField()->getField(j,k)->getMember()->setDamage(players[1]->getBigField()->getField(j,k)->getMember()->getDamage() + 1);
                                        if( players[1]->getBigField()->getField(j,k)->getMember()->getDamage() >= players[1]->getBigField()->getField(j,k)->getMember()->getType() ){
                                            players[1]->getBigField()->getField(j,k)->getMember()->setSunk(true);
                                            players[1]->getBigField()->getField(j,k)->getMember()->changeTexture();
                                        }
                                        players[1]->getBigField()->getField(j,k)->getDrawing()->setTexture(*players[1]->getBigField()->getField(j,k)->getTexture());
                                        players[0]->setHits(players[0]->getHits() + 1);
                                        return true;
                                    }
                                    else{
                                        players[1]->getBigField()->getField(j,k)->getTexture()->loadFromFile("assets/miss.png");
                                        players[1]->getBigField()->getField(j,k)->getDrawing()->setTexture(*players[1]->getBigField()->getField(j,k)->getTexture());
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
                    break;
                case 1:
                    if(temp.x<600){
                        for(int k=0; k<10;k++){
                            if( players[0]->getBigField()->getField(0,k)->getPosition().x <= temp.x && players[0]->getBigField()->getField(0,k)->getPosition().x + 40 > temp.x){
                                for(int j=0; j<10;j++){
                                    if( players[0]->getBigField()->getField(j,k)->getPosition().y <= temp.y && players[0]->getBigField()->getField(j,k)->getPosition().y + 40 > temp.y){
                                        if(!players[0]->getBigField()->getField(j,k)->getBoom()){
                                            players[0]->getBigField()->getField(j,k)->setBoom(true);
                                            if(players[0]->getBigField()->getField(j,k)->getAssigned() && players[0]->getBigField()->getField(j,k)->getMember() != nullptr){
                                                players[0]->getBigField()->getField(j,k)->getTexture()->loadFromFile("assets/red.png");

                                                players[0]->getBigField()->getField(j,k)->getMember()->setDamage(players[0]->getBigField()->getField(j,k)->getMember()->getDamage() + 1);
                                                if( players[0]->getBigField()->getField(j,k)->getMember()->getDamage() >= players[0]->getBigField()->getField(j,k)->getMember()->getType() ){
                                                    players[0]->getBigField()->getField(j,k)->getMember()->setSunk(true);
                                                    players[0]->getBigField()->getField(j,k)->getMember()->changeTexture();
                                                }
                                                players[0]->getBigField()->getField(j,k)->getDrawing()->setTexture(*players[0]->getBigField()->getField(j,k)->getTexture());
                                                players[1]->setHits(players[1]->getHits() + 1);
                                                return true;
                                            }
                                            else{
                                                players[0]->getBigField()->getField(j,k)->getTexture()->loadFromFile("assets/miss.png");
                                                players[0]->getBigField()->getField(j,k)->getDrawing()->setTexture(*players[0]->getBigField()->getField(j,k)->getTexture());
                                                return false;
                                            }
                                        }

                                    }

                                }
                            }
                        }
                    }
                    break;
            }


        }
    }
    }
    return false;
}
void Game::setField(){

    players[1]->getBigField()->getMyself()->setPosition(Vector2f(610, 160));
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            Vector2f temp = players[1]->getBigField()->getField(i,j)->getDrawing()->getPosition();
            players[1]->getBigField()->getField(i,j)->getDrawing()->setPosition( ( temp.x + 540), (temp.y) );
            players[1]->getBigField()->getField(i,j)->setPosition(0, temp.x + 540);
        }
    }

    for(int i=0; i<10; i++){
        Vector2f temp = players[1]->getBigField()->getShip(i)->setDrawing()->getPosition();
        players[1]->getBigField()->getShip(i)->setDrawing()->setPosition( ( temp.x + 540), (temp.y) );
    }

}
void Game::drawAll(RenderWindow & window, int opt){
    window.clear(sf::Color(81, 132, 197));

    sf::Texture textureBackground;
    textureBackground.loadFromFile( "assets/table.jpg" );
    try{
            if (!textureBackground.loadFromFile("assets/table.jpg"))
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

    sf::Texture textureBigfieldLeft;
    textureBigfieldLeft.loadFromFile( "assets/playground.png" );
    try{
            if (!textureBigfieldLeft.loadFromFile("assets/playground.png"))
                throw(textureBigfieldLeft);
        }
        catch(Texture){
            std::ofstream errorFile ("logs.txt");
            errorFile << "error texture is missing" << std::endl;
            errorFile.close();
            exit(0);
    }

    sf::Sprite bigfieldSpriteLeft;
    bigfieldSpriteLeft.setTexture( textureBigfieldLeft );
    bigfieldSpriteLeft.setPosition( sf::Vector2f( 70, 160 ) );

    sf::Sprite bigfieldSpriteRight;
    bigfieldSpriteRight.setTexture( textureBigfieldLeft );
    bigfieldSpriteRight.setPosition( sf::Vector2f( 610, 160 ) );

    window.draw(tableSprite);

    for(int h=0; h<2; h++){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                window.draw(*players[h]->getBigField()->getField(i,j)->getDrawing());
            }
        }
        for(int i=0; i<10; i++){
            if(opt == 1 || players[h]->getBigField()->getShip(i)->getSunk())
                window.draw(players[h]->getBigField()->getShip(i)->getDrawing()) ;
        }
    }

    window.draw(bigfieldSpriteLeft);
    window.draw(bigfieldSpriteRight);
}

void Game::assignField(RenderWindow & window, BigField & bigField, bool &isInside, int i){
    for(int k=0; k<10;k++){
        if( bigField.getField(0,k)->getPosition().x - 20 <= bigField.getShip(i)->getLeft() && bigField.getField(0,k)->getPosition().x + 20 > bigField.getShip(i)->getLeft() ){
            for(int j=0; j<10;j++){
                if( bigField.getField(j,k)->getPosition().y - 20 <= bigField.getShip(i)->getTop() && bigField.getField(j,k)->getPosition().y + 20 > bigField.getShip(i)->getTop() ){
                    isInside = true;
                    if( !bigField.checkEmpty(bigField.getShip(i), j, k)  ){
                        bigField.getShip(i)->goHome();
                        break;
                    }

                    bigField.getShip(i)->setDrawing()->setPosition( (bigField.getField(j,k)->getPosition().x + bigField.getShip(i)->getDrawing().getGlobalBounds().width/2.0f ),
                                                            (bigField.getField(j,k)->getPosition().y + bigField.getShip(i)->getDrawing().getGlobalBounds().height/2.0f) );
                    bigField.getShip(i)->setPosition(0,(bigField.getField(j,k)->getPosition().x + bigField.getShip(i)->getDrawing().getGlobalBounds().width/2.0f ));
                    bigField.getShip(i)->setPosition(1, (bigField.getField(j,k)->getPosition().y + bigField.getShip(i)->getDrawing().getGlobalBounds().height/2.0f));
                    bigField.getShip(i)->setAssigned(true);
                    bigField.getField(j,k)->setMember(bigField.getShip(i));
                    bigField.setAssign(bigField.getShip(i), j, k);
                    if(bigField.getField(j,k)->getMember()->getHorizontal() == true){
                        for(int l=1; l<bigField.getShip(i)->getType(); l++){
                            bigField.getField(j,k+l)->setMember(bigField.getShip(i));
                        }
                    }
                    else{
                        for(int l=1; l<bigField.getShip(i)->getType(); l++){
                            bigField.getField(j+l,k)->setMember(bigField.getShip(i));
                        }
                    }

                    break;
                }
            }

        }
    }

}


void Game::setPlayers(RenderWindow & window){
            players[0] = new Player(setPlayer(window));
            players[1] = new Player(setPlayer(window));
}

Player * Game::getPlayer(int playerNum){
    return players[playerNum];
}
