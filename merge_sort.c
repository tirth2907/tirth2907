#include "stdio.h"

int a[50]; // Declare the array globally or pass it as a parameter

void merge(int low, int mid, int high)
{
    int i, j, k, c[50];
    i = low;
    j = mid + 1;
    k = low;
    while(i <= mid && j <= high){
        if(a[i] < a[j]){
            c[k] = a[i];
            k++;
            i++;
        }
        else{
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while(i<= mid){
        c[k] = a[i];
        k++;
        i++;
    }
    while(j<=high){
        c[k] = a[j];
        k++;
        j++;
    }
    for(i= low; i<k ; i++){
        a[i] = c[i];
    }

}

void merge_sort(int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main(){
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(i=0; i<n ; i++){
        scanf("%d",&a[i]);
    }
    merge_sort(0, n - 1);
    printf("Sorted array: ");
    for(i= 0 ; i<n;i++){
        printf("%d \n",a[i]);
    }
    return 0;
}