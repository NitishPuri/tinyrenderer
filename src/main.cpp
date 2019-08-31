
#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

// Draw line segments.
void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
  for (auto t = 0.; t < 1; t += .01) {
    auto x = static_cast<int>(x0 + (x1 - x0) * t);
    auto y = static_cast<int>(y0 + (y1 - y0) * t);
    image.set(x, y, color);
  }
}

int main() {
  TGAImage image(800, 800, TGAImage::RGB);
  image.set(52, 41, red);
  image.flip_vertically(); // i want to have the origin at the left bottom
                           // corner of the image

  // make a line
  line(10, 10, 600, 600, image, red);
  image.write_tga_file("output.tga");
  return 0;
}
