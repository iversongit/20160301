 ///
 /// @file    stack_obj.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-01 05:27:59
 ///
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
/*
 *只能生成栈对象，不能生成堆对象，亦即不能通过
 *new表达式来生成对象
 *
 *将operator new函数放入到private区域即可
 */
class Onlystack{
	public:
		Onlystack();
		~Onlystack();
	
	private:
		static void* operator new(size_t);
		static void operator delete(void *);
	#if 0
		static void* operator new(size_t sz){
			cout<<"operator new(size_t)"<<endl;
			void *pRet = malloc(sz);
			return pRet;
		}

		static void operator delete(void* pRet){
			cout<<"operator delete(void *)"<<endl;
			free(pRet);
		}
	#endif
		int _id;
		char _name[10];
};

Onlystack::Onlystack(){
	cout<<"Onlystack()"<<endl;
}

Onlystack::~Onlystack(){
	cout<<"~Onlystack()"<<endl;
}

void* Onlystack::operator new(size_t sz){
	cout<<"operator new(size_t)"<<endl;
	void *pRet = malloc(sz);
	return pRet;
}

void Onlystack::operator delete(void* pRet){
	cout<<"operator delete(void *)"<<endl;
	free(pRet);
}


int main(void){
	Onlystack o1;
//	Onlystack *o2 = new Onlystack;
//	delete o2;
	return 0;
}
