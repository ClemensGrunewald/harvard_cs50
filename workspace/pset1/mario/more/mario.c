#include <stdio.h>
#include <cs50.h>

int main(void) {

    int height;
    do {
        height = get_int("How high should the pyramid be? ");
    }
    while (height < 0 || height > 23);



    for (int row = 0; row < height; row++){

        // print left pyramid
        for (int i = row; i < height - 1; i++){
         printf(" ");
        }

        for (int i = 0; i < row + 1; i++){
         printf("#");
        }


        //print spacing
        printf("  ");


        //print right pyramid
        for (int i = 0; i < row + 1; i++){
         printf("#");
        }



        printf("\n");
    }

}