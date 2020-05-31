#include <iostream>
#include <cassert>
#include <sstream>

using std::cin;


int border(const int* a, int size, int k){
    int ans = 0;
    while(ans < size && a[ans] < k){
        ans = (ans == 0? 1:ans*2);
    }
    return (ans > size-1 ? size -1 : ans);
}


int BinS(const int* a,int size,int k){
    int l = 0;
    int r = size;
    while(r-l > 1){
        int m = (l + r)/2;
        if(a[m] <= k)
            l = m;
        else
            r = m;
    }
    if(k > a[r] || a[r] - k < k - a[l])
        return r;
    return l;
}

void output(int* a, int m){
    for(int i = 0 ; i< m; i++){
        std::cout << a[i] << std::endl;
    }
}


int* run(int n,const int* A,int m,const int* B,std::ostream& out){
    int* ans = new int[m];
    for(int k = 0; k < m; k++){
        int rborder = border(A,n,B[k]);
        int lborder = rborder/2;
        int index = BinS(&A[lborder],rborder - lborder,B[k]) + lborder;
        ans[k] = index;
    }
    return ans;
}


int* input(int n){
    int *A = new int[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    return A;
}

int main(){
    int n = 0;int m = 0;
    cin >> n;
    int*A = input(n);
    cin >> m;
    int*B = input(m);
    int* ans = run(n,A,m,B,std::cout);
    output(ans,m);
    delete[] A;
    delete[] B;
    delete []ans;
    return 0;
}