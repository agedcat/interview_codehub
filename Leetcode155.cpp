#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class MinStack {
private:
    vector<int>myStack;
    int minElement=INT32_MAX;

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        myStack.push_back(val);
        minElement=minElement>val?val:minElement;
    }
    
    void pop() {
        if(!myStack.empty())
        {
            myStack.pop_back();
        }
        int temp=INT32_MAX;
        for(int i=0;i<myStack.size();++i)
        {
            if(myStack[i]<temp) temp=myStack[i];
        }
        minElement=temp;

    }
    
    int top() {

        return myStack[myStack.size()-1];


    }
    
    int getMin() {
        return minElement;

    }
};