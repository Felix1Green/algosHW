#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <stack>

using std::priority_queue;
using std::vector;

typedef unsigned char byte;

struct IInputStream {
    bool Read(byte& value){
        if(!std::cin.eof()) {
            std::cin >> value;
            return true;
        }
        return false;
    }
};

struct IOutputStream {
    void Write(byte value){
        std::cout << value;
    }
};


struct HuffNode{
public:
    HuffNode():priority(0),value(0),left(nullptr),right(nullptr){};
    HuffNode(int count,byte _value):priority(count),value(_value),left(nullptr),right(nullptr){};
    HuffNode(HuffNode* left, HuffNode*right);
    int priority;
    HuffNode* left;
    HuffNode* right;
    byte value;
};

HuffNode::HuffNode(HuffNode *_left, HuffNode *_right):value(0),left(_left),right(_right){
    priority = left->priority + right->priority;
}

bool operator <(const HuffNode& a, const HuffNode& b){
    return a.priority > b.priority;
}

void toTable(HuffNode* root,vector<vector<char>>& table, vector<char> comress_code){
    if(!root)
        return;
    if(root->left){
        comress_code.push_back('0');
        toTable(root->left,table,comress_code);
    }if(root->right){
        comress_code.push_back('1');
        toTable(root->right,table,comress_code);
    }
    if(root->value) {
        table[int(root->value)] = comress_code;
        comress_code.pop_back();
    }
}

void encodeTree(HuffNode* root,std::string& raw){
    if(root->value){
        raw += '1';
        raw += root->value;
    }else{
        raw += '0';
        encodeTree(root->left,raw);
        encodeTree(root->right,raw);
    }
}

HuffNode* decodeTree(const std::string raw){
    for(int i = 0; i < raw.size();i++){
        std::cout << raw[i];
        if(int(raw[i]) == int('1')){
            return new HuffNode(0,raw[i+1]);
        }else{
            HuffNode* left = decodeTree(raw.substr(i+1,raw.size()));
            HuffNode* right = decodeTree(raw.substr(i+1,raw.size()));
            return new HuffNode(left,right);
        }
    }
    return nullptr;
}



void Encode(IInputStream & original,IOutputStream & compressed){
    const int Range = 256;
    int cnt[Range];
    std::string raw_data;
    memset(cnt,0,Range*sizeof(int));
    byte value;
    priority_queue<HuffNode*> q;
    while(original.Read(value)){
        raw_data += value;
        cnt[int(value)] +=1;
    }
    for(int i = 0; i < Range;i++){
        if(cnt[i] != 0){
            HuffNode* newNode = new HuffNode(cnt[i],i);
            q.push(newNode);
        }
    }
    while(q.size() != 1){
        HuffNode* left = q.top();
        q.pop();
        HuffNode* right = q.top();
        q.pop();
        HuffNode* p = new HuffNode(left,right);
        q.push(p);
    }
    vector<vector<char>> table(Range);
    vector<char>compress_code;
    HuffNode* root = q.top();q.pop();
    toTable(root,table,compress_code);
    std::string raw_tree = "";
    encodeTree(root,raw_tree);
    for(auto i:raw_tree)
        compressed.Write(i);
    compressed.Write(' ');
    for(auto i:raw_data){
        for(auto j : table[int(i)])
            compressed.Write(j);
    }
}

void Decode(IInputStream & compressed,IOutputStream & original){
    const int Range = 256;
    std::string raw_data;
    byte value;
    while(compressed.Read(value) && value != '/'){
        raw_data += value;
    }
    HuffNode* root = decodeTree(raw_data);
    vector<vector<char>> table(Range);
    vector<char>compress_code;
    toTable(root,table,compress_code);
    std::string answer;
    vector<char> code;
    while(compressed.Read(value)){
        code.push_back(value);
        for(int i = 0; i < Range;i++){
            if(table[i] == code){
                answer += char(i);
                code.clear();
            }
        }
    }
    std::cout << answer.size() << std::endl;
    for(auto j : answer){
        original.Write(j);
    }
}

int main(){
    IInputStream in;
    IOutputStream out;
    Decode(in,out);
    return 0;
}