#include "Text.h"



Text::Text()
{
}


Text::~Text()
{
}

void Text::LoadFont()
{

	LPCWSTR fileName = L"C:/Box/Box Sync/Data/font2.fnt";

	HANDLE hFile = CreateFile(fileName,GENERIC_READ, FILE_SHARE_READ,NULL,
		OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,NULL);

	CloseHandle(hFile);

	wstring _fontName, _textureName;
	int _fontSize;
	int pl, pt, pr, pb;
	int _lineHeight;
	int _baseHeight;
	int _texW, _texH, _numChar;

	
	wifstream fs;
	fs.open(fileName);

	wstring tempStr;
	int index;


	fs >> tempStr >> tempStr; 
	_fontName = tempStr.substr(6, tempStr.size() - 6 - 1);

	fs >> tempStr; 
	_fontSize = std::stoi(tempStr.substr(6, tempStr.size() - 6));

	wcout << _fontName.c_str() << endl;
	wcout << _fontSize << endl;



	fs >> tempStr >> tempStr >> tempStr >> tempStr >> tempStr >> tempStr >> tempStr; 

														 // get padding
	fs >> tempStr; // padding=5,5,5,5 
	pt = std::stoi(tempStr.substr(8, 1));
	pr = std::stoi(tempStr.substr(10, 1));
	pb = std::stoi(tempStr.substr(12, 1));
	pl = std::stoi(tempStr.substr(14, 1));
	
	wcout << pl << " " << pt << " " << pr << " " << pb << " " << endl;

	


	fs >> tempStr >> tempStr >> tempStr >> tempStr;
	_lineHeight = std::stoi(tempStr.substr(11, tempStr.size() - 11));

	fs >> tempStr; 
	_baseHeight = std::stoi(tempStr.substr(5, tempStr.size() - 5));


	fs >> tempStr; 
	_texW = std::stoi(tempStr.substr(7, tempStr.size() - 7));

	fs >> tempStr;
	_texH = std::stoi(tempStr.substr(7, tempStr.size() - 7));

	wcout << _lineHeight << " " << _baseHeight << " " << _texW << " " << _texH << " " << endl;

	fs >> tempStr >> tempStr >> tempStr >> tempStr >> tempStr >> tempStr >> tempStr >> tempStr >> tempStr;

	index = tempStr.find(L".");
	_textureName = tempStr.substr(6, index - 6 );

	wcout << _textureName << endl;

	fs >> tempStr >> tempStr;
	_numChar = std::stoi(tempStr.substr(6, tempStr.size() - 6));

	wcout << _numChar << endl;


	_charList = new TextCharacter[_numChar];


	for (int i = 0; i < _numChar; i++){

		fs >> tempStr >> tempStr; 
		_charList[i].id = stoi(tempStr.substr(3, tempStr.size() - 3));

		fs >> tempStr;
		_charList[i].x = stoi(tempStr.substr(2, tempStr.size() - 2));

		fs >> tempStr; 
		_charList[i].y = stoi(tempStr.substr(2, tempStr.size() - 2));

		fs >> tempStr;
		_charList[i].width = stoi(tempStr.substr(6, tempStr.size() - 6));

		fs >> tempStr;
		_charList[i].height = stoi(tempStr.substr(7, tempStr.size() - 7));

		fs >> tempStr;
		_charList[i].xoffset = stoi(tempStr.substr(8, tempStr.size() - 8));

		fs >> tempStr;
		_charList[i].yoffset = stoi(tempStr.substr(8, tempStr.size() - 8));

		fs >> tempStr;
		_charList[i].xadvance = stoi(tempStr.substr(9, tempStr.size() - 9));

		fs >> tempStr >> tempStr; 
	}

}
/*





	// get number of kernings
	fs >> tempStr >> tempStr; // kernings count=96
	startpos = tempStr.find(L"=") + 1;
	font.numKernings = std::stoi(tempStr.substr(startpos, tempStr.size() - startpos));

	// initialize the kernings list
	font.KerningsList = new FontKerning[font.numKernings];

	for (int k = 0; k < font.numKernings; ++k)
	{
		// get first character
		fs >> tempStr >> tempStr; // kerning first=87
		startpos = tempStr.find(L"=") + 1;
		font.KerningsList[k].firstid = std::stoi(tempStr.substr(startpos, tempStr.size() - startpos));

		// get second character
		fs >> tempStr; // second=45
		startpos = tempStr.find(L"=") + 1;
		font.KerningsList[k].secondid = std::stoi(tempStr.substr(startpos, tempStr.size() - startpos));

		// get amount
		fs >> tempStr; // amount=-1
		startpos = tempStr.find(L"=") + 1;
		int t = (float)std::stoi(tempStr.substr(startpos, tempStr.size() - startpos));
		font.KerningsList[k].amount = (float)t / (float)windowWidth;
	}

	return font;
}

*/