#include <graphics.h>
#include <stdlib.h>

typedef struct fvector2D {
  int x;
  int y;
} fvector2D;

void bresenhams(fvector2D p1, fvector2D p2) {
  int dx = abs(p2.x - p1.x);
  int dy = abs(p2.y - p1.y);

  int incrementer_x = (p2.x > p1.x) ? 1: -1;
  int incrementer_y = (p2.y > p1.y) ? 1: -1;
  // m <= 1 -> p = 2*dy - dx
  // m > 1 -> p = 2*dx - dy
  if (dy >= dx) {
    int desPar = 2 * dy - dx;
    while (p1.x != p2.x) {
      putpixel(p1.x, p1.y, YELLOW);
      p1.x += incrementer_x;
      if (desPar < 0) {
        desPar = desPar + 2 * dy;
      } else {
        desPar = desPar + 2 * dy - 2 * dx;
        p1.y += incrementer_y;
      }
    }
  } else {
    int desPar = 2 * dx - dy;
    while (p1.y != p2.y) {
      putpixel(p1.x, p1.y, YELLOW);
      p1.y += incrementer_y;
      if (desPar < 0) {
        desPar = desPar + 2 * dx;
      } else {
        desPar = desPar + 2 * dx - 2 * dy;
        p1.x += incrementer_x;
      }
    }
  }
}

int main() {
  fvector2D starting, ending;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, (char *)"");

  printf("Enter Starting postition: \n");
  printf("x: ");
  scanf("%d", &starting.x);
  printf("y: ");
  scanf("%d", &starting.y);

  printf("Enter Ending postition: \n");
  printf("x: ");
  scanf("%d", &ending.x);
  printf("y: ");
  scanf("%d", &ending.y);

  bresenhams(starting, ending);
  delay(3000);

  closegraph();
}
