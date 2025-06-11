#include<bits/stdc++.h>
using namespace std;

int eval(vector<string> exp){
    for(auto &s: exp) cout << s << endl;
    int ans = 0;
    int start = 0;
    int n = exp.size();
    if(exp.front() != "-"){
        ans = stoi(exp.front());
        start = 1;
    }
    for(int i=start; i<n; i+=2){
        string sign = exp[i];
        int num = stoi(exp[i+1]);
        if(sign == "-") ans -= num;
        else ans += num;
    }
    return ans;
}


// (1+(4+5+2)-3)+(6+8)
int calculate(string s){
    stack<string> st;
    string curr = "";
    for(auto &ch : s){
        // If the character is a space
        if(ch  == ' ') continue;

        if(isdigit(ch)) curr.push_back(ch);
        else if(ch == '(') st.push("("); 
        else{
            // firstly add the curr number
            if(curr != ""){
                st.push(curr);
                curr = "";
            }

            if(ch == '+') st.push("+"); 
            else if(ch == '-') st.push("-"); 
            else{
                // Closing bracket
                vector<string> exp;
                while(!st.empty() && st.top() != "("){
                    exp.push_back(st.top());
                    st.pop();
                }
                st.pop();

                reverse(exp.begin(), exp.end());
                // Evaluate this simple expresion
                int ans = eval(exp);
                string num = to_string(abs(ans));

                // convert to string ans add it to stack with taking care of sign
                if(st.empty()){
                    if(ans >= 0) st.push(num);
                    else{
                        st.push("-");
                        st.push(num);
                    }
                }else{
                    string sign = st.top();
                    if(sign == "+"){
                        if(ans >= 0) st.push(num);
                        else{
                            st.pop();
                            st.push("-");
                            st.push(num);
                        }
                    }else{
                        if(ans >= 0) st.push(num);
                        else{
                            st.pop();
                            st.push("+");
                            st.push(num);
                        }
                    }
                }
            }
        }
    }

    if(curr != ""){
        st.push(curr);
        curr  = "";
    }

    if(st.size() == 1) return stoi(st.top());

    vector<string> exp;
    while(!st.empty()){
        exp.push_back(st.top());
        st.pop();
    }

    reverse(exp.begin(), exp.end());

    // Evaluate this simple expresion
    int ans = eval(exp);
    return ans;
}

int main(){
    string cal;
    getline(cin, cal);
    cout << calculate(cal) << endl;
}