/*
To perform an operationwithout using conditions we use polymorphism. Our aim is to decide at runtime which function to call, which is done by virtual functions abstract classes.

Here we create an array of pointers of the abstract class of size 4. Now, we point each of the element to each operator class.
0th index to addition
1st index to subtraction ...

We use a map STL to map operators to numbers ('+'=0,'-'=1 ...).

If user gives a plus sign then the object pointed by the pointer at 0th index will be called.
*/

#include <iostream>
#include <map>
using namespace std;

class Calculator		//The abstract class calculator which has each operation class as a child.
{
	public:
		Calculator(){}
		virtual int calculate(int a,int b)=0;		//Pure virtual function.
};

class Addition:public Calculator 		//Addition class for adition operator.
{
	public:
		int calculate(int a, int b)
		{
			return a+b;
		}
};

class Subtraction:public Calculator 		//Subtraction class for subtraction operator.
{
	public:
		int calculate(int a, int b)
		{
			return a-b;
		}
};

class Multiplication:public Calculator 		//Multiplication class for multiplication operator.
{
	public:
		int calculate(int a, int b)
		{
			return a*b;
		}
};

class Division:public Calculator 		//Division class fro division operator.
{
	public:
		int calculate(int a, int b)
		{
			return a/b;
		}
};

int main()
{
	Calculator *c[4];		//Object of abstract class, which is an array of pointers.
	Addition a;				//Object of addition class.
	Subtraction s;			//Object of subtraction class.
	Multiplication m;		//Object of multiplication class.
	Division d;				//Object of division class.

	//Now we point pointer at each index to each operator class.

	c[0] = &a;
	c[1] = &s;
	c[2] = &m;
	c[3] = &d;

	int d1,d2;		//Data variables.
	char op;		//Operator

	//Mapping each operator to an integer number.

	map<char,int> opMap;
	opMap.insert(pair<char,int>('+',0));
	opMap.insert(pair<char,int>('-',1));
	opMap.insert(pair<char,int>('*',2));
	opMap.insert(pair<char,int>('/',3));

	cout << "Enter an expression:" << endl;		//Taking input
	cin >> d1 >> op >> d2;

	cout << "= " << c[opMap[op]]->calculate(d1,d2);		//This is the line which binds the relevant object at runtime.
}