#include <stdio.h>
#include <stdlib.h>

int main()
{
    double perimeter;
    printf("what is the perimeter of this square?\n");
    scanf("%lf", &perimeter);
    printf("side of this square is %f cm", perimeter / 2 / 2);
    return 0;
}
