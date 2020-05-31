#include <iostream>
#include <vector>
#include <cassert>
#define FIND_CONST 53
#define HASH_CONST 61
using std::vector;


template<class T>
struct HashTableNode{
    T key;
    int type;
    HashTableNode():key(""),type(0){};
    HashTableNode(const T& _key,const int& _type):key(_key),type(_type){};
};


template<typename T, class H>
class HashTable{
public:
    HashTable(const int& size = 8, const H& hasher = H());
    bool Add(const T&  _key);
    bool Delete(const T& _key);
    bool Contains(const T& _key,int hash);
private:
    H HashFunction;
    vector< HashTableNode<T> > table;
    unsigned int KeysCount;
    void GrowTable();
};
template<typename T, class H>
HashTable<T,H>::HashTable(const int& size,const H& hasher):
    KeysCount(0),
    table(size,HashTableNode<T>()),
    HashFunction(hasher)
{};


template<typename T, class H>
bool HashTable<T,H>::Add(const T& _key) {
    if (4*(KeysCount+1) > 3 * table.size()) {
        GrowTable();
    }
    unsigned int hash = HashFunction(_key) % table.size();
    if (Contains(_key,hash))
        return false;
    int cnt = 1;
    while (table[hash].type != 0 && table[hash].type != -1 && cnt < table.size()) {
        hash = (hash + cnt*cnt*(FIND_CONST))%table.size();
        cnt++;
    }
    if(cnt == table.size())
        return false;
    table[hash].key = _key;
    table[hash].type = 1;
    KeysCount++;
    return true;
}

template<typename T, class H>
bool HashTable<T,H>::Delete(const T& _key){
    unsigned int hash = HashFunction(_key)%table.size();
    int cnt = 1;
    while(table[hash].type != 0 && !(table[hash].type == 1 && table[hash].key == _key) && cnt< table.size()){
        hash = (hash + cnt*cnt*FIND_CONST)%table.size();
        cnt++;
    }
    if(table[hash].type == 1 && table[hash].key == _key){
        table[hash].type =-1;
        KeysCount--;
        return true;
    }
    return false;
}

template<typename T,class H>
bool HashTable<T,H>::Contains(const T& _key,int hash){
    int i = 1;
    while(table[hash].type != 0 && !(table[hash].type == 1 && table[hash].key == _key) && i< table.size()){
        hash = (hash + i*i*FIND_CONST)%table.size();
        i++;
    }
    return !(table[hash].type == 0 || i >= table.size());
}

template <class T,class H>
void HashTable<T,H>::GrowTable() {
    vector< HashTableNode<T> > newtable(table.size()*2,HashTableNode<T>());
    for(int i = 0; i < table.size();i++){
        if(table[i].type > 0) {
            unsigned int hash = HashFunction(table[i].key)%newtable.size();
            int cnt = 1;
            while (newtable[hash].type != 0 && newtable[hash].type != -1 && cnt < newtable.size()) {
                hash = (hash + cnt*cnt*(FIND_CONST))%newtable.size();
                cnt++;
            }
            newtable[hash].key = table[i].key;
            newtable[hash].type = 1;
        }
    }
    table = newtable;
}

class StringHasher {
public:
    unsigned int operator()(const std::string &_key) {
        unsigned hash = 0;
        for(int i = _key.size(); i >= 0; i--){
            hash += _key[i] + hash*HASH_CONST;
         }
        return hash;
    }
};


void run(){
    HashTable<std::string,StringHasher> set;
    char key = ' ';
    std::string str("asd");
    while(std::cin >> key >> str){
        switch(key){
            case '+': std::cout << (set.Add(str)?"OK":"FAIL") << std::endl;
                break;
            case '-': std::cout << (set.Delete(str)?"OK":"FAIL")<< std::endl;
                break;
            case '?': std::cout << (set.Contains(str)?"OK":"FAIL") << std::endl;
                break;
            default: assert(false);
        }
    }
}


int main(){
    run();
    return 0;
}