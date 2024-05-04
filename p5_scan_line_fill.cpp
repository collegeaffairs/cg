#include <graphics.h>
#include <iostream>
using namespace std;

int main()
{
    int n = 0, i;
    int a[20][2];

    cout << "Enter the number of vertices of the polygon: ";
    cin >> n;

    cout << "Enter the coordinates of polygon vertices (x y): ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    a[n][0] = a[0][0]; // Connect the last vertex to the first vertex
    a[n][1] = a[0][1];

    int gdriver = DETECT, gmode;
    char pathtodriver[] = "";
    initgraph(&gdriver, &gmode, pathtodriver);

    // Draw the polygon
    for (i = 0; i < n; i++)
    {
        line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
    }

    // Fill the polygon
    setfillstyle(SOLID_FILL, YELLOW);
    fillpoly(n + 1, (int *)a);

    getch();
    closegraph();
    return 0;
}

