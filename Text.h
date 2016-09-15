#pragma once
#include <windows.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct TextCharacter{

	int id;
	int x;
	int y;
	int width;
	int height;
	int xoffset;
	int yoffset;
	int xadvance;
};

class Text{
public:
	Text();
	~Text();
	void LoadFont();

	TextCharacter* _charList;
};


