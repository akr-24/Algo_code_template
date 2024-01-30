#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
  
    //case-1
    
  /* push -->O(1) , pop-->O(n), top-->O(n)
  
  
        |     v        |
        |    iv        |
        |   iii        |
        |    ii        |
        |____i_________|
    
       i.e.for this case we are keeping the first element at bottom/ new element at top
    */
    
    /*
    
    stack<int>s1,s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);  
    
    }
    
    int pop() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ele = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
        return ele;
    }
    
    int peek() {
         while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ele = s2.top();
        // s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
        return ele;
    }
    
    bool empty() {
        return s1.size()==0;
    }
    
    
    */
    
    //case-2
    
    /*  push -->O(n), pop-->O(1) ,top-->O(1)
    
        |     i        |
        |    ii        |
        |   iii        |
        |    iv        |
        |____v_________|
        
        i.e. we are keeping first element at top/ new element at bottom
    */
    
    stack<int>s1,s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
         while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
       int ele = s1.top();
       s1.pop();
       return ele;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.size()==0;
    }
    
};