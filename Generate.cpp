#include "Generate.h"

Generate::Generate()
{
}
Generate::~Generate(){
	delete [] data;
}

void Generate::Start(int x, int y){

	noCols = x;
	noRows = y;
	totalTiles = x * y;
	data = new TileData[totalTiles];

	for (int i = 0; i < totalTiles; i++) {
		data[i].t = 0;
	}



}

void Generate::Draw(){

	int curRow = 0;
	int curCol = 0;
	for (int i = 0; i < totalTiles; i++) {
		cout << data[i].t << " ";
		curCol++;

		if (curCol == noCols) {
			curCol = 0;
			curRow++;
			cout << endl;
		}


	}

}
