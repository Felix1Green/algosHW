#include <iostream>
using std::swap;

int partition(int * a, int n){
    if(n <= 1)
        return 0;
    int pivot = a[n-1];
    int i =0; int j = n-2;
    while(i <= j){
        for(;a[i] < pivot;i++){};
        for(;j >= 0 && a[j] > pivot; j--){};
        if(i < j){
            swap(a[i++],a[j--]);
        }
    }
    swap(a[i],a[n-1]);
    return i;
}



void QuickSort(int *a, int n){
    int pivot = partition(a,n);
    if(pivot > 0)QuickSort(a,pivot);
    if(pivot + 1 < n)QuickSort(&a[pivot+1],n - pivot - 1);
}


int main(){
    int a[] = {3,2,1,5,3,6};
    QuickSort(a,6);
    for(int i = 0 ; i < 6; i++){
        std::cout << a[i] << " ";
    }
    return 0;
}