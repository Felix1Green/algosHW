#include<iostream>
#include <vector>
#include <stack>




class IsLessDefault{
public:
    bool operator ()(const int& a,const int& b){
        return a < b;
    }
};


template<class T>
struct BinTreeNode{
public:
    T value;
    BinTreeNode* Left;
    BinTreeNode* Right;
    BinTreeNode* Parent;
    BinTreeNode():value(0),Left(nullptr),Right(nullptr),Parent(nullptr){};
};

template<class T,class H = IsLessDefault>
class BinTree{
    BinTreeNode<T>* root;
    H IsLess;
public:
    BinTree(H Less = H()):root(nullptr),IsLess(Less){};
    bool Add(const T& key);
    T* PreOrder(const int& n);
    ~BinTree();
};



template<class T, class H>
bool BinTree<T,H>::Add(const T& key){
    if(root == nullptr){
        root = new BinTreeNode<T>();
        root->value = key;
        return true;
    }
    BinTreeNode<T>* p = nullptr;
    BinTreeNode<T>* c = root;
    while(c != nullptr){
        p = c;
        if(IsLess(key,p->value)){
            c = c->Left;
        }else   {
            c = c->Right;
        }
    }
    c = new BinTreeNode<T>();
    c->Parent = p;
    c->value = key;
    if(IsLess(c->value,p->value))
        p->Left = c;
    else
        p->Right = c;
    return true;
}

template<class T, class H>
T* BinTree<T,H>::PreOrder(const int& n){
    T* res = new T[n];
    std::stack<BinTreeNode<T>*> st;
    BinTreeNode<T>* p = root;
    int i = 0;
    while(!st.empty() || p != nullptr){
        if(p != nullptr){
            res[i++] = p->value;
            if(p->Right){
                st.push(p->Right);
            }
            p = p->Left;
        }else{
            p = st.top();
            st.pop();
        }
    }
    return res;
}

template<class T,class H>
BinTree<T,H>::~BinTree<T, H>(){
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


int* run(int n, const int* arr){
    BinTree<int>* BinTreeRoot = new BinTree<int>();
    for(int i = 0; i < n; i++){
        BinTreeRoot->Add(arr[i]);
    }
    int* res = BinTreeRoot->PreOrder(n);
    delete BinTreeRoot;
    return res;
};



int main(){
    int n = 0;
    std::cin >> n;
    int* arr = new int[n];
    for(int i = 0;i < n;i++){
        std::cin >> arr[i];
    }
    int* res = run(n,arr);
    for(int i = 0; i < n; i++){
        std::cout << res[i] << " ";
    }
    delete[] arr;
    delete[] res;
    return 0;
}