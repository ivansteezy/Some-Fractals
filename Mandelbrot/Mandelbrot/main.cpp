#include <iostream>
#include <cstdint>
#include "BitMapFileHeader.h"
#include "BitMapInfoHeader.h"
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace fractal;

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 99999;
	double max = -99999;

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			double xFractal = (x - WIDTH/2.0) * 2.0/WIDTH;
			double yFractal = (y - HEIGHT/2.0) * 2.0/HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			std::uint8_t red = (std::uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			bitmap.setPixel(x, y, red, red, red);
			if (red < min) min = red;
			if (red > max) max = red;
		}
	}

	std::cout << min << ", " << max << std::endl;
	std::cout << "Termino." << std::endl;
	return 0;
}