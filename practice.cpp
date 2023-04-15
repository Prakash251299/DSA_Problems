#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int operate(int choice,int x,int y,int lastAnswer,int n,int q,int arr[][q],int count[]){
    int idx=0;
    switch(choice){
        case 1: idx = ((x^lastAnswer)%n);
                // j = sizeof(arr[idx])/sizeof(arr[0]);
                arr[idx][count[idx]] = y;
                // printf("%d %d %d\n",arr[0][0],arr[0][1],arr[1][0]);
                count[idx] = count[idx]+1;
                break;
        case 2: idx = ((x^lastAnswer)%n);
                // printf("%d %d %d",arr[0][0],arr[0][1],arr[1][0]);
                // printf("arr[%d]: %d\n",idx,arr[idx]);
                lastAnswer = arr[idx][y % (count[idx])];
                // printf("arr[%d]: %d\n",idx,lastAnswer);
                printf("%d\n",lastAnswer);
                // printf("%d %d %d\n",arr[0][0],arr[0][1],arr[1][0]);
                break;
        default:return lastAnswer;
    }
    return lastAnswer;
}
int main(){
    int n=0,i=0,q=0,choice=0,a=0,b=0,lastAnswer=0;
    scanf("%d",&n);
    int count[n];
    for(i=0;i<n;i++){
        count[i] = 0;
    }
    scanf("%d",&q);
    int arr[n][q];
    i=0;
    while(i<q){
        scanf("%d",&choice);
        scanf("%d",&a);
        scanf("%d",&b);
        lastAnswer = operate(choice,a,b,lastAnswer,n,q,arr,count);
        i++;
    }
    return 0;
}