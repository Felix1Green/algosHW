#include<iostream>
#include <vector>
#include <stack>


class IsLessDefault{
public:
    bool operator ()(const int& a,const int& b){
        return a < b;
    }
};


template<class T,>
struct BinTreeNode{
private:
    T value;
    BinTreeNode* Left;
    BinTreeNode* Right;
    BinTreeNode* Parent;
public:
    BinTreeNode():value(0),Left(nullptr),Right(nullptr),Parent(nullptr){};
    bool Add(const T& key,)
};



template<class T, class IsLess = IsLessDefault>
bool Add(BinTreeNode<T>*& root,T key,IsLess cmp = IsLess()){
    if(root == nullptr){
        root = new BinTreeNode<T>();
        root->value = key;
        return true;
    }
    BinTreeNode<T>* p = nullptr;
    BinTreeNode<T>* c = root;
    while(c != nullptr){
        p = c;
        if(cmp(key,p->value)){
            c = c->Left;
        }else {
            c = c->Right;
        }
    }
    c = new BinTreeNode<T>();
    c->Parent = p;
    c->value = key;
    if(cmp(c->value,p->value))
        p->Left = c;
    else
        p->Right = c;
    return true;
}

template<class T>
void PrintTree(BinTreeNode<T>* root){
    std::stack<BinTreeNode<T>*> st;
    BinTreeNode<T>* p = root;
    while(!st.empty() || p != nullptr){
        if(p != nullptr){
            std::cout << p->value << " ";
            if(p->Right){
                st.push(p->Right);
            }
            p = p->Left;
        }else{
            p = st.top();
            st.pop();
        }
    }
}

template<class T>
void deleteTree(BinTreeNode<T>* root){
    std::stack<BinTreeNode<T>*> st;
    BinTreeNode<T>* p = root;
    while(!st.empty() || p != nullptr){
        if(p!= nullptr){
            if(p->Right){
                st.push(p->Right);
            }
            if(p->Left) {
                p = p->Left;
                delete p->Parent;
            }else {
                delete p;
                p = nullptr;
            }
        }else{
            p = st.top();
            st.pop();
        }
    }
}


void run(int n, const int* arr){
    BinTreeNode<int>* BinTreeRoot = nullptr;
    for(int i = 0; i < n; i++){
        Add(BinTreeRoot,arr[i]);
    }
    PrintTree(BinTreeRoot);
    deleteTree(BinTreeRoot);
};



int main(){
    int n = 0;
    std::cin >> n;
    int* arr = new int[n];
    for(int i = 0;i < n;i++){
        std::cin >> arr[i];
    }
    run(n,arr);
    delete[] arr;
    return 0;
}