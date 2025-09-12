#include "stdio.h"

int binary_search (int arr[], int n, int key){
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key){
            printf("Element found at index: %d\n", mid);
            return mid;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    printf("Element not found\n");
    return -1;
}

int main(){
    int n, key;
    printf("enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter %d element in array (sorted order): ", n);
    for(int i = 0 ; i < n ; i++ ){
        scanf("%d", &arr[i]);
    }
    printf("enter element to be searched : ");
    scanf("%d", &key);
    binary_search(arr, n, key);
    return 0;
}
