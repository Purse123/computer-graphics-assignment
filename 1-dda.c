#include <graphics.h>
#include <stdlib.h>
#define COLOR YELLOW

typedef struct fvector2D {
  float x;
  float y;
} fvector2D;

void dda(fvector2D p1, fvector2D p2){
  float dx = p2.x - p1.x;
  float dy = p2.y - p1.y;
  int steps = fmax(fabs(dx), fabs(dy));

  float x_inc = dx / steps;
  float y_inc = dy / steps;

  for (int i = 0; i <= steps; i++) {
    putpixel(round(p1.x), round(p1.y), COLOR);
    p1.x += x_inc;
    p1.y += y_inc;
  }
}

int main() {
  fvector2D starting, ending;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, (char*)"");

  printf("Enter Starting postition: \n");
  printf("x: ");
  scanf("%f", &starting.x);
  printf("y: ");
  scanf("%f", &starting.y);

  printf("Enter Ending postition: \n");
  printf("x: ");
  scanf("%f", &ending.x);
  printf("y: ");
  scanf("%f", &ending.y);

  dda(starting, ending);
  delay(3000);
  closegraph();
}
