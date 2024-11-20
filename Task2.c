#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
} Point;

float calculateDistance(Point p1, Point p2) {
    return sqrtf((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

int isPointInRectangle(Point p, Point topLeft, Point bottomRight) {
    return (p.x >= topLeft.x && p.x <= bottomRight.x && p.y >= topLeft.y && p.y <= bottomRight.y);
}

int main() {
    Point p1, p2, rectTopLeft, rectBottomRight;

    printf("Enter coordinates of point p1 (x y): ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter coordinates of point p2 (x y): ");
    scanf("%f %f", &p2.x, &p2.y);

    printf("Enter coordinates of rectangle's top-left corner (x y): ");
    scanf("%f %f", &rectTopLeft.x, &rectTopLeft.y);

    printf("Enter coordinates of rectangle's bottom-right corner (x y): ");
    scanf("%f %f", &rectBottomRight.x, &rectBottomRight.y);

    printf("Distance between p1 and p2: %.2f\n", calculateDistance(p1, p2));
    printf("Point p1 %s within the rectangle.\n", isPointInRectangle(p1, rectTopLeft, rectBottomRight) ? "lies" : "does not lie");

    return 0;
}
