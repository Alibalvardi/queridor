#include "stdafx.h"

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <string.h>

using namespace std;
using namespace sf;

void Update( Event & event ,RenderWindow & window, CircleShape & bead)
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::EventType::KeyReleased :
			if(event.key.code == Keyboard::Key::P)

			if (event.key.code == Keyboard::Key::Escape)
				window.close();
			
			if (event.key.code == Keyboard::Key::Up && bead.getPosition().y > 70)
					 bead.setPosition(bead.getPosition().x, bead.getPosition().y - 77);
			
			if (event.key.code == Keyboard::Key::Down && bead.getPosition().y + 70 < 720)
				bead.setPosition(bead.getPosition().x, bead.getPosition().y + 77);
			
			if (event.key.code == Keyboard::Key::Left && bead.getPosition().x > 65)
				bead.setPosition(bead.getPosition().x - 77, bead.getPosition().y);
			
			if (event.key.code == Keyboard::Key::Right && bead.getPosition().x + 70 < 735)
				bead.setPosition(bead.getPosition().x + 77, bead.getPosition().y);
		break;
		
		case Event :: EventType :: MouseButtonReleased :
			if (event.mouseButton.button == Mouse::Button::Left )
				bead.setPosition(Mouse::getPosition(window).x-11, Mouse::getPosition(window).y-11);
		break;

		case Event::EventType::Closed:
			window.close();
		break;	

		default:
			break;
		}
	}
	
}

void placewall(RenderWindow & window)
{
	RectangleShape rect(Vector2f(138, 15));
	rect.setFillColor(Color::Blue);
	rect.setOrigin(Vector2f(340, 347));
	rect.setPosition(Vector2f(15, 0));
	if (Keyboard::isKeyPressed(Keyboard::R))
		rect.setRotation(180);
	window.draw(rect);
}


int main()
{

	VideoMode vm(1080, 800);             // create a video mode objejt
	RenderWindow window(vm , " quorider !!", Style::Default);             // craete and open a window for the game 
	window.setFramerateLimit(10);


	// create background 
	Texture texturebackground;   // create a textur to hold a graphic on the  GPU
	texturebackground.loadFromFile("graphics/background.png");// load a graphic into the texture 
	Sprite spritebackground;// creat a sprite
	spritebackground.setTexture(texturebackground);// attach the textur to the sprite
	spritebackground.setPosition(0, 0);// set spritebachground to cover the screen
														   

	CircleShape bead1;								// create white and black beat circle
	bead1.setRadius(22);
	bead1.setFillColor(Color::White);
	bead1.setPosition(365, 64);

	CircleShape bead2;
	bead2.setRadius(22);
	bead2.setFillColor(Color::Black);	
	bead2.setPosition(362, 677);

	
	Event event1 ;
	
    // main game loop
	int  turn = 0 ;
	while (window.isOpen())
	{

		window.clear(Color::White);                   // clear old frame

		 //draw our game scane here												 
		window.draw(spritebackground);               // draw background 
		window.draw(bead1);
		window.draw(bead2);
				
		//update 
		RectangleShape rect(Vector2f(138, 15));
		rect.setFillColor(Color::Blue);
		rect.setOrigin(Vector2f(340, 347));
		rect.setPosition(Vector2f(15, 0));
		if (Keyboard::isKeyPressed(Keyboard::R))
				rect.setRotation(180);
		


		
		if (turn % 2 == 0)
		{
			Update(event1, window, bead1);
			window.draw(bead1);
			window.draw(rect);
		}
		else 
		{ 		
			Update(event1, window, bead2); 
			window.draw(bead2);
			window.draw(rect);
		}
		turn++;
	
		// render 
		window.display();
	}

	return 0; // end of application
}



