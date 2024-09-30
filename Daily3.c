/*
 Author: Jonathan Oliveri
 Date: 01/30/2024
 Effort: 1 hour
 Purpose: Help the user understand how to manipulate bits and how it looks
 */

#include <stdio.h>
void set_flag(int* pFlag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{
    int flag_holder = 0;
    int i;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    for(i=31; i>=0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if(i%4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

void set_flag(int* pFlag_holder, int flag_position)
{
    *pFlag_holder |= (1 << flag_position);
}

int check_flag(int flag_holder, int flag_position)
{
    int checked = (flag_holder & (1 << flag_position)) >> flag_position;
    return checked;
}
