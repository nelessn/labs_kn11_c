#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day;
    puts("what is number of the day?");
    scanf("%d", &day);

    if(day == 1 || day == 2 || day == 3 || day == 4 || day == 5) {
        puts("weekday");
    }
    else if(day == 6) {
        puts("saturday");
    }
    else if(day == 7) {
        puts("sunday");
    }
    else {
        puts("wrong, week has 7 days");
    }

    return 0;
}
