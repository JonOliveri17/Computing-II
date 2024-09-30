/*
 Author: Jonathan Oliveri
 Date: 02/05/2024
 Effort: 1 hour 15 minutes
 Purpose: Advance the bit manipulation of the last code, and allow the user to be able to display the bits using arrays this time.
 */
#include <stdio.h>
void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = { 0 };   //Set the first integer to zero and all others to zero by default

    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    
    display_flags(flag_holder, 5);
    
    printf("\n\n");
    
    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);
    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
    int array_index = flag_position / 32;   //finding index
    int bit_position = flag_position % 32;  //finding bit position
    flag_holder[array_index] |= (1u << bit_position); //set selected bit to 1 using bitwise Or function
}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
    int array_index = flag_position / 32;         //same as above
    int bit_position = flag_position % 32;
    
    flag_holder[array_index] &= ~(1u << bit_position); //similar, just with And bitwise function
}

int check_flag(unsigned int flag_holder[], int flag_position)
{
    int array_index = flag_position / 32;         //same as above
    int bit_position = flag_position % 32;
    
    int checked_flag = (flag_holder[array_index] >> bit_position) & 1u; //getting the value of the specified bit using bitwise shift and and opperator 
    
    return checked_flag;

}

void display_flags_as_array(unsigned int flag_holder)
{
    for (int i = 0; i < 32; i++)
    {
        printf("%d", check_flag(&flag_holder, i));    //print bit value
        
        if(i % 4 == 3)
        {
            printf(" ");   //spacing every 4 bits
        }
    }
    printf("\n");
}

void display_flags(unsigned int flag_holder[], int size)
{
    for (int i = 0; i < size; i++)
    {
        display_flags_as_array(flag_holder[i]);
    }
}
