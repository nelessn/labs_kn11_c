#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

void upper(char symbol);
int main()
{
    char symbol;
    scanf("%c", &symbol);
    upper(symbol);
    puts("");
    return 0;
}
void upper(char symbol)
{
   if(symbol >= 'a' && symbol <= 'z') {
    printf("1\n");
   }
   else if(symbol >= 'A' && symbol <= 'Z') {
    printf("0\n");
   }
   else{
    printf("wrong");
   }
}
