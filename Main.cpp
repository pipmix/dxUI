#include "Text.h"
#include "Generate.h"
using namespace std;

int main() {

	//Text text;
	//text.LoadFont();


	Generate gen;
	gen.Start(24,24);
	gen.Draw();
	cout << endl << endl;

	return 0;
}