#include <iostream>
#include <graphics.h>
using namespace std;
// Define a point structure
struct Point {
    int x, y;
};

// Function to draw a line between two points
void drawLine(int x1, int y1, int x2, int y2, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
}


void drawRectangle(int x_min, int y_min, int x_max, int y_max) {
    rectangle(x_min, y_min, x_max, y_max);
}

// Cohen-Sutherland line clipping algorithm
void cohenSutherlandClip(Point p1, Point p2, int x_min, int y_min, int x_max, int y_max) {
    // Compute region codes for both endpoints
    int code1 = 0, code2 = 0;
    if (p1.x < x_min) code1 |= 1; // Left
    if (p1.x > x_max) code1 |= 2; // Right
    if (p1.y < y_min) code1 |= 4; // Bottom
    if (p1.y > y_max) code1 |= 8; // Top
    if (p2.x < x_min) code2 |= 1;
    if (p2.x > x_max) code2 |= 2;
    if (p2.y < y_min) code2 |= 4;
    if (p2.y > y_max) code2 |= 8;

    // Perform line clipping
    while (true) {
        if ((code1 | code2) == 0) {
            // Both endpoints are inside the window
            drawLine(p1.x, p1.y, p2.x, p2.y,WHITE);
            break;
        } else if (code1 & code2) {
            // Both endpoints are outside on the same side
            break;
        } else {
            // One endpoint is inside, the other is outside
            int code_out = (code1 != 0) ? code1 : code2;
            int x, y;
            if (code_out & 1) {
                // Clip against left boundary
                x = x_min;
                y = p1.y + (p2.y - p1.y) * (x_min - p1.x) / (p2.x - p1.x);
            } else if (code_out & 2) {
                // Clip against right boundary
                x = x_max;
                y = p1.y + (p2.y - p1.y) * (x_max - p1.x) / (p2.x - p1.x);
            } else if (code_out & 4) {
                // Clip against bottom boundary
                y = y_min;
                x = p1.x + (p2.x - p1.x) * (y_min - p1.y) / (p2.y - p1.y);
            } else {
                // Clip against top boundary
                y = y_max;
                x = p1.x + (p2.x - p1.x) * (y_max - p1.y) / (p2.y - p1.y);
            }

            if (code_out == code1) {
                p1.x = x;
                p1.y = y;
                code1 = 0;
            } else {
                p2.x = x;
                p2.y = y;
                code2 = 0;
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI"); // Initialize graphics mode

    
	// Define the clipping window
    int x_min, y_min, x_max, y_max;
	
	cout<<"\nEnter Window Minimum & Maximum Vlaues :: ";
	cin>>x_min>>y_min>>x_max>>y_max;
    // Define the line endpoints
    int x1,y1,x2,y2;
	cout<<"\nEnter The Endpoints of the Line :: ";
	cin>>x1>>y1>>x2>>y2;
    Point p1 = {x1,y1};
    Point p2 = {x2,y2};
	
	drawLine(p1.x, p1.y, p2.x, p2.y, RED);
	
	std::cout << "Do you want to see the clipped line? (yes/no): ";
    char response;
    std::cin >> response;

    if (response == 'y' || response == 'Y') {
        // Call the Cohen-Sutherland line clipping algorithm
        drawRectangle(x_min, y_min, x_max, y_max);
        cohenSutherlandClip(p1, p2, x_min, y_min, x_max, y_max);
    }
	
    // Call the Cohen-Sutherland line clipping algorithm
    cohenSutherlandClip(p1, p2, x_min, y_min, x_max, y_max);

    getch();
    closegraph(); // Close graphics mode
    return 0;
}