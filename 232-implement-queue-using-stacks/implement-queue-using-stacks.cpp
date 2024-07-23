class MyQueue {
public:
    //Let's solve this problem using two stacks incluclating concept of Amortized O(1) time complexity concept
    stack<int>input;
    stack<int>output;
    int peekv=-1;
    MyQueue() {

    }

    void push(int x) {
        if(input.empty()){
            peekv=x;
        }
        input.push(x);
        
    }

    int pop() {
        //output khaali hai
        //input se output mei daalo
        if(output.empty()){
            while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        }
        

        int val=output.top();
        output.pop();
        return val;
        
    }

    int peek() {
        if(output.empty())
            return peekv;

        else return output.top();    
        
    }

    bool empty() {
        return input.empty() && output.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */