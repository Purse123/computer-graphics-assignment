#include <graphics.h>
#include <stdlib.h>

typedef struct fvector2D {
  float x;
  float y;
} fvector2D;

void dda(fvector2D p1, fvector2D p2){
  float dx = p2.x - p1.x;
  float dy = p2.y - p1.y;
  float steps;
  if (fabs (dx) > fabs (dy)) {
    steps = dx;
  } else {
    steps = dy;
  }
  dx /= steps;
  dy /= steps;
  for (int i =  1; i <= steps; i++) {
    putpixel(p1.x, p1.y, YELLOW);
    p1.x = p1.x + dx;
    p1.y = p1.y + dy;
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
  delay(5000);
  closegraph();
}
