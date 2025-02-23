#include <stdio.h>
#include <math.h>
#include <graphics.h>
#define COLOR YELLOW

typedef struct vector2D {
  int x;
  int y;
} vector2D;

void plot_ellipse_points (vector2D center, int x, int y) {
  putpixel(center.x + x, center.y + y, COLOR);
  putpixel(center.x - x, center.y + y, COLOR);
  putpixel(center.x + x, center.y - y, COLOR);
  putpixel(center.x - x, center.y - y, COLOR);
}

void mid_point_circle (vector2D center, vector2D radius) {
  int x = 0, y = radius.y;

  // initial paramter for region 1
  // slope < 1, x increments & y-plot
  int p10 = pow(radius.y, 2)
            - pow(radius.x, 2) * radius.y
            + pow(radius.x, 2) / 4;
  int dx = 2 * pow(radius.y, 2) * x;
  int dy = 2 * pow(radius.x, 2) * y;

  while (dx < dy) {
    plot_ellipse_points(center, x, y);

    x++;
    if (p10 < 0) {
      dx += 2 * pow(radius.y, 2);
      p10 += dx + pow(radius.y, 2);
    } else {
      y--;
      dx += 2 * pow(radius.y, 2);
      dy -= 2 * pow(radius.x, 2);
      p10 += dx - dy + pow(radius.y, 2);
    }
  }

  // initial paramter for region 2
  // slope > 1, y increments & x-plot
  int p20 = pow(radius.y, 2) * pow(x + 0.5, 2)
            + pow(radius.x, 2) * pow(y - 1, 2)
            - pow(radius.x, 2) * pow(radius.y, 2);
  while (y >= 0) {
    plot_ellipse_points(center, x, y);

    y--;
    if (p20 > 0) {
      dy -= 2 * pow(radius.x, 2);
      p20 += pow(radius.x, 2) - dy;
    } else {
      x++;
      dx += 2 * pow(radius.y, 2);
      dy -= 2 * pow(radius.x, 2);
      p20 += dx - dy + pow(radius.x, 2);
    }
  }
}

int main() {
  vector2D c, r;
  int gd = DETECT, gm;

  initgraph(&gd, &gm, (char*)"");
  printf("Enter the center of the circle:\n");
  scanf("%d%d", &c.x, &c.y);
  printf("Enter the radius of the circle:\n");
  scanf("%d%d", &r.x, &r.y);

  mid_point_circle(c, r);
  delay(3000);
  closegraph();
}
