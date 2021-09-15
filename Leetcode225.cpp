#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        for(int i = 0; i < n; ++i){
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int e = top();
        q.pop();
        return e;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};