#include <iostream>
#include <cstring>

using std::cin;


template<class T>
class IsLessDefault{
public:
    bool operator ()(const T& l, const T& r){
        return l < r;
    }
};


struct Point{
public:
    int l;
    int index;
    Point():l(0),index(0){};
};

bool IsLessPoint(const Point& l, const Point& r){
    return l.l < r.l;
}


template <class T,class Compare = IsLessDefault<T> >
void Merge(T* arr, int l, int r, T* res, Compare IsLess = Compare()){
    int i = 0; int j = l;
    int cnt = 0;
    while(i < l && j < l+r){
        if(IsLess(arr[i],arr[j]))
            res[cnt++] = arr[i++];
        else{
            res[cnt++] = arr[j++];
        }
    }
    while(i < l)
        res[cnt++] = arr[i++];
    while(j < l+r)
        res[cnt++] = arr[j++];
}



template <class T, class Compare = IsLessDefault<T> >
void MergeSort(T* arr, int n, Compare IsLess = Compare()){
    if(n <= 1)
        return;
    int l = n/2;
    int r = n - n/2;
    MergeSort(arr,l,IsLess);
    MergeSort(arr + l,r,IsLess);
    T* c = new T[n];
    Merge(arr,l,r,c,IsLess);
    memcpy(arr,c,sizeof(Point)*n);
    delete[]c;
}



int run(Point* points,int n){
    MergeSort(points,n,IsLessPoint);
    int result = 0;
    int k = 0;
    for(int i = 0; i < n;i++){
        if(k > 0){
            result += points[i].l - points[i-1].l;
        }
        k+= points[i].index;
    }
    return result;
}


int main(){
    int n = 0;
    cin >> n;
    Point* points = new Point[n*2];
    for(int i = 0; i < n*2; i++){
        cin >> points[i].l;
        points[i].index = (i %2 == 0 ? 1:-1);
    }
    int result = run(points,n*2);
    std::cout << result << std::endl;
    delete[] points;
    return 0;
}