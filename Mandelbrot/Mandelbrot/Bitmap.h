#ifndef BITMAP_H_
#define BITMAP_H_
#include <string>
#include <cstdint>

namespace fractal
{
	class Bitmap
	{
		int m_width{ 0 };
		int m_height{ 0 };
		std::unique_ptr<std::uint8_t> m_pPixel{ nullptr };

	public:
		Bitmap(int width, int height);
		bool write(std::string filename);
		void setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
		virtual ~Bitmap();
	};
}
#endif // !BITMAP_H_

