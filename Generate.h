#pragma once
#include <iostream>
using namespace std;

enum DIR {
	LEFT = 1,
	TOP = 2,
	RIGHT = 4,
	BOTTOM = 8
};

struct TileData {
	int touch;
	int t;

};

class Generate {

public:
	Generate();
	~Generate();
	void Start(int x, int w);
	void Draw();

private:
	int noCols;
	int noRows;
	int totalTiles;
	TileData* data;

};