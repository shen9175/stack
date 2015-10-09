#include "stack.h"
#include <stdexcept>
#include <iostream>
#include <random>
using namespace std;
template <typename T> void test(Stack<T> testobj/*,bool type*/);
int main()
{
	Stack<unsigned> s;
	test(s);
	Stack<double> a;
	test(a);
	return 0;
}


template <typename T> void test(Stack<T> testobj/*,bool type*/)
{
	
	default_random_engine e;
/*
	if(type)
		goto inttype;
	else
		goto floattype;
inttype:
		uniform_int_distribution<unsigned> u(0,9);
floattype:
		uniform_real_distribution<double> u(0,9);
*/
	uniform_real_distribution<double> u(0,9);


	try{
		cout<<"Now testing Stack push and pop function:"<<endl;
		char ch;
		while(1)
		{
			try{
			bool quit=false;
			cout<<"Push or Pop? press \"p or P\" for push, press \"o or O\" for pop, press \"q or Q\" for quit: ";
			cin>>ch;
			switch(ch)
			{
				case 'p':
				case 'P':
					{
						T temp=u(e);
						testobj.push(temp);
						cout<<"Generated random number: "<<temp<<" pushed onto the stack."<<endl;
						cout<<"Now the stack is:"<<endl;
						testobj.print();
						break;
					}
				case 'O':
				case 'o':
					{
						cout<<"Number: "<<testobj.pop()<<" is popped."<<endl;
						cout<<"Now the stack is:"<<endl;
						testobj.print();
						break;
					}
				case 'q':
				case 'Q':
					{
					quit=true;
					break;
					}
				default:
					throw runtime_error("Invalid input, try again!");
					break;
			}//end switch

			if(quit)
				break;

		  }//end inner try
			catch(runtime_error err)
			{
				cerr<<err.what()<<endl;
			}
		}//end while
		
	   }
	catch(overflow_error over)
		{
			cerr<<over.what()<<endl;
		}
	catch(underflow_error under)
		{
			cerr<<under.what()<<endl;
		}

	Stack<T> s2(testobj);
	Stack<T> s3;
	s3=s2;
	cout<<"Now testing the copy assignement and assignment operator!"<<endl;
	cout<<"The copy constructor assigned s2 from s, the s2 is:"<<endl;
	s2.print();
	cout<<"The assignment operator: s3=s2. the s3 is:"<<endl;
	s3.print();

} 
