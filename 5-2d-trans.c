#include <stdio.h>
#include <math.h>
#include <graphics.h>
#define PI 3.1415
#define DEG2RAD(x) (x * (PI / 180))

typedef struct vector2d {
  int x;
  int y;
} vector2d;

typedef struct rect {
  int x1, y1;
  int x2, y2;
} RECTANGLE;

void translation(RECTANGLE *r) {
  int tf;
  printf("Enter the translating factor: ");
  scanf("%d", &tf);
  r->x1 += tf;
  r->y1 += tf;
  r->x2 += tf;
  r->y2 += tf;
  rectangle(r->x1, r->y1, r->x2, r->y2);
}

void reflection(RECTANGLE *r) {
  int op;
  printf("-----------------------------\n");
  printf("Choose which Rotation\n");
  printf("1. X-axis\n2. Y-axis\n");
  printf("-----------------------------\n");
  scanf("%d", &op);

  // getmaxx() gives width of window
  // getmaxy() gives height of window
  if (op == 1) {
    r->y1 = getmaxy() - r->y1;
    r->y2 = getmaxy() - r->y2;
  } else if(op == 2) {
    r->x1 = getmaxx() - r->x1;
    r->x2 = getmaxx() - r->x2;
  } else {
  }
  rectangle(r->x1, r->y1, r->x2, r->y2);
}

void rotation(RECTANGLE *r) {
  int deg;
  printf("Enter the degree of rotation: ");
  scanf("%d", &deg);
  double rad = DEG2RAD(deg);
  int x1 = r->x1, y1 = r->y1;
  int x2 = r->x2, y2 = r->y1;
  int x3 = r->x2, y3 = r->y2;
  int x4 = r->x1, y4 = r->y2;
  int cx = (r->x1 + r->x2) / 2;
  int cy = (r->y1 + r->y2) / 2;

 // Translate points to origin
  x1 -= cx; y1 -= cy;
  x2 -= cx; y2 -= cy;
  x3 -= cx; y3 -= cy;
  x4 -= cx; y4 -= cy;

  // Rotate each point using matrix multiplication
  int new_x1 = (x1 * cos(rad)) - (y1 * sin(rad));
  int new_y1 = (x1 * sin(rad)) + (y1 * cos(rad));
  int new_x2 = (x2 * cos(rad)) - (y2 * sin(rad));
  int new_y2 = (x2 * sin(rad)) + (y2 * cos(rad));
  int new_x3 = (x3 * cos(rad)) - (y3 * sin(rad));
  int new_y3 = (x3 * sin(rad)) + (y3 * cos(rad));
  int new_x4 = (x4 * cos(rad)) - (y4 * sin(rad));
  int new_y4 = (x4 * sin(rad)) + (y4 * cos(rad));

 // Translate points to original
  new_x1 += cx; new_y1 += cy;
  new_x2 += cx; new_y2 += cy;
  new_x3 += cx; new_y3 += cy;
  new_x4 += cx; new_y4 += cy;

  // Translate points back to original position (add cx, cy)
  line(new_x1, new_y1, new_x2, new_y2);
  line(new_x2, new_y2, new_x3, new_y3);
  line(new_x3, new_y3, new_x4, new_y4);
  line(new_x4, new_y4, new_x1, new_y1);
}

void scaling(RECTANGLE *r) {
  int sf;
  printf("Enter the scaling factor: ");
  scanf("%d", &sf);

  int cx = (r->x1 + r->x2) / 2;
  int cy = (r->y1 + r->y2) / 2;
  // translating to center & scaling
  r->x1 = cx + (r->x1 - cx) * sf;
  r->y1 = cy + (r->y1 - cy) * sf;
  r->x2 = cx + (r->x2 - cx) * sf;
  r->y2 = cy + (r->y2 - cy) * sf;
  rectangle(r->x1, r->y1, r->x2, r->y2);
}

int main() {
  int gd = DETECT, gm;
  RECTANGLE r = {.x1 = 100, .y1 = 100, .x2 = 300, .y2 = 300};

  initgraph(&gd, &gm, (char*)"");
  rectangle(r.x1, r.y1, r.x2, r.y2);

  int option_int;
  printf("-----------------------------\n");
  printf("Choose the 2D transformation operation\n");
  printf("1. Translation\n2. REFLECTION\n3. ROTATION\n4. SCALING\n");
  printf("-----------------------------\n");

  printf("Enter the corresponding integer: ");
  scanf("%d", &option_int);

  switch (option_int) {
    case 1:
      translation(&r);
      break;
    case 2:
      reflection(&r);
      break;
    case 3:
      rotation(&r);
      break;
    case 4:
      scaling(&r);
      break;
    default:
      printf("No valid input\n");
  }

  delay(3000);
  closegraph();
}
