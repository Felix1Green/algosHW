#include <iostream>
#include <sstream>
#include <cassert>

using std::cin;


int run(int n,const int*a,int m,const int* b,int k){
    int result = 0;int i=0,j = m-1;
    while(i < n && j >= 0){
        if(k-a[i] > b[j])
            i++;
        else if(k - a[i] < b[j])
            j--;
        else if(k-a[i] == b[j])
            result++,i++,j--;
    }
    return result;
}



int main(){
    int n,m = 0;
    cin >> n;
    int* a = new int[n];
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    int *b = new int[m];
    for(int i = 0; i < m; i++){
        cin >>b[i];
    }int k = 0;cin >> k;
    int result = run(n,a,m,b,k);
    std::cout <<result;
    delete []a;
    delete []b;
    return 0;
}