#include <vector>
#include <iostream>
#include <cassert>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <algorithm>

using std::vector;
using std::queue;
using std::cin;
using std::cout;
using std::unordered_map;
using std::pair;

const int SideSize = 4;
const int FieldSize = SideSize*SideSize;
const vector<char> WinState{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};


class State{
public:
    State(const vector<char>& tmp);
    State(const State& state);
    bool MoveRightAbility() const;
    bool MoveDownAbility() const;
    bool MoveUpAbility() const;
    bool MoveLeftAbility() const;
    State MoveRight()const;
    State MoveDown()const;
    State MoveLeft()const;
    State MoveUp()const;
    int findDistance() const;
    bool operator == ( const State& state ) const { return field == state.field; }
    bool operator != ( const State& state ) const { return field != state.field; }
    bool operator <(const State& state) const {return findDistance() > state.findDistance();}
    State& operator=(const State& state) = default;
    bool isFinish() const;
    friend class Hasher;
    friend bool ResolveAbility(State state);
private:
    vector<char> field;
    char zeroCoord;
};

State::State(const State &state) {
    *this = state;
}


State::State(const vector<char> &tmp):field(tmp),zeroCoord(0) {
    for(int i = 0 ; i < tmp.size(); i++){
        if(tmp[i] == 0) {
            zeroCoord = i;
            break;
        }
    }
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
    return zeroCoord < FieldSize - SideSize;
}

bool State::MoveLeftAbility() const {
    return zeroCoord %SideSize != 0;
}

bool State::MoveRightAbility() const {
    return zeroCoord %SideSize < SideSize-1;
}

bool State::MoveUpAbility() const {
    return zeroCoord > SideSize-1;
}

State State::MoveUp() const{
    assert(MoveUpAbility());
    State newState(*this);
    std::swap(newState.field[zeroCoord],newState.field[zeroCoord+SideSize]);
    newState.zeroCoord -=SideSize;
    return newState;
}

State State::MoveRight() const{
    assert(MoveRightAbility());
    State newState(*this);
    std::swap(newState.field[zeroCoord],newState.field[zeroCoord - 1]);
    newState.zeroCoord+=1;
    return newState;
}

State State::MoveLeft() const{
    assert(MoveLeftAbility());
    State newState(*this);
    std::swap(newState.field[zeroCoord],newState.field[zeroCoord+1]);
    newState.zeroCoord-=1;
    return newState;
}

State State::MoveDown() const{
    assert(MoveDownAbility());
    State newState(*this);
    std::swap(newState.field[zeroCoord],newState.field[zeroCoord - SideSize]);
    newState.zeroCoord +=SideSize;
    return newState;
}

bool State::isFinish() const {
    return field == WinState;
}


class Hasher{
public:
    size_t operator()(const State & state) const{
        size_t hash = 0;
        memcpy(&hash,&state.field[0],sizeof(hash));
        return hash;
    }
};


bool ResolveAbility(State state){
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


std::string Resolver(const State& startState, const vector<char>& field){
    std::unordered_map<State, std::string, Hasher> visited;
    std::priority_queue<State> queue;
    queue.push(startState);
    visited[startState] = "";

    State completed(WinState);
    while (queue.top() != completed) {
        State currentState = queue.top();
        queue.pop();

        if(currentState.MoveLeftAbility()) {
            State leftState = currentState.MoveLeft();
            if(visited.find(leftState) == visited.end()) {
                queue.push(leftState);
                visited[leftState] = visited[currentState] + "L";
            }
        }
        if(currentState.MoveRightAbility()) {
            State rightState = currentState.MoveRight();
            if(visited.find(rightState) == visited.end()) {
                queue.push(rightState);
                visited[rightState] = visited[currentState] + "R";
            }
        }
        if(currentState.MoveUpAbility()) {
            State upState = currentState.MoveUp();
            if( visited.find(upState) == visited.end() ) {
                queue.push(upState);
                visited[upState] = visited[currentState] + "U";
            }
        }
        if(currentState.MoveDownAbility()) {
            State downState = currentState.MoveDown();
            if( visited.find(downState) == visited.end() ) {
                queue.push(downState);
                visited[downState] = visited[currentState] + "D";
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
    }State tmp(arr);

    if(!ResolveAbility(tmp)){
        cout << -1 << std::endl;
        return 0;
    }

    std::string solution = Resolver(tmp,arr);
    if(solution.empty()){
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << solution.size() << std::endl;
    for(char j : solution){
        std::cout << j << std::endl;
    }
    return 0;
}
