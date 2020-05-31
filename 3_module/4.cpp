#include<array>
#include<cassert>
#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
#include<cstring>
#include <algorithm>

using std::array;
using std::swap;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::queue;
using std::unordered_map;

const int SideSize = 4;
const int FieldSize = SideSize * SideSize;
const array<char, FieldSize> FinishField( { 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,0 } );

class GameState {
public:
    GameState( const array<char, FieldSize>& _field );

    bool CanMoveLeft() const;
    bool CanMoveUp() const;
    bool CanMoveRight() const;
    bool CanMoveDown() const;

    GameState MoveLeft() const;
    GameState MoveUp() const;
    GameState MoveRight() const;
    GameState MoveDown() const;

    bool IsFinish() const;

    bool operator == ( const GameState& state ) const { return field == state.field; }
    bool operator != ( const GameState& state ) const { return !(*this == state); }

    friend ostream& operator << ( ostream& out, const GameState& state );
    friend struct Hasher;

private:
    array<char, FieldSize> field;
    char zeroPos;
};

GameState::GameState( const array<char, FieldSize>& _field ) :
        field( _field ),
        zeroPos( -1 )
{
    for( unsigned int i = 0; i < field.size(); i++ )
        if( field[i] == 0 ) {
            zeroPos = i;
            break;
        }
    assert( zeroPos != -1 );
}

bool GameState::CanMoveLeft() const
{
    return zeroPos % SideSize != 0;
}

bool GameState::CanMoveUp() const
{
    return zeroPos >= SideSize;
}

bool GameState::CanMoveRight() const
{
    return zeroPos % SideSize < SideSize - 1;
}

bool GameState::CanMoveDown() const
{
    return zeroPos < FieldSize - SideSize;
}

GameState GameState::MoveLeft() const
{
    assert( CanMoveLeft() );

    GameState newState( *this );
    swap( newState.field[newState.zeroPos], newState.field[newState.zeroPos - 1] );
    --newState.zeroPos;
    return newState;
}

GameState GameState::MoveUp() const
{
    assert( CanMoveUp() );

    GameState newState( *this );
    swap( newState.field[newState.zeroPos], newState.field[newState.zeroPos - SideSize] );
    newState.zeroPos -= SideSize;
    return newState;
}

GameState GameState::MoveRight() const
{
    assert( CanMoveRight() );

    GameState newState( *this );
    swap( newState.field[newState.zeroPos], newState.field[newState.zeroPos + 1] );
    ++newState.zeroPos;
    return newState;
}

GameState GameState::MoveDown() const
{
    assert( CanMoveDown() );

    GameState newState( *this );
    swap( newState.field[newState.zeroPos], newState.field[newState.zeroPos + SideSize] );
    newState.zeroPos += SideSize;
    return newState;
}


bool GameState::IsFinish() const
{
    return field == FinishField;
}

ostream& operator << ( ostream& out, const GameState& state )
{
    for( int y = 0; y < SideSize; y++ ) {
        for( int x = 0; x < SideSize; x++ ) {
            out << static_cast<int>( state.field[y * SideSize + x] ) << " ";
        }
        out << endl;
    }
    out << endl;
    return out;
}


struct Hasher {
    size_t operator()( const GameState& state ) const {
        size_t hash = 0;
        memcpy( &hash, &state.field[0], sizeof( hash ) );
        return hash;
    }
};

string Get8thSolution( const GameState& state )
{
    queue<GameState> bfsQueue;
    bfsQueue.push( state );
    unordered_map<GameState, char, Hasher> visited;
    visited[state] = 'S';
    bool hasSolution = false;
    while( bfsQueue.size() > 0 ) {
        GameState tempState = bfsQueue.front();
        bfsQueue.pop();
        if( tempState.IsFinish() ) {
            hasSolution = true;
            break;
        }
        if( tempState.CanMoveLeft() ) {
            GameState newState = tempState.MoveLeft();
            if( visited.find( newState ) == visited.end() ) {
                visited[newState] = 'L';
                bfsQueue.push( newState );
            }
        }
        if( tempState.CanMoveUp() ) {
            GameState newState = tempState.MoveUp();
            if( visited.find( newState ) == visited.end() ) {
                visited[newState] = 'U';
                bfsQueue.push( newState );
            }
        }
        if( tempState.CanMoveRight() ) {
            GameState newState = tempState.MoveRight();
            if( visited.find( newState ) == visited.end() ) {
                visited[newState] = 'R';
                bfsQueue.push( newState );
            }
        }
        if( tempState.CanMoveDown() ) {
            GameState newState = tempState.MoveDown();
            if( visited.find( newState ) == visited.end() ) {
                visited[newState] = 'D';
                bfsQueue.push( newState );
            }
        }
    }

    if( !hasSolution ) {
        return string();
    }

    string result;
    GameState tempState( FinishField );
    char move = visited[tempState];
    while( move != 'S' ) {
        result += move;
        switch( move ) {
            case 'L':
                tempState = tempState.MoveRight();
                break;
            case 'U':
                tempState = tempState.MoveDown();
                break;
            case 'R':
                tempState = tempState.MoveLeft();
                break;
            case 'D':
                tempState = tempState.MoveUp();
                break;
            default:
                assert( false );
        }
        move = visited[tempState];
    }

    std::reverse( result.begin(), result.end() );
    return result;
}

int main()
{
    GameState state( { 6,15,1,5,8,12,7,10,14,9,2,4,0,3,13,11 } );
    string solution = Get8thSolution( state );
    for( char direction : solution ) {
        switch( direction ) {
            case 'L':
                state = state.MoveLeft();
                break;
            case 'U':
                state = state.MoveUp();
                break;
            case 'R':
                state = state.MoveRight();
                break;
            case 'D':
                state = state.MoveDown();
                break;
            default:
                assert( false );
        }
        cout << state;
    }
    return 0;
}