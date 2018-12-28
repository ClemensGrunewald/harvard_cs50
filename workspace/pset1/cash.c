#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){

    float coins[7] = {200, 100, 50, 25, 10, 5, 1};
    int coinIndex = 0;
    int coinCounter  = 0;

    float change;
    int remain;

    do {
        change = get_float("Change: ");
        remain = (int) roundf(change*100);
    }
    while(change < 0);

    while (remain > 0){
        if(remain >= coins[coinIndex]){
            remain = remain - coins[coinIndex];
            coinCounter++;
        } else {
            if(coinIndex < sizeof(coins)){
                coinIndex++;
            }
        }
    }
    printf("Coins needed: %i\n", coinCounter);

}