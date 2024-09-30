#include <stdio.h>
#include <stdlib.h>
/**********************************************************************
Program: Day 7
Author: Jonathan Oliveri
Date: 02/15/2024
Time spent: 2 hours
Purpose: The purpose of this program is to check that a program or a string that is written is using a correct amount of parenthasis, brackets, and curly braces
***********************************************************************/

#include "stack.h"

int main(int argc, char * argv[])
{
    int n;
    int i = 0;
    scanf("%d", &n);
    getchar();
    
    for(i = 0; i < n; i++)
    {
        char string [1000000];
        fgets(string, sizeof(string), stdin);
        if(CheckString(string))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    
    return 0;
}
