#include "stdio.h"

int lenear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index: %d\n", i);
            return i;
        }
    }
    printf("Element not found in the array.\n");
}

int main(){
    int n, key;
    printf("enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter %d element in array : ", n);
    for(int i = 0 ; i < n ; i++ ){
        scanf("%d", &arr[i]);
    }
    printf("enter element to be searched : ");
    scanf("%d", &key);
    lenear_search(arr, n, key);
    return 0;
}