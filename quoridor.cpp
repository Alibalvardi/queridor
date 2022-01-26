#include "stdafx.h"

#include <iostream>
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

#include <string.h>

using namespace std;
using namespace sf;

void Update(string & str, RenderWindow & window, CircleShape & bead)
{	

	bool t = true;
	//while (t)	
		if (str == 'w' || str == 's' || str == 'a' || str == 'd')
		{
			if (str == 'w')
				bead.setPosition(bead.getPosition().x, bead.getPosition().y - 77);
			if (str == 's')
				bead.setPosition(bead.getPosition().x, bead.getPosition().y + 77);
			if (str == 'a')
				bead.setPosition(bead.getPosition().x - 77, bead.getPosition().y);
			if (str == 'd')
				bead.setPosition(bead.getPosition().x + 77, bead.getPosition().y);
		}
		else
		{
			str = {};
			cin >> str;
			t = false;
		}	
}
void placewall(RenderWindow & window)
{
	RectangleShape rect(Vector2f(137, 15));
	rect.setFillColor(Color::Blue);
	rect.setPosition(Vector2f(850, 400));
	rect.setRotation(90);
	window.draw(rect);
}
int main()
{

	// create a video mode objejt
	RenderWindow window(VideoMode(1080, 800), " quorider !!", Style::Default);             // craete and open a window for the game 
	window.setFramerateLimit(10);


	// create background 
	Texture texturebackground;   // create a textur to hold a graphic on the  GPU
	texturebackground.loadFromFile("graphics/background.png");// load a graphic into the texture 
	Sprite spritebackground;// creat a sprite
	spritebackground.setTexture(texturebackground);// attach the textur to the sprite
	spritebackground.setPosition(0, 0);// set spritebachground to cover the screen

	// create font 
	Font font1;
	font1.loadFromFile("fonts/font1.ttf");

	//creat text
	Text starttext("press any key to start the game !!" , font1);
	//starttext.setString("press any key to start the game !!");
	starttext.setFont(font1);
	starttext.setCharacterSize(24);
	//starttext.setColor(Color::Black);
	starttext.setPosition(500, 400);

	


	CircleShape bead1;								// create white and black beat circle
	bead1.setRadius(22);
	bead1.setFillColor(Color::White);
	bead1.setPosition(365, 64);

	CircleShape bead2;
	bead2.setRadius(22);
	bead2.setFillColor(Color::Black);
	bead2.setPosition(362, 677);

	bool turn1 = false;
	bool turn2 = true;

	// main game loop
	
	window.draw(starttext);

	while (window.isOpen())
	{
		Event event;
		string input = {};
cin >> input ;
		window.clear(Color::White);                   // clear old frame

													  //draw our game scane here												 
		window.draw(spritebackground);               // draw background 
		

		// input 
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::EventType::KeyPressed:
				if (event.key.code == Keyboard::Key::Escape)
					window.close();
				break;
			case Event::EventType::Closed:
				    window.close();
				break;
			}
		}
		

		//update 

		turn1 = !turn1;
		turn2 = !turn2;

		if (input=='p')
		{
			placewall(window);
		}

		if (turn1)
		{
			Update(input , window, bead1);
			//window.draw(bead1);

		}
		if (turn2)
		{
			Update(input, window, bead2);
			//window.draw(bead2);
		}


        window.draw(bead1);
		window.draw(bead2);
		// render 
		window.display();
	}

	
	return 0; // end of application
}



