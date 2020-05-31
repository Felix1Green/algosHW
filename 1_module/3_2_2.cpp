#include <iostream>
#include <sstream>
#include <cassert>

#define CNT 5

template <class T>
class Deque{
public:
    Deque();
    Deque(const Deque<T> &t )= delete;
    Deque operator =(Deque<T> &t) = delete;
    void EnFront(const T& data);
    T DeFront();
    void EnBack(const T& data);
    T DeBack();
    bool IsEmpty(){return tail == nullptr;};
    ~Deque();
private:
    struct Node{
        T* data;
        Node* next;Node* prev;
        int h,t,size;
        Node():data(new T[CNT]),next(nullptr),prev(nullptr),h(CNT-1),t(0),size(0){}
    }*head,*tail;
};

template <class T>
Deque<T>::Deque():
        head(nullptr),
        tail(nullptr)
{}

template <class T>
void Deque<T>::EnBack(const T& data) {
    if(tail == nullptr || tail->size == CNT) {
        Node *newNode = new Node();
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }else {
            tail->next = newNode;
            newNode->prev = tail;
            head->prev = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }if(tail->t >= CNT)
        tail->t = 0;
    tail->data[tail->t++] = data;
    tail->size++;
}

template <class T>
void Deque<T>::EnFront(const T &data) {
    if(head == nullptr || head->size == CNT){
        Node* newNode = new Node();
        if(head == nullptr) {
            tail = newNode;
            head = newNode;
        }else {
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head = newNode;
        }
    }
    if(head->h<0)
        head->h = CNT-1;
    head->data[head->h--] = data;
    head->size++;
}

template <class T>
T Deque<T>::DeBack() {
    assert(!IsEmpty());
    Node* tmp = tail;
    if(--tmp->t < 0)
        tmp->t = CNT-1;
    T ans = tmp->data[tmp->t];
    if(--tmp->size <= 0) {
        if (head == tail)
            head = nullptr, tail = nullptr;
        else {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }delete[] tmp->data;
        delete(tmp);
    }
    return ans;
}

template <class T>
T Deque<T>::DeFront() {
    assert(!IsEmpty());
    Node* tmp = head;
    if(++tmp->h >=CNT)
        tmp->h = 0;
    T ans = tmp->data[tmp->h];
    if(--tmp->size <= 0) {
        if (head == tail)
            head = nullptr, tail = nullptr;
        else {
            head = tmp->next;
            tail->next = head;
            head->prev = tail;
        }delete[] tmp->data;
        delete(tmp);
    }
    return ans;
}

template <class T>
Deque<T>::~Deque() {
    while(!IsEmpty())
        DeBack();
}


bool run(std::istream& input,int n){
    Deque<int> dq;
    bool result = true;
    for(int i = 0; i < n; i ++){
        int command = 0;int data = 0;
        input >> command >> data;
        switch(command){
            case 1:
                dq.EnFront(data);
                break;
            case 2:
                if(dq.IsEmpty())
                    result = result && data == -1;
                else
                    result = result && data == dq.DeFront();
                break;
            case 3:
                dq.EnBack(data);
                break;
            case 4:
                if(dq.IsEmpty())
                    result = result && data == -1;
                else
                    result = result && data == dq.DeBack();
                break;
            default:
                assert(false);
        }
    }
    return result;
}


int main(){
    int n = 0;
    std::cin >> n;
    bool result = run(std::cin,n);
    std::cout << (result ? "YES":"NO") << std::endl;
    return 0;
}