#include<stdio.h>

int main(){
    int space , a , spaceI , star , i , j , l;

    printf("Enter any number :");
    scanf("%d", &a);

    space = (a*2)-2;
    spaceI = 0;


    for(i = 0; i <  a-1; i++){
        for(j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0; l < spaceI; l++){
            printf(" ");
        }

        if(l != 0)
            printf("*");
        

        printf("\n");

        space--;
        if(i == 0)
            spaceI++;
        else
            spaceI+=2;
    }


    for(i = 0 ;  i < a; i++){
        printf("*");
    }

    for(i = 0;  i < spaceI; i++){
        printf(" ");
    }

    for(i = 0 ;  i < a; i++){
        printf("*");
    }


    printf("\n");
    spaceI = (spaceI*2)-1;
    space = 1;

    for(i = 0; i < a-1;  i++){
        for(j = 0; j  < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0 ; l < spaceI; l++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        spaceI-=2;
        space++;

    }
    

    space = a-2;
    spaceI = 1;
    for(i = 0; i < a-2; i++){
        for(j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0; l < space; l++){
            printf(" ");
        }
        printf("*");
        for(j = 0;  j < spaceI; j++){
            printf(" ");
        }
        printf("*");
        for( j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        space --;
        spaceI+=4;

    }
    spaceI+=2;
    printf("*");
    for(j = 0; j < spaceI; j++){
        printf(" ");
    }
    printf("*");
    return 0;
}
