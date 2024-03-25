#include <stdio.h>
#include <string.h>

//lab10 v8
struct country {
    char name[50];
    char capital[50];
    int population;
    int square;
    int num_cities;
};

int main() {
    int n = 3;
    struct country countries[n];

    for (int i = 0; i < n; i++) {
        printf("info about country %d:\n", i + 1);
        printf("enter s name of country: ");
        scanf("%s", countries[i].name);
        printf("capital: ");
        scanf("%s", countries[i].capital);
        printf("population: ");
        scanf("%d", &countries[i].population);
        printf("square of the country: ");
        scanf("%d", &countries[i].square);
        printf("number of cities: ");
        scanf("%d", &countries[i].num_cities);
    }

    for (int i = 0; i < n; i++) {
            if (countries[i].population > countries[i + 1].population) {
                struct country temp = countries[i];
                countries[i] = countries[i + 1];
                countries[i + 1] = temp;
        }
    }

   printf("countries sorted by population:\n");
    for (int i = 0; i < n; i++) {
        printf("%s population: %d\n", countries[i].name, countries[i].population);
    }

    return 0;
}
