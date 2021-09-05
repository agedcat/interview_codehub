#include<iostream>
using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
int rand7(){}

int rand10() 
{
    while(true)
    {
        int a=rand7();
        int b=rand7();
        int sum=(a-1)*7+b;
        if(sum<=40) return sum%10+1;
    }
}