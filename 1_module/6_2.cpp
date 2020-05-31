#include <iostream>

using std::cin;
using std::swap;


template<class T>
class IsLessDefaultFunctor{
public:
    bool operator()(const T& l, const T& r){
        return l < r;
    }
};

template <class T, class Compare = IsLessDefaultFunctor<T>>
int choose_pivot(T*a, int l, int r,Compare f = Compare()){
    int m = (l+r)/2;
    if(f(a[m],a[l]))
        swap(a[l],a[m]);
    if(f(a[r],a[l]))
        swap(a[l],a[r]);
    if(f(a[m],a[r]))
        swap(a[r],a[m]);
    return r;
}

template <class T, class Compare = IsLessDefaultFunctor<T>>
int Partition(T* a, int l,int r, Compare f = Compare()){
    int p = choose_pivot(a,l,r);
    swap(a[p],a[r]);
    T pivot = a[r];
    int j = r;
    for(int i = r-1;i >= l; i--){
        if(!f(a[i], pivot))
            swap(a[i], a[--j]);
    }
    swap(a[j],a[r]);
    return j;
}

template <class T, class Compare = IsLessDefaultFunctor<T> >
int FindKStat(T* a, int n, int k, Compare IsLess = Compare()){
    int l = 0; int r = n-1;
    while(true){
        int pos = Partition(a,l,r,IsLess);
        if(pos == k)return a[pos];
        if(pos < k)l = pos+1;
        else r = pos -1;
    }
}


int main(){
    int n = 0;
    int k = 0;
    cin >> n >> k;
    int* A = new int[n];
    for(int i = 0; i < n; i ++){
        cin >> A[i];
    }
    int res = FindKStat(A,n,k);
    std::cout << res << std::endl;
    delete [] A;
    return 0;
}