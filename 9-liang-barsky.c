#include <graphics.h>
#include <stdio.h>

// Clipping window boundaries
int xmin = 100, ymin = 100, xmax = 300, ymax = 300;

// Liang-Barsky algorithm for line clipping
void liangBarskyClip(int x1, int y1, int x2, int y2) {
    float t0 = 0.0, t1 = 1.0;
    int dx = x2 - x1, dy = y2 - y1;
    
    float p[4], q[4];
    p[0] = -dx; q[0] = x1 - xmin;  // Left
    p[1] = dx;  q[1] = xmax - x1;  // Right
    p[2] = -dy; q[2] = y1 - ymin;  // Bottom
    p[3] = dy;  q[3] = ymax - y1;  // Top

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {  // Line is parallel to clipping boundary
            if (q[i] < 0) return; // Line is completely outside
        } else {
            float t = q[i] / p[i];
            if (p[i] < 0) {
                if (t > t1) return; // Outside
                if (t > t0) t0 = t; // Update t0
            } else {
                if (t < t0) return; // Outside
                if (t < t1) t1 = t; // Update t1
            }
        }
    }

    int nx1 = x1 + t0 * dx, ny1 = y1 + t0 * dy;
    int nx2 = x1 + t1 * dx, ny2 = y1 + t1 * dy;

    setcolor(RED);
    line(nx1, ny1, nx2, ny2); // Draw clipped line
}

// Driver Code
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Example line
    int x1 = 50, y1 = 50, x2 = 350, y2 = 350;
    
    // Draw original line
    setcolor(YELLOW);
    line(x1, y1, x2, y2);

    // Clip the line using Liang-Barsky Algorithm
    liangBarskyClip(x1, y1, x2, y2);

    delay(2000);
    closegraph();
    return 0;
}
