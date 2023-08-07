#include <stdio.h>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;
    int p, twoDy, twoDyMinusDx;

    int xStep = (x1 < x2) ? 1 : -1;
    int yStep = (y1 < y2) ? 1 : -1;

    x = x1;
    y = y1;

    putpixel(x, y, WHITE);

    if (dx > dy) {
        p = 2 * dy - dx;
        twoDy = 2 * dy;
        twoDyMinusDx = 2 * (dy - dx);

        while (x != x2) {
            x += xStep;
            if (p < 0) {
                p += twoDy;
            } else {
                y += yStep;
                p += twoDyMinusDx;
            }
            putpixel(x, y, WHITE);
        }
    } else {
        p = 2 * dx - dy;
        twoDy = 2 * dx;
        twoDyMinusDx = 2 * (dx - dy);

        while (y != y2) {
            y += yStep;
            if (p < 0) {
                p += twoDy;
            } else {
                x += xStep;
                p += twoDyMinusDx;
            }
            putpixel(x, y, WHITE);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1=200, y1=10, x2=300, y2=500;

    drawLineBresenham(x1, y1, x2, y2);

    delay(5000);
    closegraph();
    return 0;
}
