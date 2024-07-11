#include <iostream>
#include "header1.h"
#include "header2.h"

using namespace header1;
using namespace std;

int main() {
	cout << "Hello, World!!!" << endl;
	return 0;

	foo();					//header1
	bar();					//header1
	header2::foo();				//header2
	header2::bar();				//header2
}
