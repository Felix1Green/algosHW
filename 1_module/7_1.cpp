#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include <cmath>


using std::cin;
using std::string;


template <class T>
class Array{
    int size;
    int buf_size;
public:
    T* arr;
    Array():size(0),buf_size(2){
        arr = new T[buf_size];
    }
    Array(const Array<T>& l) = delete;
    Array operator =(Array<T> & l) = delete;
    void push_back(const T& data);
    T& operator [](const int i){
        assert(i < size || i > size);
        return arr[i];
    }
    void grow();
    ~Array();
};

template <class T>
void Array<T>::push_back(const T& data){
    if(size >= buf_size)
        grow();
    arr[size] = data;
    size++;
}

template <class T>
void Array<T>::grow(){
    T* tmp = new T[buf_size*2];
    for(int i = 0; i < buf_size; i++)
        tmp[i] = arr[i];
    buf_size*=2;
    delete[]arr;
    arr = tmp;
}
template <class T>
Array<T>::~Array() {
    delete[]arr;
}


char if_contains(string s,int index){
    if(index < s.size())
        return s[index];
    return 0;
}


template <class T>
void MSD(T* arr, int size,int index,int Range = 256){
    int* group = new int[Range+1];
    group[Range] = size;
    memset(group,0,Range*sizeof(int));
    for (int i = 0; i < size; ++i) {
        ++group[if_contains(arr[i],index)];
    }
    int sum = 0;
    for (int i = 0; i < Range; ++i) {
        int tmp = group[i];
        group[i] = sum;
        sum += tmp;
    }
    T *res = new T[size];

    for (int i = 0; i < size; ++i) {
        res[group[if_contains(arr[i],index)]] = arr[i];
        ++group[if_contains(arr[i],index)];
    }
    for(int i =0; i < size; i++)
        arr[i] = res[i];
    delete[]res;
    for (int i = 0; i < Range; ++i) {
        int group_size = group[i + 1] - group[i];
        if (group_size > 1) {
            MSD(&arr[group[i]], group_size, index + 1);
        }
    }
    delete[]group;
}




int main(){
    Array<string> a;
    int cnt = 0;
    string s;
    std::getline(cin,s);
    while(!s.empty()){
        a.push_back(s);
        cnt += 1;
        std::getline(cin,s);
    }
    MSD(&a.arr[0],cnt,0);
    for(int i = 0; i < cnt;i++){
        std::cout << a[i] << std::endl;
    }
    return 0;
}