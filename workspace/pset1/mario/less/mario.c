#include <stdio.h>
#include <cs50.h>

int main(void) {

    int height;

    do {
        height = get_int("How high should the pyramid be? ");
    }
    while (height < 0 || height > 23);

    for (int row = 0; row < height; row++){

        for (int i = row; i < height - 1; i++){
         printf(" ");
        }

        for (int i = 0; i < row + 2; i++){
         printf("#");
        }

        printf("\n");
    }

}
