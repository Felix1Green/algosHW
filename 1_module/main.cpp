#include <iostream>
#include <string>
#include <cstring>

using std::string;

int main(){
	string* a = new string[10];
	delete[]a;
	return 0;
}
