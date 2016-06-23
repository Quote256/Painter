#include <SFML/Graphics.hpp>
#include "getSprite.h"

#include <Windows.h>

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine, _In_ int       nCmdShow)
{
	sf::RenderWindow window(sf::VideoMode(1600, 800), "Painter");

	sf::Clock gameTime;
	sf::Time currentTime = gameTime.getElapsedTime();

	float startSize = 20.0;
	int size = 20;
	
	sf::CircleShape shape(size);
	shape.setFillColor(sf::Color::Cyan);
	shape.setOrigin(size, size);

	int x = 100;
	int y = 100;
	bool drawing = false;

	sf::Font testFont;
	sf::Text testText = getText("ebrima.ttf", testFont);

	testText.setString("1 = \n2 = \n3 = \n4 = \n5 = \n6 = \n7 = \n"); //Cyan, Red, Green, Yellow, Blue, White, Magenta

	//Cyan
	sf::Font cyanColor;
	sf::Text text1 = getText("ebrima.ttf", cyanColor);
	text1.setColor(sf::Color::Cyan);

	text1.setString("      Cyan\n");
	
	//Red

	sf::Font redColor;
	sf::Text text2 = getText("ebrima.ttf", redColor);
	text2.setColor(sf::Color::Red);

	text2.setString("\n      Red\n");

	//Green
	sf::Font greenColor;
	sf::Text text3 = getText("ebrima.ttf", greenColor);
	text3.setColor(sf::Color::Green);

	text3.setString("\n\n      Green\n");

	//Yellow
	sf::Font yellowColor;
	sf::Text text4 = getText("ebrima.ttf", yellowColor);
	text4.setColor(sf::Color::Yellow);

	text4.setString("\n\n\n      Yellow\n");

	//Blue
	sf::Font blueColor;
	sf::Text text5 = getText("ebrima.ttf", blueColor);
	text5.setColor(sf::Color::Blue);

	text5.setString("\n\n\n\n      Blue\n");

	//White
	sf::Font whiteColor;
	sf::Text text6 = getText("ebrima.ttf", whiteColor);
	text6.setColor(sf::Color::White);

	text6.setString("\n\n\n\n\n      White\n");

	//Magenta
	sf::Font magentaColor;
	sf::Text text7 = getText("ebrima.ttf", magentaColor);
	text7.setColor(sf::Color::Magenta);

	text7.setString("\n\n\n\n\n\n      Magenta\n");

	sf::Texture testTexture;
	sf::Sprite testSprite = getSprite("Link Sprite.gif", testTexture);
	testSprite.setScale(sf::Vector2f(0.5f, 0.5f));

	sf::Color currentColor;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::LShift)
				{
					size-= 4;
					if (size < 1)
					{
						size = 1;
					}
					shape.setScale(sf::Vector2f(size / startSize, size / startSize));
				}
				if (event.key.code == sf::Keyboard::S)
				{
					sf::Image screenshot = window.capture();
					screenshot.saveToFile("Painter.png");
				}

				if (event.key.code == sf::Keyboard::RShift)
				{
					size+=4;
					if (size > 150)
					{
						size = 150;
					}
					shape.setScale(sf::Vector2f(size / startSize, size / startSize));
				}
			}

		}

		//Process stuff here
		
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
//			shape.setFillColor(sf::Color::Cyan);
			currentColor = sf::Color::Cyan;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			shape.setFillColor(sf::Color::Red);
			currentColor = sf::Color::Red;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			shape.setFillColor(sf::Color::Green);
			currentColor = sf::Color::Green;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			shape.setFillColor(sf::Color::Yellow);
			currentColor = sf::Color::Yellow;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			shape.setFillColor(sf::Color::Blue);
			currentColor = sf::Color::Blue;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			shape.setFillColor(sf::Color::White);
			currentColor = sf::Color::White;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			shape.setFillColor(sf::Color::Magenta);
			currentColor = sf::Color::Magenta;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			x = 100;
			y = 100;
			window.clear();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			size = 20;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//Pressed right button
			drawing = true;
			shape.setFillColor(currentColor);
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			drawing = true;
			shape.setFillColor(sf::Color::Black);
		}
		else
		{
			drawing = false;
		}

		//window.clear();


		//Draw stuff here
		shape.setPosition(localPosition.x, localPosition.y);
		if (drawing) {
			window.draw(shape);
		}
		window.draw(testText);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);

		window.display();
	}

	return 0;
}
