#include <graphics.h>
#include <stdio.h>

typedef struct BAR {
  int x1, y1;
  int x2, y2;
  int depth;
} BAR;

void translation(BAR *r) {
  int tf;
  printf("Enter the translating factor: ");
  scanf("%d", &tf);
  r->x1 += tf;
  r->y1 += tf;
  r->x2 += tf;
  r->y2 += tf;
  /* r->depth += tf; */
  bar3d(r->x1, r->y1, r->x2, r->y2, r->depth, 1);
}

void reflection(BAR *r) {
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
  bar3d(r->x1, r->y1, r->x2, r->y2, r->depth, 1);
}

void scaling(BAR *r) {
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
  bar3d(r->x1, r->y1, r->x2, r->y2, r->depth, 1);
}

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, (char*)"");

  BAR b = {
    .x1 = 200, .y1 = 200,
    .x2 = 100, .y2 = 300,
    .depth = 50
  };
  /* bar3d (int left, int top, int right, int bottom, int depth, int topflag) */
  bar3d(b.x1, b.y1, b.x2, b.y2, b.depth, 1);

  int option_int;
  printf("-----------------------------\n");
  printf("Choose the 2D transformation operation\n");
  printf("1. Translation\n2. REFLECTION\n3. SCALING\n");
  printf("-----------------------------\n");

  printf("Enter the corresponding integer: ");
  scanf("%d", &option_int);

  switch (option_int) {
    case 1:
      translation(&b);
      break;
    case 2:
      reflection(&b);
      break;
    case 3:
      scaling(&b);
      break;
    default:
      printf("No valid input\n");
  }

  delay(3000);
  closegraph();
}
