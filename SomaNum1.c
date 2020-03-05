#include <stdio.h>

void main(int argc, char const *argv[])
{
    int c = contaSomatorios(15);
    printf("\n15: %d \n", c);
}

int contaSomatorios(int n){
    int count = 1; //Proprio numero ja conta
    int target = n/2 + n%2;
    int min = target;
    int sum = 0;
    while (min > 1){
        min = target;
        while (sum < n)
        {
            sum += min;
            min--;
        }
        
        if (sum == n)
        {
           count++;
        }
        target--;
        sum = 0;
    }

    return count;
}
