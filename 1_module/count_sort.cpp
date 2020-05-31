#include <iostream>


void  count_sort(int * a, int n,int k){
    int * c = new int[k];
    for(int i =0 ; i <k; i ++){
        c[i] = 0;
    }
    for(int i = 0;i < n;i ++){
        c[a[i]] +=1;
    }
    int p = 0;
    for(int i =0 ; i < k; i++){
        for(int j = 0; j < c[i]; j++){
            a[p++] = i;
        }
    }
    delete[]c;
}


int main(){
    int a[] = {1, 4 , 2 , 2 , 5 , 9 ,5};
    count_sort(a,7,10);
    for(int i =0; i < 7; i ++){
        std::cout << a[i] << " ";
    }
    return 0;
}