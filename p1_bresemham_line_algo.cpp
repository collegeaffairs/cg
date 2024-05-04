#include<iostream>
#include<conio.h>
#include<graphics.h>

using namespace std;

int main(){
    int gdriver = DETECT, gmode;
    char pathtodriver[] = "";
    initgraph(&gdriver, &gmode, pathtodriver);
    int x1, y1, x2, y2, x, y, dx, dy, dP;
    cout << "Enter the coordinates of P: ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of Q: ";
    cin >> x2 >> y2;
    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    dP = 2 * dy - dx;
    putpixel(x, y, 1);
    while (x <= x2) {
        x++;
        if (dP <= 0) {
            dP += 2 * dy;
        } else {
            dP += 2 * (dy - dx);
            y++;
        }
        putpixel(x, y, 1);
    }
    getch();
    closegraph();
    return 0;
}
