#include <stdio.h>

 

int main(){

    int N, a;

    int i, min, max;

    

    scanf("%d", &N);

    

    for(i=0;i<N;i++){

        scanf("%d",&a);

        if(i==0){

            min = a;

            max = a;

        }

        else{

            if(a<min){

                min = a;

            }

            if(a>max){

                max = a;

            }

        } 

    }

    printf("%d %d",min,max);

    

    return 0;

}