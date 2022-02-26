#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int banyak;
    scanf("%d", &banyak);
    int deret[banyak];
    for (int i = 0; i < banyak; i++) {
        scanf("%d", deret[i]);
    }
    for (int i = 0; i < banyak; i++){
        printf("%d", deret[i]);
    }
    {
        /* code */
    }
    
    return 0;
}
