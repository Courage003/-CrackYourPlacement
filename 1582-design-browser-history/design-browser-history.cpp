class BrowserHistory {
public:
stack<string>past;
stack<string>future;

string curr;
    BrowserHistory(string homepage) {
        curr=homepage;
        
    }
    
    void visit(string url) {
         past.push(curr); // push the current page to past
    curr = url;      // update curr to the new url

    // Clear the forward history since we're visiting a new page
    future = stack<string>();
    }
    
    string back(int steps) {

        while(steps && !past.empty()){
            future.push(curr);
            curr=past.top();
            past.pop();
            steps--;
        }
        return curr;
        
    }
    
    string forward(int steps) {
        while(steps && !future.empty()){
            past.push(curr);
            curr=future.top();
            future.pop();
            steps--;
        }
        return curr;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */