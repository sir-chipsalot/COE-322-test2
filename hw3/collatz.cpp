#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//function for collatz conjecture
int collatz(int number)
{
	//returns the count which is the amount of tries it took to converge.
	int count = 0;
	while(number !=1)
	{
		if(number%2==0)
		{
			number = number/2;
		}
		else
		{
			number = 3*number+1;
		}
		count+=1;
	}
	return count;
}

int main()
{
	//self explanitory
	int iterations = 0;

	//this will hold the max number
	int index;

	// for loop for for 1-1000

	for(int i = 1; i <1001; i++)
	{
		//sets iterations equal to the return of the collatz function
		if(iterations < collatz(i))
		{
			index = i;
			iterations = collatz(i);
			cout << "The new number is: " << index << " with a step of " << iterations <<" iterations.\n"; 
		}
	}
	cout << "The most amount of iterations it took to converge to 1 is " << iterations << " and the number was " << index << "\n";
}
