/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <time.h> 
int main()
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
    int upper = n/2 + n%2;
    int min = upper;
    int sum = 0;
    while (min > 0){
        if(sum < n){ // Se menor que o numero, adiciona proximo valor sequencial.
            sum+=min;
            min--;
        }
        if(sum > n){//Se maior que o numero, decrementa maior valor sequencial e adiciona proximo valor sequencial.
            sum += min - upper;
            upper--;
            min--;
        }
        if(sum == n){ //Se igual, incrementa count e decrementa maior valor sequencial.
            count++;
            sum -=upper;
            upper--;
        }
    }
    return count;
}
