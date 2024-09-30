/**********************************************************************
Program: Program 2
Author: Jonathan Oliveri
Date: 04/23/2024
Time spent: Too long
Purpose: This code is used to figure out how many times a ferry has to get across th river to successfully transport how ever many cars from one side of it to the other.
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int c, l, m;
    int *crosstemp;
    int *car_length;
    int temp;
    char **awaitingferry;
    char SideofFerry [7] = "left";
    
    scanf("%d", &c); //c is # of cases
    
    crosstemp = (int*)malloc(sizeof(int) * c);
    for (int i = 0; i < c; i++)
    {
        crosstemp[i] = 0;
    }
    
    for (int i = 0; i < c; i++)
    {
        crosstemp[i] = 1;
        scanf("%d %d", &l, &m);
        l *= 100;
        
        car_length = (int*)malloc(sizeof(int) * m);
        awaitingferry = (char**)malloc(sizeof(char*) * m);
        
        for (int n = 0; n < m; n++)
        {
            awaitingferry[n] = (char*)malloc(sizeof(char) * 7);
            scanf("%d %s", &car_length[n], awaitingferry[n]);
        }
        
        temp = l;
        
        strcpy(SideofFerry, "left");
        
        for (int n = 0; n < m;)
        {
            if (car_length[n] < temp && strcmp(SideofFerry, awaitingferry[n]) == 0)
            {
                temp = temp - car_length[n];
                n++;
            }
            else
            {
                crosstemp [i] ++;
                if(strcmp(SideofFerry, "left") == 0)
                {
                    strcpy(SideofFerry, "right");
                }
                else
                {
                    strcpy(SideofFerry, "left");
                }
                
                temp = l;
            }
        }
        
        free(car_length);
        free(awaitingferry);
    }
    
    for(int i = 0; i < c; i++)
    {
        printf("%d\n", crosstemp[i]);
    }
    
    return 0; 
}
