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
    TreapNode<T>* root;
    H IsLess;
public:
    Treap():root(nullptr),IsLess(H()){};
    ~
};


template<class T,class Compare = IsLessDefault>
void Split(TreapNode<T>* root, T key,TreapNode<T>*& Left,TreapNode<T>*& Right,Compare IsLess = Compare()){
    if(root == nullptr){
        Left = nullptr;
        Right = nullptr;
    }
    else if(IsLess(root->value,key)){
        Split(root->Right,key, root->Right,Right,IsLess);
        Left = root;
    }else{
        Split(root->Left,key,Left,root->Left);
        Right = root;
    }
}

template<class T>
TreapNode<T>* Merge(TreapNode<T>* Left, TreapNode<T>* Right){
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


template<class T, class Compare = IsLessDefault>
void AddTreapNode(TreapNode<T>*& root, T key,int Priority, Compare IsLess = Compare()){
    TreapNode<T>* newNode = new TreapNode<T>(key,Priority);
    if(root == nullptr) {
        root = newNode;
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
    Split(p,key,newNode->Left,newNode->Right, IsLess);
    if(parent && IsLess(parent->value,key))
        parent->Right = newNode;
    else if (parent && !IsLess(parent->value,key)){
        parent->Left = newNode;
    }else{
        root = newNode;
    }
}

template<class T,class H>
Treap<T,H>::~Treap(){
    std::stack<Tree*> st;
    Tree* p = root;
    while(!st.empty() || p != nullptr){
        if(p!= nullptr){
            if(p->Right){
                st.push(p->Right);
            }
            if(p->Left) {
                Tree* c = p;
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
int height(Tree* node){
    if(node == nullptr)
        return 0;
    int lheight = height(node->Left) + 1;
    int rheight = height(node->Right) + 1;
    return (lheight>rheight?lheight:rheight);
}

template<class Tree>
int levelWidth(Tree* node,int level){
    if(node == nullptr)
        return 0;
    if(level == 1)
        return 1;
    if(level > 1){
        return levelWidth(node->Left,level-1) + levelWidth(node->Right,level-1);
    }
    return 0;
}

template<class Tree>
int MaxWidth(Tree* node){
    if(node == nullptr)
        return 0;
    int cnt = 0;
    int maxWidth = 0;
    int h = height(node);
    for(int i = 0; i < h;i++){
        cnt = levelWidth(node,i);
        maxWidth = (cnt>maxWidth?cnt:maxWidth);
    }
    return maxWidth;
}
int run(int n, const vector<pair<int,int>>& arr){
    BinTreeNode<int>* BinTreeRoot = nullptr;
    TreapNode<int>* TreapTreeRoot = nullptr;
    for(int i = 0; i < n; i++){
        AddBinTreeNode(BinTreeRoot,arr[i].first);
        AddTreapNode(TreapTreeRoot,arr[i].first,arr[i].second);
    }
    int BinTreeWidth = MaxWidth(BinTreeRoot);
    int TreapTreeWidth = MaxWidth(TreapTreeRoot);
    deleteTree(TreapTreeRoot);
    deleteTree(BinTreeRoot);
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