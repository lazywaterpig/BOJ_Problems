#include <iostream>
#include <string>
#include <stack>
using namespace std;

//ascii code value
//'(' + 1 = ')'
//'[' + 2 = ']'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, n, cnt=0;
    bool flag=0;
    string x;
    stack <char> b;
    cin >> x;
    n=x.size();

    for(i=0; i<n; i++){
        if(x[i]=='(' || x[i]=='['){
            b.push(x[i]);
            cnt++;
        }
        else{
            if(b.size()==0){
                flag=1;
                break;
            }
            else if(!(b.top()+1==x[i] || b.top()+2==x[i])){
                flag=1;
                break;
            }
            else b.pop();
            cnt--;
        }
    }
    if(cnt!=0) flag=1;

    if(flag==0){
        int sum=0, value=1;
        for(i=0; i<n; i++){
            if(x[i]=='(') value*=2;
            else if(x[i]=='[') value*=3;
            else if(x[i]==')'){
                if(x[i-1]=='(') sum+=value;
                value/=2;
            }
            else{
                if(x[i-1]=='[') sum+=value;
                value/=3;
            }
        }
        cout << sum;
    }
    else cout << '0';

    return 0;
}