#include <graphics.h>
#include <math.h>

double expression(double u, int *p) {
  return pow(1 - u, 3) * p[0]
	 + 3 * u * pow(1 - u, 2) * p[1]
         + 3 * pow(u, 2) * (1 - u) * p[2]
         + pow(u, 3) * p[3];
}

void bezier (int *x, int *y) {
  // idk why 0.0005 instead of just 0.25->1/4
  for (double i = 0; i < 1; i += 0.0005) {
    double cordX = expression(i, x);
    double cordY = expression(i, y);
    putpixel((int)cordX, (int)cordY, RED);
  }

  // Control points display
  for (int i = 0; i < 4; i++) {
    putpixel(*(x+i), *(y+i), CYAN);
  }
}

int main() {
  int gd = DETECT , gm;
  int x[4], y[4];

  printf("Enter the x and y coordinates: \n");
  for (int i = 0; i < 4; i++) {
    printf("x%d: ", i+1);
    scanf("%d", &x[i]);
    printf("y%d: ", i+1);
    scanf("%d", &y[i]);
  }
  initgraph(&gd, &gm, (char *)"");

  bezier(x, y);

  delay(3000);
  closegraph();
  return 0;
}  
