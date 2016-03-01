 ///
 /// @file    iostream_2.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-01 06:36:48
 ///
 
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

int main(void){
	ifstream ifs("iostream_1.cpp");
	if(!ifs.good()){
		cout<<"open file error"<<endl;
		return -1;
	}

	string s;
	while(getline(ifs,s)){
		cout<<s<<endl;
	}

	return 0;
}
