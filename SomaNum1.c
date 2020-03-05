#include <stdio.h>
#include <time.h>

void main(int argc, char const *argv[])
{   
    clock_t t = clock();
    int max_i = 0;
    int max_count = 0;
    int c;
    for (int i = 0; i <= 30000; i++){
        c = contaSomatorios(i);
        if (c > max_count){
            max_i = i;
            max_count = c;
            printf("%d : %d\n", max_i, max_count);
        }
        else if (i%1000 == 0)
        {
            printf("%d\n", i);
        }
    }
    printf("Maximo count encontrado: %d em %d.\n", max_count, max_i);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("%f segundos\n", time_taken);
}

int contaSomatorios(int n){
    int count = 1; //Proprio numero ja conta
    int target = n/2 + n%2;
    int min = target;
    int sum = 0;
    while (min > 1){
        min = target;
        while (sum < n && min > 0)
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
