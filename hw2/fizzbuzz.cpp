#include<iostream>

using std::cout;
using std::endl;
using std::cin;


int read_number(int number);

int main()
{
	int c;
	cout << "Write a number: ";
	cin  >> c;
	read_number(c);
}

int read_number(int number)
{
	if (number%3==0 and number%5==0)
	{
		cout<<"FizzBuzz! \n";
	}
	else if (number%3 == 0)
	{
		cout<< "Fizz! \n";
	}
	else if (number%5 == 0)
	{
		cout << "Buzz!\n";
	}
	return 0;
}	


