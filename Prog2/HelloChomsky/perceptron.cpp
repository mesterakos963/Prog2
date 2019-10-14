#include <iostream>
#include <time.h>
#include "mlp.hpp"
#include <png++/png.hpp>

using namespace std;

int main(int argc, char **argv)
{

	srand(time(NULL));

	png::image <png::rgb_pixel> png_image(argv[1]);

	int size = png_image.get_width()*png_image.get_height();

	Perceptron *p = new Perceptron(3, size, 256, 1);

	double* image_red = new double[size];
	double* image_green = new double[size];
	double* image_blue = new double[size];

	for(int i=0; i<png_image.get_width(); ++i)
	{
		for(int j=0; j<png_image.get_height(); ++j)
		{
			image_red[i*png_image.get_width()+j] = png_image[i][j].red;
			image_green[i*png_image.get_width()+j] = png_image[i][j].green;
			image_blue[i*png_image.get_width()+j] = png_image[i][j].blue;
		}
	}

	png::image<png::rgb_pixel> image(png_image.get_height(), png_image.get_width());

	for(png::uint_32 y = 0; y<image.get_height(); ++y)
	{
		for(png::uint_32 x = 0; y<image.get_width(); ++x)
		{
			image[y][x] = png::rgb_pixel(image_red [y* image.get_width()+x],
			image_green [y*image.get_width()+x], image_blue[y*image.get_width+x]);
		}
	}

	image.write("rgb.png");

	double value = (*p)(image_red);

	cout<<value;

	png::image <png::rgb_pixel> png_res ((*p)(png_image));
	png_res.write("kimeneti.png");

	delete p;
	delete image_red;
	delete image_green;
	delete image_blue;
	return 0;
}
