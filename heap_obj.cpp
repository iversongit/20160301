 ///
 /// @file    heap_obj.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-01 05:27:59
 ///
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
/*
 *只能生成堆对象，不能生成栈对象，亦即在创建栈
 *对象时，不能调用构造函数或者析构函数
 *
 *将析构函数放入到private区域即可,同时需要在写
 *一个public权限下的destroy成员函数来销毁堆对象
 */
class Onlyheap{
	public:
		Onlyheap();
	//	~Onlyheap();
		void destroy();
		static void* operator new(size_t);
		static void operator delete(void *);
	private:
		~Onlyheap();
		int _id;
		char _name[10];
};

Onlyheap::Onlyheap(){
	cout<<"Onlyheap()"<<endl;
}

Onlyheap::~Onlyheap(){
	cout<<"~Onlyheap()"<<endl;
}

void* Onlyheap::operator new(size_t sz){
	cout<<"operator new(size_t)"<<endl;
	void *pRet = malloc(sz);
	return pRet;
}

void Onlyheap::operator delete(void* pRet){
	cout<<"operator delete(void *)"<<endl;
	free(pRet);
}

void Onlyheap::destroy(){
	cout<<"destroy()"<<endl;
	delete this;
}

int main(void){
//	Onlyheap h1;
	Onlyheap *h2 = new Onlyheap;
	h2->destroy();
	return 0;
}
