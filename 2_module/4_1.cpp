#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <stack>

template<class T>
class IsLessDefault{
public:
    int operator ()(const T& a, const T& b){
        if(a == b)
            return 0;
        if(a < b)
            return 1;
        if(a > b)
            return 2;
    }
};


template<class T>
struct AvlTreeNode {
    T value;
    unsigned int height;
    unsigned int ElementsCnt;
    AvlTreeNode* left;
    AvlTreeNode* right;
    AvlTreeNode(T key):value(key),left(nullptr),right(nullptr),height(1),ElementsCnt(0){};
};


template<class T>


template<class T>
unsigned int Height(AvlTreeNode<T>* node){
    return node?node->height:0;
}


template<class T>
int diffFactor(AvlTreeNode<T>* node){
    unsigned int hl = Height(node->left);
    unsigned int hr = Height(node->right);
    return hr - hl;
}

template<class T>
unsigned int NewHeight(AvlTreeNode<T>* node){
    node->height = std::max(Height(node->left),Height(node->right)) + 1;
    return node->height;
}

template<class T>
unsigned int cElements(AvlTreeNode<T>* node){
    if(!node){
        return 0;
    }
    node->ElementsCnt = 0;
    if(node->left){
        node->ElementsCnt += node->left->ElementsCnt + 1;
    }
    if(node->right){
        node->ElementsCnt += node->right->ElementsCnt + 1;
    }
    return node->ElementsCnt;
}

template<class T>
AvlTreeNode<T>* RightSmall(AvlTreeNode<T>* node){
    AvlTreeNode<T>* left = node->left;
    node->left = left->right;
    left->right = node;
    NewHeight(node);
    cElements(node);
    NewHeight(left);
    cElements(left);
    return left;
}

template<class T>
AvlTreeNode<T>* LeftSmall(AvlTreeNode<T>* node){
    AvlTreeNode<T>* right = node->right;
    node->right = right->left;
    right->left = node;
    NewHeight(node);
    cElements(node);
    NewHeight(right);
    cElements(right);
    return right;
}

template<class T>
AvlTreeNode<T>* RightBig(AvlTreeNode<T>* node){
    if(diffFactor(node->left) > 0)
        node->left = LeftSmall(node->left);
    return RightSmall(node);
}

template<class T>
AvlTreeNode<T>* LeftBig(AvlTreeNode<T>* node){
    if(diffFactor(node->right) < 0)
        node->right = RightSmall(node->right);
    return LeftSmall(node);
}

template<class T>
AvlTreeNode<T>* balance(AvlTreeNode<T>* node){
    NewHeight(node);
    cElements(node);
    if(diffFactor(node) == 2){
        return LeftBig(node);
    }else if(diffFactor(node) == -2){
        return RightBig(node);
    }
    return node;
}



template<class T, class Compare = IsLessDefault<T>>
AvlTreeNode<T>* insertKey(T key,AvlTreeNode<T>* node,Compare IsLess = Compare()){
    if(!node) {
        return new AvlTreeNode<T>(key);
    }if(IsLess(key,node->value) == 1){
        node->left = insertKey(key,node->left);
    }else if(IsLess(key,node->value) == 2){
        node->right = insertKey(key,node->right);
    }else{
        assert(false);
    }
    return balance(node);
}


template <class T>
AvlTreeNode<T>* findMin(AvlTreeNode<T>* node){
    AvlTreeNode<T>* p = node;
    while(p->left != nullptr){
        p = p->left;
    }
    return p;
}

template<class T>
AvlTreeNode<T>* deleteMin(AvlTreeNode<T>* node){
    if(node->left == nullptr) {
        return node->right;
    }
    node->left = deleteMin(node->left);
    return balance(node);
}


template<class T>
AvlTreeNode<T>* deleteKey(T key,AvlTreeNode<T>* node){
    if(!node)
        return nullptr;
    if(node->right && key < node->right->ElementsCnt + 1){
        node->right = deleteKey(key,node->right);
    }else if((node->right && key > node->right->ElementsCnt+1)||(!node->right && key > 0)){
        key -= (node->right?node->right->ElementsCnt + 2:1);
        node->left = deleteKey(key,node->left);
    }
    else{
        AvlTreeNode<T>* left = node->left;
        AvlTreeNode<T>* right = node->right;
        delete node;
        if(!right)
            return left;
        AvlTreeNode<T>* p = findMin(right);
        p->right = deleteMin(right);
        p->left = left;
        return balance(p);
    }
    return balance(node);
}

template<class T,class Compare = IsLessDefault<T>>
unsigned int findKey(AvlTreeNode<T>* node,T key, Compare IsLess = Compare()){
    int ans = 0;
    AvlTreeNode<T>* p = node;
    while(p != nullptr && IsLess(key,p->value) != 0){
        if(IsLess(key,p->value) == 1){
            ans += (p->right?p->right->ElementsCnt + 2:1);
            p = p->left;
        }else{
            p = p->right;
        }
    }
    ans += (p->right?p->right->ElementsCnt + 1:0);
    return ans;
}


template<class T>
void deleteTree(AvlTreeNode<T>* root){
    while(root != nullptr){
        root = deleteKey(0,root);
    }
    delete root;
}


void run(){
    int n = 0;
    std::cin >> n;
    AvlTreeNode<int>* Root = nullptr;
    for(int i = 0 ; i < n; i++){
        int command;
        int value = 0;
        std::cin >> command >> value;
        switch(command){
            case 1:
                Root = insertKey(value,Root);
                std::cout << findKey(Root,value) << std::endl;
                break;
            case 2:
                Root = deleteKey(value,Root);
                break;
            default:
                assert(false);
        }
    }
    deleteTree(Root);
}



int main(){
    run();
    return 0;
}