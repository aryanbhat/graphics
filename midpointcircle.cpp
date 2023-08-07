#include <stdio.h>
#include <graphics.h>

void drawCircleMidPoint(int centerX, int centerY, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    putpixel(centerX,centerY,WHITE);
    while (x <= y) {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX + y, centerY + x, WHITE);
        putpixel(centerX - y, centerY + x, WHITE);
        putpixel(centerX + y, centerY - x, WHITE);
        putpixel(centerX - y, centerY - x, WHITE);

        if (p < 0) {
            p = p + 2 * x + 3;
        } else {
            p = p + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int centerX=250, centerY=250, radius=150;


    drawCircleMidPoint(centerX, centerY, radius);

    delay(5000);
    closegraph();
    return 0;
}
