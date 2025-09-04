#include <stdio.h>
#define MAX 100
void bubble_short(int arr[], int n){
    int i, j, temp;
    for(i = 0 ; i < n-1; i++){
        for(j = 0 ; j < n-i-1; j++){
            if(arr[j]> arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[MAX],n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubble_short(arr,n);
    printf("Sorted array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}