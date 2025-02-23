#include <stdio.h>
#include <graphics.h>
#define COLOR YELLOW

typedef struct vector2D {
  int x;
  int y;
} vector2D;

void mid_point_circle (vector2D center, int r) {
  int x = 0, y = r;
  int p0 = 1 - r;

  while (x <= y) {
    putpixel(center.x + x, center.y + y, COLOR);
    putpixel(center.x - x, center.y + y, COLOR);
    putpixel(center.x + x, center.y - y, COLOR);
    putpixel(center.x - x, center.y - y, COLOR);
    putpixel(center.x + y, center.y + x, COLOR);
    putpixel(center.x - y, center.y + x, COLOR);
    putpixel(center.x + y, center.y - x, COLOR);
    putpixel(center.x - y, center.y - x, COLOR);

    if (p0 < 0) {
      p0 = p0 + 2*x + 1;
    } else {
      p0 = p0 + 2*x + 1 - 2*y;
      y--;
    }
    x++;
  }
}

int main() {
  vector2D c;
  int radius, gd = DETECT, gm;

  initgraph(&gd, &gm, (char*)"");
  printf("Enter the center of the circle:\n");
  scanf("%d%d", &c.x, &c.y);
  printf("Enter the radius of the circle:\n");
  scanf("%d", &radius);

  mid_point_circle(c, radius);
  delay(3000);
  closegraph();
}
