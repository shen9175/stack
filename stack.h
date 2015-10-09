#ifndef STACK_H
#define STACK_H
#include <array>
#include <stdexcept>
#include <iostream>

using namespace std;

#define MAX_SIZE 12
template <typename T> class Stack
{

	public:
	typedef typename array<T,MAX_SIZE>::size_type size_type;
	Stack();
	Stack(const Stack&) = default;
	Stack& operator=(const Stack &) = default;
	~Stack() = default;

	bool isEmpty();
	void push(T x);
	T pop();
	void print();

	private:
	array<T,MAX_SIZE> a;
	size_type top;
};





template<typename T> Stack<T>::Stack()
{
	top=0;
}

template<typename T> bool Stack<T>::isEmpty()
{
	if(top==0)
		return true;
	else
		return false;
}

template<typename T> void Stack<T>::push(T x)
{
	if(top>=MAX_SIZE)
		throw overflow_error("Stack Overflow!");
	else
		a[++top-1]=x;
}

template<typename T> T Stack<T>::pop()
{
	if(isEmpty())
		throw underflow_error("Stack underflow!");
	else
		return a[(top--)-1];
}

template<typename T> void Stack<T>::print()
{
	for(size_type i=0;i<top;++i)
		cout<<a[i]<<" ";
	cout<<endl;
}





#endif

