 ///
 /// @file    vector.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-01 06:58:04
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

void printVector(std::vector<int> & vecInt){
	cout<<"size of vecInt = "<<vecInt.size()<<endl;
	cout<<"capacity of vecInt = "<<vecInt.capacity()<<endl;
}

int main(void){
	/*vector类似于无限数组，存储空间是动态增长的
	 *每次都是*2
	 */
	std::vector<int> vecInt;
//	vecInt.reserve(50);  //事先开好一个固定大小的空间，减少重新开辟空间
                      	 //移动数据的次数
	vecInt.push_back(1);
	printVector(vecInt);
	vecInt.push_back(2);
	printVector(vecInt);
	vecInt.push_back(3);
	printVector(vecInt);
	vecInt.push_back(4);
	printVector(vecInt);
	vecInt.push_back(5);
	printVector(vecInt);

	
	/*常规数组遍历*/
	int i;
	for(i=0; i<vecInt.size(); ++i){
		cout<<vecInt[i]<<endl;
	}

	cout<<endl;

	/*运用迭代器进行遍历*/
	std::vector<int>::iterator it = vecInt.begin();
	for(;it != vecInt.end(); ++it){
		cout<<*it<<endl;
	}

	cout<<endl;

	/*C++11新功能：自动遍历*/
	for(auto elem : vecInt){
		cout<<elem<<endl;
	}

	return 0;
}
