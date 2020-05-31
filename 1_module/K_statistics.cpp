#include <iostream>
using std::swap;

int partition(int * mas, int l,int r){
    if (l!=r)
        swap(mas[l + rand() % (r - l)], mas[r]);
    int x = mas[r];
    int i = l-1;
    for (int j = l; j <= r; j++) {
        if (mas[j] <= x)
            swap(mas[++i],mas[j]);
    }
    return i;
}

int k_statistics(int* a,int n, int k){
    int l = 0, r = n - 1;
    for(;;) {
        int pos = partition(a,l,r);
        if (pos < k)
            l = pos + 1;
        else if (pos > k)
            r = pos - 1;
        else return a[k];
    }
};


int main(){
    int a[] = {3,2,1,5,3,6};
    for(int i = 0; i < 6; i ++){
        std::cout << k_statistics(a,6,i) << std::endl;
    }
    return 0;
}