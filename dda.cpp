#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float xIncrement, yIncrement;
    float x = x1, y = y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = (float)dx / steps;
    yIncrement = (float)dy / steps;

    putpixel(round(x), round(y), WHITE);

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(round(x), round(y), WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2;

    x1 = 10;
    y1=10;
    x2=100;
    y2=100;

    drawLineDDA(x1, y1, x2, y2);

    delay(5000);
    closegraph();
    return 0;
}
