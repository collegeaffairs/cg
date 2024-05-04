#include <conio.h>
#include <graphics.h>
#include <cmath>
#include <iostream>

using namespace std;

int dda(int x1, int y1, int x2, int y2)
{
	float x,y;
	float m = (float)(y2-y1)/(x2-x1);
	
	if (abs(m) < 1)
	{
        if (x1>x2)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		x=x1;
		y=y1;
		for(int i = x1; i<=x2; i++){
			 x = i;	
			 y = y+m;	
			putpixel(x, round(y), WHITE);
		}
	}
	else{
	 	if (y1>y2)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
        x=x1;
        y=y1;
		for(int i = y1; i<=y2; i++){
			x = x+1/m;
			y = i;	
			putpixel(round(x), y, RED);
		}
	}
}

main()
{
	int gd = DETECT, gm;
	char pathtodriver[] = "";

	initgraph(&gd, &gm, pathtodriver);

	int x1, y1, x2, y2;

	cout << "Enter x1: \n";
	cin >> x1;
	cout << "Enter y1: \n";
	cin >> y1;
	cout << "Enter x2: \n";
	cin >> x2;
	cout << "Enter y2: \n";
	cin >> y2;
	
	dda(x1, y1, x2,  y2);
//	dda(2, 43, 20, 100);
	getch();
	closegraph();
}

