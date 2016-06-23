#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <direct.h>
#include <string>
#include <windows.h>

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

std::string getexepath()
{
	char* buffer;

	buffer = _getcwd(NULL, 0);

	std::string exePath = std::string(buffer);

	free(buffer);

	return exePath;
}

void Debug(std::string message)
{
	//OutputDebugString(s2ws(message).c_str());
	MessageBox(NULL, s2ws(message).c_str(), NULL, NULL);
}

sf::Sprite getSprite(std::string spriteName, sf::Texture& outTexture)
{
	std::ostringstream output;
	sf::err().rdbuf(output.rdbuf());

	if (!outTexture.loadFromFile(spriteName))
	{
		// error...
		std::string error = "Load error: " + spriteName + " -> " + output.str();
		Debug(error);
	}

	outTexture.setSmooth(true);

	sf::Sprite tempSprite;
	tempSprite.setTexture(outTexture);

	return tempSprite;
}

sf::Text getText(std::string fontName, sf::Font& outFont)
{
	std::ostringstream output;
	sf::err().rdbuf(output.rdbuf());

	if (!outFont.loadFromFile(fontName))
	{
		// error...
		std::string error = "Load error: " + fontName + " -> " + output.str();
		Debug(error);
	}

	sf::Text tempText;
	tempText.setFont(outFont);

	return tempText;
}






/*
//Create sprite:
sf::Texture testTexture;
sf::Sprite testSprite= getSprite("Assets\\meteor.png", testTexture);

//Draw sprite (inside window.clear)

window.draw(testSprite);
*/

