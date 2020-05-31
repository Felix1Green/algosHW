#include <iostream>
#include <cassert>
#include <sstream>

using std::cin;

template<class T>
class Queue{
public:
    Queue();
    Queue(const Queue& q) = delete;
    Queue& operator=(Queue& q) = delete;
    void Enqueue(const T& data);
    T Dequeue();
    bool IsEmpty() const {return Tail == nullptr;}
    ~Queue();

private:
    struct Node{
        T data;
        Node* next;
        Node():next(nullptr){}
    };
    Node* Head;
    Node* Tail;
};

template<class T>
Queue<T>::Queue() :
    Head(nullptr),
    Tail(nullptr)
{}

template<class T>
void Queue<T>::Enqueue(const T& data){
    Node* newNode = new Node();
    newNode->data = data;
    if(IsEmpty()){
        Head = newNode;
    }else{
        Tail->next = newNode;
    }
    Tail = newNode;
}

template<class T>
T Queue<T>::Dequeue() {
    assert(!IsEmpty());
    Node* tmp = Head;
    Head = tmp->next;
    if(Head == nullptr)
        Tail = nullptr;
    T ans = tmp->data;
    delete(tmp);
    return ans;
}

template<class T>
Queue<T>::~Queue() {
    while(!IsEmpty()){
        Dequeue();
    }
}


void run(std::istream& input, std::ostream& output){
    int n = 0;
    Queue<int> q;
    input >> n;
    bool result = true;
    for(int i =0 ; i < n && result; i++){
        int command = 0;
        int data = 0;
        input >> command >> data;
        switch(command){
            case 2:
                if(q.IsEmpty()){
                    result = result && data == -1;
                }else
                    result = result && data == q.Dequeue();
                break;
            case 3:
                q.Enqueue(data);
                break;
            default: assert(false);
        }
    }
    output << (result ? "YES":"NO");
}


void testQueue(){
    {//logic test
        Queue<bool> q;
        assert(q.IsEmpty());
        for(int i =0; i < 10; ++i){
            q.Enqueue(i%2 == 0);
        }
        assert(!q.IsEmpty());
        for(int y = 0; y < 10; ++y){
            assert(q.Dequeue() == (y%2 == 0));
        }
    }
    {// 1st test
        std::stringstream input;
        std::stringstream output;
        input << "3 3 44 3 50 2 44 ";
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

int main() {
    //run(std::cin,std::cout);
    testQueue();
    return 0;
}

