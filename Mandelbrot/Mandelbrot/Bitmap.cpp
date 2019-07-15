#include "Bitmap.h"
#include "BitMapFileHeader.h"
#include "BitMapInfoHeader.h"
#include <fstream>

using namespace fractal;

namespace fractal 
{
	Bitmap::Bitmap(int width, int height) : 
		m_height(height), m_width(width), 
		m_pPixel(new std::uint8_t[width * height * 3]{})
	{

	}

	Bitmap::~Bitmap()
	{
	}

	bool Bitmap::write(std::string filename)
	{
		BitMapInfoHeader infoHeader;
		BitMapFileHeader fileHeader;

		fileHeader.fileSize = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader) + m_width * m_height * 3;
		fileHeader.dataOffset = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		std::ofstream file;
		file.open(filename, std::ios::out | std::ios::binary);

		if (!file)
		{
			return false;
		}

		file.write((char *)&fileHeader, sizeof(fileHeader));
		file.write((char *)&infoHeader, sizeof(infoHeader));
		file.write((char *)m_pPixel.get(), m_width*m_height*3);
		file.close();
			
		if (!file)
		{
			return false;
		}

		return true;
	}

	void Bitmap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue)
	{
		std::uint8_t *pPixel = m_pPixel.get();

		pPixel += (y * 3) * m_width + (x * 3);

		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}
}







