#include <iostream>
#include <cstdint>
#include <memory>
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

	double min = 999999;
	double max = -999999;

	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS + 1]{0});
	std::unique_ptr<int[]> Ifractal(new int[WIDTH * HEIGHT]{0});

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			double xFractal = (x - WIDTH / 2.0 - 200.0) * 2.0 / HEIGHT;
			double yFractal = (y - HEIGHT / 2.0) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			Ifractal[y * WIDTH + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				histogram[iterations]++;
			}

			std::uint8_t color = (std::uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
			color = color * color * color;

			bitmap.setPixel(x, y, 0, color, 0);
			if (color < min) min = color;
			if (color > max) max = color;
		}
	}

	bitmap.write("test.bmp");
	std::cout << "Termino." << std::endl;
	return 0;
}