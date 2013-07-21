#include <iostream>
using namespace std;

template<class M, class G>
M smaller(M a, G b)
{
	if(a < 1)
		return a;
	else				   
		return b;
}

template<class T>
class Generic
{
	T myVar;

public:
	Generic (T a)
	{
		myVar = a;
	}

	T getVar();
};

template<class T>
T Generic<T>:: getVar()
{
	return myVar;
}

template<>
class Generic<string>
{
	string myVar;

public:
	Generic(string myVar)
	{
		cout << "I am a string" << endl;
	}
	string getVar();

};

int main()
{
	int x = 4;
	double y = 2.5;

	cout << smaller(x,y) << endl;

	Generic<int> myGeneric(42);
	cout << myGeneric.getVar() << endl;

	Generic<string> myGeneric1("Get to teh Choppa");
	
	try{
		int pickNum;
		cout << "Pick a number between 1 and 10: " << endl;
		cin >> pickNum;
		if(pickNum > 10 || pickNum < 1)
		{
			throw 42;
		}
	}catch(int error){
		cout << "You done fucked up... " << error << endl;
	}

	system("pause");
	return 0;

}


