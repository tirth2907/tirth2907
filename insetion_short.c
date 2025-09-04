#include "stdio.h"

void insertion_short(int arr[],int n){
    int i ,j ,key ;
    for(i= 1; i<n;i++){
        key = arr[i];
        j = i-1;
        while(j>= 0 && arr[j]>  key)
        {
            arr[j+1]  = arr [j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[100],n,i;
    printf("enter the number of elements :");
    scanf("%d",&n);
    printf("enter the elements :");
    for(i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    insertion_short(arr,n);
    printf("sorted array :");
    for ( i = 0 ; i< n ; i++)
    {
        printf("%d \n",arr[i]);
    }
    return 0;
}
