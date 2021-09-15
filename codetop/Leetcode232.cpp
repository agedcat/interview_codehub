#include<queue>
#include<stack>
using namespace std;

class MyQueue {
private:
    stack<int>in;
    stack<int>out;

    void in2out()
    {
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(out.empty()) in2out();
        int temp=out.top();
        out.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if(out.empty()) in2out();
        return out.top();

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty()&&out.empty();
    }
};