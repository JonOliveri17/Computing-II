/*
Author: Jonathan Oliveri
Date: 01/23/2024
Effort: 30 minutes
Purpose: Helps students understand how to successfully use the << and >> opperators for a hands on learning experience
*/

#include <stdio.h>

int main(int argc, char * argv[])
{
    unsigned int x = 1; //Unsigned Integer
    
    for(int counter = 0; x != 0; ++counter)  //++counter will throw it off so you have to do ++counter, and this checks to make sure that the loop keeps running until the integer reaches 0
    {
        printf("%d: %u\n", counter, x);   // prints the count: the iteration
        x = x << 1;                       // shift bit number by 1 space each time
    }
    
    return 0;
}
