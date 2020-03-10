#include <stdio.h>
#include <time.h>
#include <math.h>

void main(int argc, char const *argv[])
{   
    clock_t t = clock();
    int max_i = 0;
    int max_count = 0;
    int c;
    for (int i = 1; i <= 30000; i++){
        c = contaSomatorios(i);
        if (c > max_count){
            max_i = i;
            max_count = c;
            printf("%d : %d\n", max_i, max_count);
        }
        /*else if (i%1000 == 0)
        {
            printf("%d\n", i);
        }*/
    }
    printf("Maximo count encontrado: %d em %d.\n", max_count, max_i);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("%f segundos\n", time_taken);
}

int contaSomatorios(int n){
    int count = 1;
    int i = 2;
    int impar;
    int min = n;
    int resto = 1;
    int quoc = n;
    while (min > 0){
        impar = i%2;
        if((n%i == resto && !impar) || (n%i == 0 && impar)){
            if(quoc > floor(n/i)){
                quoc = floor(n/i);
                min = (int) ceil(n/i)-resto;
                if(min > 0){
                    count++; 
                }
            }
        }
        min = (int) ceil(n/i)-resto;
        if(i%2==1){
           resto++; 
        }
        i++;
    }

    return count;
}
