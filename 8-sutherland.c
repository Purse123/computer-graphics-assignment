#include <graphics.h>
#include <stdio.h>

#define LEFT  1  // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

int xmin = 100, ymin = 100, xmax = 300, ymax = 300;

// Function to compute region code for a point (x, y)
int computeCode(int x, int y) {
    int code = 0;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    if (y > ymax) code |= TOP;
    return code;
}

// Cohen-Sutherland Line Clipping Algorithm
void sutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = 1;  // Both endpoints are inside
            break;
        } else if (code1 & code2) {
            break;  // Both endpoints share an outside region (trivially rejected)
        } else {
            int x, y;
            int codeOut = code1 ? code1 : code2;  // Choose an outside point

            // Find intersection point
            if (codeOut & TOP) { // Above the window
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & BOTTOM) { // Below the window
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (codeOut & RIGHT) { // To the right
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (codeOut & LEFT) { // To the left
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            // Replace outside point with intersection
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    // Draw the clipped line if accepted
    if (accept) {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

// Driver Code
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Example line (can be outside the clipping window)
    int x1 = 50, y1 = 50, x2 = 350, y2 = 350;
    
    // Draw original line
    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    
    // Clip the line using Sutherland-Cohen Algorithm
    sutherlandClip(x1, y1, x2, y2);

    delay(2000);
    closegraph();
    return 0;
}
