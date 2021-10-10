#include <stdio.h>

int main()
{
    /////-------- simple pointer example

    //actual variable
    int number = 99;

    //declare variable
    int *pointer_of_number;
    
    //declare another pointer
    int **pointer_point_another_pointer;

    //menyimpan memori address dari variabel 'number' ke variabel pointer pointer_of_number
    //karakter '&' menandakan akses ke alamat memori
    pointer_of_number = &number;
    
    //menyimpanmemori dari pointer pointer_of_number
    pointer_point_another_pointer = &pointer_of_number;
    
    //print alamat variable dari pointer
    printf("alamat variable number adalah %d (diakses lewat variable pointer)\n", pointer_of_number);

    //print alamat variable dari number
    printf("alamat variable number adalah %d (diakses lewat variable number)\n", &number);

    //print value variable dari number
    printf("alamat variable number adalah %d (diakses lewat variable number)\n", number);

    //print value variable dari pointer
    printf("alamat variable number adalah %d (diakses lewat variable pointer)\n", *pointer_of_number);
    
    //print alamat variable dari pointer to pointer
    printf("alamat variable number adalah %d (diakses lewat variable pointer)\n", pointer_point_another_pointer);
    
    //print value variable dari pointer
    printf("alamat variable number adalah %d (diakses lewat variable pointer)\n", *ointer_point_another_pointer);

}
