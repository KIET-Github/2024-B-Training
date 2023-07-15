#include<bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string s)
{
    stack<char>st;
    for(char c:s){
        char o=st.empty()?'#':st.top();
        if(o=='(' and c==')')   st.pop();
        else if (o == '{' and c == '}') st.pop();
        else if(o=='[' and c==']')  st.pop();
        else st.push(c);
    }
    return st.empty();
}
int main(){
    int n;  cin>>n;
    string s;   cin>>s;
    (isValidParenthesis(s))?cout<<"True":cout<<"False";
}