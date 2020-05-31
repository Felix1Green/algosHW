#include <iostream>
#include <cassert>
#include <cstring>


template <class T>
class IsLessDefault{
public:
    bool operator ()(const T& l, const T& r){
        return l < r;
    }
};




template <class T, class H = IsLessDefault<T>>
class Heap{
private:
    T* arr;
    int size;
    int arr_size;
    H IsLess;
    void BuildHeap();
    void siftdown(int i);
    int siftup(int i);
public:
    Heap():size(0),arr_size(0),IsLess(IsLessDefault<T>()){};
    explicit Heap(const T* arr, int n, H functor = IsLessDefault<T>());
    Heap(const Heap& t) = delete;
    ~Heap();
    Heap operator =(const Heap &t) = delete;
    T Extract_Max();
    T Pop_Max();
    int insert(T i);
    bool isEmpty(){return size == 0;}
};

template <class T,class H>
void Heap<T,H>::BuildHeap() {
    for(int i = size/2 - 1; i >= 0; --i){
        siftdown(i);
    }
}
template <class T,class H>
void Heap<T,H>::siftdown(int i){
    int l = i*2 + 1;
    int r = i*2 + 2;
    int largest = i;
    if(l < size && !IsLess(arr[l],arr[largest]))
        largest = l;
    if(r < size && !IsLess(arr[r], arr[largest]))
        largest = r;
    if(largest != i) {
        std::swap(arr[i],arr[largest]);
        siftdown(largest);
    }
}

template <class T,class H>
int Heap<T,H>::siftup(int i) {
    while(i > 0){
        int parent = (i-1)/2;
        if(!IsLess(arr[parent],arr[i]))
            return i;
        std::swap(arr[i],arr[parent]);
        i = parent;
    }
    return i;
}

template <class T,class H>
Heap<T,H>::Heap(const T* array,int n,H functor){
    arr = new T[n];
    memcpy(arr,array,n*sizeof(T));
    size = n;
    arr_size = n;
    IsLess = functor;
    BuildHeap();
}

template <class T,class H>
T Heap<T,H>::Pop_Max() {
    assert(!isEmpty());
    return arr[0];
}

template <class T,class H>
T Heap<T,H>::Extract_Max() {
    assert(!isEmpty());
    T ans = arr[0];
    arr[0] = arr[size-1];
    size--;
    if(!isEmpty())
        siftdown(0);
    return ans;
}

template <class T,class H>
int Heap<T,H>::insert(T i){
    if(size == arr_size){
        T* buffer = new T[(arr_size > 0? arr_size*2:2)];
        memcpy(arr,buffer,arr_size);
        delete[]arr;
        arr = buffer;
        arr_size*=2;
    }
    arr[size] = i;
    int pos =siftup(size);
    size++;
    return pos;
}

template <class T,class H>
Heap<T,H>::~Heap(){
    delete[]arr;
}



int run(int* A, int n,int k){
    Heap<int> h(A,n);
    int result = 0;
    int picked = 0;int cnt = 0;
    int range = -1;
    while(!h.isEmpty()){
        int poped = h.Extract_Max();
        if(picked +poped > k || (cnt >= range && range !=-1) ){
            result ++;
            picked = 0;cnt = 0;
            range = -1;
        }
        picked += poped;cnt++;
        if(poped > 1)
            range = h.insert(poped/2);
    }
    if(picked != 0)
        result++;
    return result;
}





int main(){
    int n = 0;
    int k = 0;
    std::cin >> n;
    int*A = new int[n];
    for(int i =0; i < n; i++){
        std::cin >> A[i];
    }
    std::cin >> k;
    int res = run(A,n,k);
    std::cout << res << std::endl;
    delete[]A;
    return 0;
}