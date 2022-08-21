#include<iostream>
using namespace std;
//这是针对今天的问题，面试官说是4个字节，但是我在这边看到的是1个字节，没有padding，奇怪
class A{
public:
	virtual void foo(){};
public:
	//static A origin;
	int first;
	int second;
	int third;
};
int main(void){
	A a;
	//float A::*px = &A::third;
	float A::*px = nullptr;
	int A::*pz = &A::third;
	printf("nullptr = %p\n", px);
	printf("& A::third = %p\n", pz);
	return 0;
}