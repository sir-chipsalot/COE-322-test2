#include<iostream>

using std::cout;
using std::endl;
using std::cin;

double f(double, float);
double derivative(double);

int main()
{
        //create a value of some start
        double guess = 1;
        //have a value of what we want to find the root of i.e: sqrt(2) 2 is are value in the root
        float  in_root = 2;

        //have a value that calculates the difference between the current guess and previous guess
        float gap = 1;

        // have a new_guess function read
        float new_guess;

        //track amount of tries
        int tries = 0;

        while(std::abs(gap)>1.e-7)         
        {
                //newton method new_guess is equal to this.
                new_guess = guess-(f(guess, in_root)/derivative(guess));

                //gcreates the gap value.
                gap = new_guess - guess;

                //sets x equal to xn+1 to prepare for continuing for loop.
                guess = new_guess;

                //increase the try count;
                tries+=1;

        }

        cout << "the root of " << in_root << " is " << guess << " and it took " << tries << " tries to find using Newton's method \n";
        
}
//takes the guess and changes the value
double f(double guess, float in_root){return ((guess*guess)-in_root);}
double derivative(double guess){return (guess*2);}


