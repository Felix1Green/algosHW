#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <queue>
#include <unordered_map>


using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::unordered_map;

const int SideSize = 4;
const int FieldSize = SideSize*SideSize;
const vector<char> WinState{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};

class State{
public:
    State(const vector<char>& tmp);
    State(const State& tmp);

    int findDistance()const ;

    bool MoveRightAbility() const;
    bool MoveDownAbility() const;
    bool MoveUpAbility() const;
    bool MoveLeftAbility() const;
    State MoveRight()const;
    State MoveDown()const;
    State MoveLeft()const;
    State MoveUp()const;

    State& operator=(const State& state) = default;
    bool operator ==(const State& state)const {return field == state.field;}
    bool operator !=(const State& state)const {return !(*this == state);}
    bool operator <(const State& state)const{return findDistance() > state.findDistance();}

    friend class Hasher;
    friend bool ResolveAbility(const State& state);
private:
    vector<char> field;
    char zeroCoord;
};

State::State(const vector<char>& tmp):field(tmp.size()){
    for(int i = 0; i < tmp.size(); i++){
        field[i] = tmp[i];
        if(tmp[i] == 0)
            zeroCoord = i;
    }
}

State::State(const State &tmp) {
    (*this) = tmp;
}

int State::findDistance() const {
    int distance = 0;
    for (size_t i = 0; i < FieldSize; i++) {
        if (field[i]) {
            distance += (abs(i % SideSize - (field[i] - 1) % SideSize) + abs(i / SideSize - (field[i] - 1) / SideSize));
        }
    }
    return distance;
}

bool State::MoveDownAbility() const {
    return zeroCoord > SideSize;
}

bool State::MoveLeftAbility() const {
    return zeroCoord %SideSize != SideSize-1;
}

bool State::MoveRightAbility() const {
    return zeroCoord %SideSize != 0;
}

bool State::MoveUpAbility() const {
    return zeroCoord <FieldSize - SideSize;
}

State State::MoveUp() const{
    assert(MoveUpAbility());
    State newState(*this);
    std::swap(newState.field[zeroCoord],newState.field[zeroCoord+SideSize]);
    newState.zeroCoord +=SideSize;
    return newState;
}

State State::MoveRight() const{
    assert(MoveRightAbility());
    State newState(*this);
    std::swap(newState.field[zeroCoord],newState.field[zeroCoord - 1]);
    newState.zeroCoord--;
    return newState;
}

State State::MoveLeft() const{
    assert(MoveLeftAbility());
    State newState(*this);
    std::swap(newState.field[zeroCoord],newState.field[zeroCoord+1]);
    newState.zeroCoord++;
    return newState;
}

State State::MoveDown() const{
    assert(MoveDownAbility());
    State newState(*this);
    std::swap(newState.field[zeroCoord],newState.field[zeroCoord - SideSize]);
    newState.zeroCoord-=SideSize;
    return newState;
}


class Hasher{
public:
    size_t operator()(const State & state) const{
        size_t hash = 0;
        memcpy(&hash,&state.field[0],sizeof(hash));
        return hash;
    }
};

bool ResolveAbility(const State& state){
    int inv = 0;
    for(int i = 0; i < FieldSize;i++){
        if(state.field[i]){
            for(int j = 0; j < i; j++){
                inv += state.field[j]>state.field[i]?1:0;
            }
        }
    }
    inv += 1 + state.zeroCoord/4;
    return inv % 2 == 0;
}

std::string Resolver(const vector<char>& field){
    priority_queue<State> q;
    unordered_map<State,std::string,Hasher> visited;
    const State StartState(field);
    if(!ResolveAbility(StartState)){
        return "";
    }
    visited[StartState] = "";
    q.emplace(StartState);
    State completed(WinState);
    while(q.top() != completed){
        State curState = q.top();q.pop();
        if(curState.MoveLeftAbility()) {
            State leftState = curState.MoveLeft();
            if(visited.find(leftState) == visited.end()) {
                q.emplace(leftState);
                visited[leftState] = visited[curState] + "L";
            }
        }
        if(curState.MoveRightAbility()) {
            State rightState = curState.MoveRight();
            if(visited.find(rightState) == visited.end()) {
                q.emplace(rightState);
                visited[rightState] = visited[curState] + "R";
            }
        }
        if(curState.MoveUpAbility()) {
            State upState = curState.MoveUp();
            if( visited.find(upState) == visited.end() ) {
                q.emplace(upState);
                visited[upState] = visited[curState] + "U";
            }
        }
        if(curState.MoveDownAbility()) {
            State downState = curState.MoveDown();
            if( visited.find(downState) == visited.end() ) {
                q.emplace(downState);
                visited[downState] = visited[curState] + "D";
            }
        }
    }
    return visited[completed];
}

int main(){
    vector<char> arr(FieldSize);
    int s = 0;
    for(int i = 0; i < FieldSize; i++){
        cin >> s;
        arr[i] = s;
    }
    std::string solution = Resolver(arr);
    if(solution.empty()){
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << solution.size() << std::endl;
    for(char j : solution){
        std::cout << j;
    }
    return 0;
}