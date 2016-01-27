
#include <iostream>     // std::cout
#include <string>

#include "FileAccess.h"

using namespace std;

int main(){
	cout << "FileAccessTest" << endl;

	FileAccess fa("localhost", 10030);
	fa.Upload("test", "1.txt", 0);
	fa.Download("test", "2.txt", 0);
	fa.IsFileAlive("test", "1.txt", 0);
	
	//FileAccess::AccessToken access = fa.GetUserToken("early",0);
	//cout << access.token1;

	return 0;
}