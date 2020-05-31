#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
template <class T>
class Deque{
public:
    Deque();
    Deque(const Deque<T> &t )= delete;
    Deque operator =(Deque<T> &t) = delete;
    void PushFront(const T& data);
    void PushBack(const T& data);
    T PopFront();
    T PopBack();
    bool IsEmpty(){return bufsize == 0;};
    ~Deque(){delete[] a;};
private:
    T* a;
    int head,last;
    int size;int bufsize;
};

template <class T>
Deque<T>::Deque():
    a(nullptr),
    head(0),last(1),
    size(0),bufsize(0)
{}

template<class T>
void Deque<T>::PushFront(const T& data){
    if(a == nullptr){
        a = (T*)malloc(2*sizeof(T));
        size = 2;last+=1;
    }
    else {
        if(--head <0){
            head += size;
        }
        if(bufsize == size){
            T* b = (T*)malloc(size*2*sizeof(T));
            memcpy(b,&a[head],(size - head)*sizeof(T));
            memcpy(&b[size-head],a,(head)*sizeof(T));
            a = b;
            last = size;head = 0;
            size*=2;
        }
    }
    a[head] = data;
    bufsize++;
}
template <class T>
void Deque<T>::PushBack(const T& data){
    if(a == nullptr){
        a = (T*)malloc(2*sizeof(T));
        size = 2;head+=1;
    }
    else {
        if(++last >=size){
            last %=size;
        }
        if (bufsize == size) {
            T *b = (T *) malloc(size * 2 * sizeof(T));
            memcpy(b, &a[head], (size - head) * sizeof(T));
            memcpy(&b[size - head], a, (head) * sizeof(T));
            a = b;
            last = size;
            head = 0;
            size *= 2;
        }
    }
    a[last] = data;
    bufsize++;
}

template <class T>
T Deque<T>::PopFront() {
    assert(!IsEmpty());
    T ans = a[head++];
    if(head >= size){
        head %= size;
    }
    bufsize--;
    return ans;
}

template <class T>
T Deque<T>::PopBack() {
    assert(!IsEmpty());
    T ans = a[last--];
    if(last < 0){
        last = bufsize-2;
    }
    bufsize--;
    return ans;
}

void run(std::istream& input,std::ostream& output){
    int n = 0;
    input >> n;
    Deque<int> dq;
    bool result = true;
    for(int i = 0; i < n; i ++){
        int command = 0;int data = 0;
        input >> command >> data;
        switch(command){
            case 1:
                dq.PushFront(data);
                break;
            case 2:
                if(dq.IsEmpty())
                    result = result && data == -1;
                else
                    result = result && data == dq.PopFront();
                break;
            case 3:
                dq.PushBack(data);
                break;
            case 4:
                if(dq.IsEmpty())
                    result = result && data == -1;
                else
                    result = result && data == dq.PopBack();
                break;
            default:
                assert(false);
        }
    }
    output << (result ? "YES":"NO");
}


void TestDeque(){
    {//logic test
        Deque<bool> q;
        assert(q.IsEmpty());
        for(int i =0; i < 10; ++i){
            q.PushBack(i%2 == 0);
        }
        assert(!q.IsEmpty());
        for(int y = 0; y < 10; ++y){
            assert(q.PopFront() == (y%2 == 0));
       }
    }
    {// 1st test
        std::stringstream input;
        std::stringstream output;
        input << "10 1 44 3 50 2 44 1 66 4 50 2 66 1 50 4 50 3 5 1 15 2 15 4 5";
        run(input,output);
        assert(output.str() == "YES");
    }
    {
        std::stringstream input;
        std::stringstream output;
        input << "2 2 -1 4 -1";
        run(input,output);
        assert(output.str() == "YES");
    }
    {// 3rd test
        std::stringstream input;
        std::stringstream output;
        input << "2 3 44 2 66  ";
        run(input,output);
        assert(output.str() == "NO");
    }
}


int main(){
    run(std::cin,std::cout);
    //TestDeque();
}