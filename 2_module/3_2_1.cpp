#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;


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
    BinTreeNode<T>* getRoot();
    ~BinTree();
};

template<class T,class H>
BinTreeNode<T>* BinTree<T,H>::getRoot(){
    return root;
}


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


template<class T>
struct TreapNode {
    T value;
    int priority;
    TreapNode *Left;
    TreapNode *Right;
public:
    TreapNode() : value(0),priority(0), Left(nullptr), Right(nullptr) {};
    TreapNode(T _value, int _priority):value(_value),priority(_priority),Left(nullptr),Right(nullptr){};
};

template<class T,class H = IsLessDefault>
class Treap{
    H IsLess;
    TreapNode<T>* root;
public:
    TreapNode<T>* getRoot();
    Treap():root(nullptr),IsLess(H()){};
    void Split(TreapNode<T>* node, T key,TreapNode<T>*& Left,TreapNode<T>*& Right);
    TreapNode<T>* Merge(TreapNode<T>* Left, TreapNode<T>* Right);
    void AddTreapNode(T key,int Priority);
    ~Treap();
};

template<class T,class H>
TreapNode<T>* Treap<T,H>::getRoot(){
    return root;
}

template<class T,class H>
void Treap<T,H>::Split(TreapNode<T>* node, T key,TreapNode<T>*& Left,TreapNode<T>*& Right){
    if(node == nullptr){
        Left = nullptr;
        Right = nullptr;
    }
    else if(IsLess(node->value,key)){
        Split(node->Right,key, node->Right,Right);
        Left = node;
    }else{
        Split(node->Left,key,Left,node->Left);
        Right = node;
    }
}

template<class T,class H>
TreapNode<T>* Treap<T,H>::Merge(TreapNode<T>* Left, TreapNode<T>* Right){
    if(Left == nullptr || Right == nullptr)
        return (Left == nullptr?Right:Left);
    if(Left->priority > Right->priority){
        Left->Right = Merge(Left->Right,Right);
        return Left;
    }else{
        Right->Left = Merge(Left,Right->Left);
        return Right;
    }
}


template<class T, class H>
void Treap<T,H>::AddTreapNode(T key,int Priority){
    TreapNode<T>* newroot = new TreapNode<T>(key,Priority);
    if(root == nullptr) {
        root = newroot;
        return;
    }
    TreapNode<T>* p = root;
    TreapNode<T>* parent = nullptr;
    while(p && p->priority > Priority){
        if(IsLess(p->value,key)){
            parent = p;
            p = p->Right;
        }else{
            parent = p;
            p = p->Left;
        }
    }
    Split(p,key,newroot->Left,newroot->Right);
    if(parent && IsLess(parent->value,key))
        parent->Right = newroot;
    else if (parent && !IsLess(parent->value,key)){
        parent->Left = newroot;
    }else{
        root = newroot;
    }
}

template<class T,class H>
Treap<T,H>::~Treap<T, H>() {
    std::stack<TreapNode<T>*> st;
    TreapNode<T>* p = root;
    while(!st.empty() || p != nullptr){
        if(p!= nullptr){
            if(p->Right){
                st.push(p->Right);
            }
            if(p->Left) {
                TreapNode<T>* c = p;
                p = p->Left;
                delete c;
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

template<class Tree>
int MaxWidth(Tree* root){
    if (root == nullptr)
        return 0;
    int result = 0;
    queue<Tree*> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size() ;
        result = std::max(count, result);
        for(;count > 0; count--){
            Tree *tmp = q.front();
            q.pop();
            if (tmp->Left != nullptr)
                q.push(tmp->Left);
            if (tmp->Right != nullptr)
                q.push(tmp->Right);
        }
    }
    return result;
}


int run(int n, const vector<pair<int,int>>& arr){
    BinTree<int>* BinTreeRoot = new BinTree<int>;
    Treap<int>* TreapTreeRoot = new Treap<int>;
    for(int i = 0; i < n; i++){
        BinTreeRoot->Add(arr[i].first);
        TreapTreeRoot->AddTreapNode(arr[i].first,arr[i].second);
    }
    int BinTreeWidth = MaxWidth(BinTreeRoot->getRoot());
    int TreapTreeWidth = MaxWidth(TreapTreeRoot->getRoot());
    delete TreapTreeRoot;
    delete BinTreeRoot;
    return (TreapTreeWidth - BinTreeWidth);
};



int main(){
    int n = 0;
    std::cin >> n;
    vector<pair<int,int>> arr;
    for(int i = 0;i < n;i++){
        pair<int,int> a;
        std::cin >> a.first >> a.second;
        arr.push_back(a);
    }
    int res = run(n,arr);
    std::cout << res << std::endl;
    return 0;
}