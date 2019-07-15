#include <iostream>
#include "BitMapFileHeader.h"
#include "BitMapInfoHeader.h"
#include "Bitmap.h"

using namespace fractal;

int main()
{
	Bitmap bitmap(800, 600);
	bitmap.write("test.bmp");
	std::cout << "Termino." << std::endl;
	return 0;
}