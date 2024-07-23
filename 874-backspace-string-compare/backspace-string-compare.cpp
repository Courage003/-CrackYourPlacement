class Solution {
public:
    bool backspaceCompare(string s, string t) {
        /*string s1;
        string s2;
        for(auto i: s){
            if(i!='#') s1.push_back(i);
            else if(s1.size()) s1.pop_back();
        }
        for(auto i: t){
            if(i!='#') s2.push_back(i);
            else if(s2.size()) s2.pop_back();
        }
        return s1==s2;*/
    stack<char> st1;
        stack<char> st2;

        for (auto i : s) {
            if (i != '#') {
                st1.push(i);
            } else if (!st1.empty()) {
                st1.pop();
            }
        }

        for (auto i : t) {
            if (i != '#') {
                st2.push(i);
            } else if (!st2.empty()) {
                st2.pop();
            }
        }

        string m;
        string n;

        while (!st1.empty()) {
            m.push_back(st1.top());
            st1.pop();
        }

        while (!st2.empty()) {
            n.push_back(st2.top());
            st2.pop();
        }

        return m == n;


    }};