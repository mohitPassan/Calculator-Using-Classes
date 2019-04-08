#include <iostream>
#include <map>
using namespace std;

class Calculator
{
	public:
		Calculator(){}
		virtual int calculate(int a,int b)=0;
};

class Addition:public Calculator
{
	public:
		int calculate(int a, int b)
		{
			return a+b;
		}
};

class Subtraction:public Calculator
{
	public:
		int calculate(int a, int b)
		{
			return a-b;
		}
};

class Multiplication:public Calculator
{
	public:
		int calculate(int a, int b)
		{
			return a*b;
		}
};

class Division:public Calculator
{
	public:
		int calculate(int a, int b)
		{
			return a/b;
		}
};

int main()
{
	Calculator *c[4];
	Addition a;
	Subtraction s;
	Multiplication m;
	Division d;

	c[0] = &a;
	c[1] = &s;
	c[2] = &m;
	c[3] = &d;

	int d1,d2;
	char op;

	map<char,int> opMap;
	opMap.insert(pair<char,int>('+',0));
	opMap.insert(pair<char,int>('-',1));
	opMap.insert(pair<char,int>('*',2));
	opMap.insert(pair<char,int>('/',3));

	cout << "Enter an expression:" << endl;
	cin >> d1 >> op >> d2;

	cout << "= " << c[opMap[op]]->calculate(d1,d2);
}