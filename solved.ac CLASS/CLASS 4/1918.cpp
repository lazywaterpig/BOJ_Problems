#include <bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c=='(') return 0;
    else if(c=='+' || c=='-') return 1;
    else if(c=='*' || c=='/') return 2;
}

int main(){
    int i;
    stack <char> s;
    string str;
    cin >> str;

    for(i=0; i<str.size(); i++){
        char c=str[i];
        if('A'<=c && c<='Z') cout << c;
        else if(c=='(') s.push(c);
        else if(c==')'){
            while(s.top()!='('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && priority(s.top())>=priority(c)){
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    return 0; 
}