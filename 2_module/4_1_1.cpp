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
        else
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


template<class T,class H = IsLessDefault<T>>
class AvlTree{
public:
    AvlTreeNode<T>* root;
    AvlTree(H Less = H()):root(nullptr),IsLess(Less){};
    unsigned int findKey(const T& key);
    bool insertKey(const T& key);
    bool deleteKey(T key);
    ~AvlTree();
private:
    H IsLess;
    unsigned int Height(AvlTreeNode<T>* node);
    int diffFactor(AvlTreeNode<T>* node);
    unsigned int NewHeight(AvlTreeNode<T>* node);
    unsigned int cElements(AvlTreeNode<T>* node);
    AvlTreeNode<T>* AvlInsert(AvlTreeNode<T>* node,const T& key);
    AvlTreeNode<T>* AvlDelete(AvlTreeNode<T>* node,T key);
    AvlTreeNode<T>* RightSmall(AvlTreeNode<T>* node);
    AvlTreeNode<T>* LeftSmall(AvlTreeNode<T>* node);
    AvlTreeNode<T>* RightBig(AvlTreeNode<T> *node );
    AvlTreeNode<T>* LeftBig(AvlTreeNode<T>* node);
    AvlTreeNode<T>* balance(AvlTreeNode<T>* node);
    AvlTreeNode<T>* FindAndRemoveMax(AvlTreeNode<T>* p);
    AvlTreeNode<T>* FindAndRemoveMin(AvlTreeNode<T>* p);
};

template<class T, class H>
unsigned int AvlTree<T,H>::Height(AvlTreeNode<T>* node){
    return node?node->height:0;
}


template<class T,class H>
int AvlTree<T,H>::diffFactor(AvlTreeNode<T>* node){
    int hl = Height(node->left);
    int hr = Height(node->right);
    return hr - hl;
}

template<class T,class H>
unsigned int AvlTree<T,H>::NewHeight(AvlTreeNode<T>* node){
    node->height = std::max(Height(node->left),Height(node->right)) + 1;
    return node->height;
}

template<class T,class H>
unsigned int AvlTree<T,H>::cElements(AvlTreeNode<T>* node){
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

template<class T,class H>
AvlTreeNode<T>* AvlTree<T,H>::RightSmall(AvlTreeNode<T>* node){
    AvlTreeNode<T>* left = node->left;
    node->left = left->right;
    left->right = node;
    NewHeight(node);
    cElements(node);
    NewHeight(left);
    cElements(left);
    return left;
}

template<class T,class H>
AvlTreeNode<T>* AvlTree<T,H>::LeftSmall(AvlTreeNode<T>* node){
    AvlTreeNode<T>* right = node->right;
    node->right = right->left;
    right->left = node;
    NewHeight(node);
    cElements(node);
    NewHeight(right);
    cElements(right);
    return right;
}

template<class T,class H>
AvlTreeNode<T>* AvlTree<T,H>::RightBig(AvlTreeNode<T>* node){
    if(diffFactor(node->left) > 0)
        node->left = LeftSmall(node->left);
    return RightSmall(node);
}

template<class T,class H>
AvlTreeNode<T>* AvlTree<T,H>::LeftBig(AvlTreeNode<T>* node){
    if(diffFactor(node->right) < 0)
        node->right = RightSmall(node->right);
    return LeftSmall(node);
}

template<class T,class H>
AvlTreeNode<T>* AvlTree<T,H>::balance(AvlTreeNode<T>* node){
    NewHeight(node);
    cElements(node);
    if(diffFactor(node) == 2){
        return LeftBig(node);
    }else if(diffFactor(node) == -2){
        return RightBig(node);
    }
    return node;
}



template<class T,class H>
bool AvlTree<T,H>::insertKey(const T& key){
    root = AvlInsert(root,key);
    if(root)
        return true;
    return false;
}

template<class T, class H>
AvlTreeNode<T>* AvlTree<T,H>::AvlInsert(AvlTreeNode<T>*node,const T& key) {
    if(!node) {
        return new AvlTreeNode<T>(key);
    }if(IsLess(key,node->value) == 1){
        node->left = AvlInsert(node->left,key);
    }else if(IsLess(key,node->value) == 2){
        node->right = AvlInsert(node->right,key);
    }else{
        assert(false);
    }
    return balance(node);
}

template<class T,class H>
AvlTreeNode<T>* AvlTree<T,H>::FindAndRemoveMin(AvlTreeNode<T>* p){
    std::stack<AvlTreeNode<T>*> st;
    while(p->left != nullptr) {
        st.push(p);
        p = p->left;
    }
    while(!st.empty()){
        AvlTreeNode<T>* tmp = st.top();st.pop();
        p->right = balance(tmp);
    }
    return p;
}


template<class T,class H>
AvlTreeNode<T>* AvlTree<T,H>::FindAndRemoveMax(AvlTreeNode<T>* p){
    std::stack<AvlTreeNode<T>*> st;
    while(p->right != nullptr) {
        st.push(p);
        p = p->right;
    }
    while(!st.empty()){
        AvlTreeNode<T>* tmp = st.top();st.pop();
        p->left = balance(tmp);
    }
    return p;
}


template<class T,class H>
AvlTreeNode<T>* AvlTree<T,H>::AvlDelete(AvlTreeNode<T>*node,T key) {
    if(!node)
        return nullptr;
    if(node->right && key < node->right->ElementsCnt + 1){
        node->right = AvlDelete(node->right,key);
    }else if((node->right && key > node->right->ElementsCnt+1)||(!node->right && key > 0)){
        key -= (node->right?node->right->ElementsCnt + 2:1);
        node->left = AvlDelete(node->left,key);
    }
    else{
        AvlTreeNode<T>* left = node->left;
        AvlTreeNode<T>* right = node->right;
        delete node;
        if(!right)
            return left;
        if(Height(left) > Height(right)){
            AvlTreeNode<T>* p = FindAndRemoveMax(left);
            p->right = right;
            return balance(p);
        }else{
            AvlTreeNode<T>* p = FindAndRemoveMin(right);
            p->left = left;
            return balance(p);
        }
    }
    return balance(node);
}



template<class T,class H>
bool AvlTree<T,H>::deleteKey(T key){
    root = AvlDelete(root,key);
    if(root)
        return true;
    return false;
}

template<class T,class H>
unsigned int AvlTree<T,H>::findKey(const T& key){
    int ans = 0;
    AvlTreeNode<T>* p = root;
    while(p != nullptr && IsLess(key,p->value) != 0){
        if(IsLess(key,p->value) == 1){
            ans += (p->right?p->right->ElementsCnt + 2:1);
            p = p->left;
        }else{
            p = p->right;
        }
    }
    ans += (p&&p->right?p->right->ElementsCnt + 1:0);
    return ans;
}


template<class T,class H>
AvlTree<T,H>::~AvlTree(){
    while(root != nullptr){
        deleteKey(0);
    }
    delete root;
}


void run(){
    int n = 0;
    std::cin >> n;
    AvlTree<int>* Root = new AvlTree<int>();
    for(int i = 0 ; i < n; i++){
        int command;
        int value = 0;
        std::cin >> command >> value;
        switch(command){
            case 1:
                Root->insertKey(value);
                std::cout << Root->findKey(value) << std::endl;
                break;
            case 2:
                Root->deleteKey(value);
                break;
            default:
                assert(false);
        }
    }delete Root;
}



int main(){
    run();
    return 0;
}