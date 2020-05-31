#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>



template <class T>
class Array{
    int size;
    int buf_size;
public:
    T* arr;
    Array():size(0),buf_size(2){
        arr = new T[buf_size];
    }
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

const int abc_size = 256;

struct get_char_t {
    int k;
    get_char_t(int _k) : k(_k) { }
    int operator ()(const char *data) { return data[k]; }
};

template <typename T, typename less_t>
void counting_sort(T *a, int n, less_t &_get_digit, int *cnt) {
    for (int i = 0; i < abc_size; ++i) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++cnt[_get_digit(a[i])];
    }
    int sum = 0;
    for (int i = 0; i < abc_size; ++i) {
        int tmp = cnt[i];
        cnt[i] = sum;
        sum += tmp;
    }

    T *res = new T[n];

    for (int i = 0; i < n; ++i) {
        res[cnt[_get_digit(a[i])]] = a[i];
        ++cnt[_get_digit(a[i])];
    }

    memcpy(a, res, n * sizeof(T));

    delete[] res;
}

void msd(char **a, int n, int k = 0) {
    int *groups = new int[abc_size + 1];

    groups[abc_size] = n;

    get_char_t get_char(k);

    counting_sort<char *, get_char_t>(a, n, get_char, groups);

    for (int i = 0; i < abc_size; ++i) {
        int group_size = groups[i + 1] - groups[i];
        if (group_size > 1) {
            msd(&a[groups[i]], group_size, k + 1);
        }
    }

    delete[] groups;
}

int main() {
    Array<char *> a;
    int cnt = 0;
    while (true) {
        std::string str;
        std::getline(std::cin, str);
        if (str.empty()) {
            break;
        }
        char *c = new char[str.length() + 1];
        strcpy(c, str.c_str());
        cnt ++;
        a.push_back(c);
    }

    msd(&a.arr[0], cnt);

    for (size_t i = 0; i < cnt; ++i) {
        std::cout << a[i] << std::endl;
    }

    return 0;
}