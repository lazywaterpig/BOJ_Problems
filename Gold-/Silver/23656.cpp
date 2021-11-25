#include <bits/stdc++.h>
using namespace std;

int main(){
    int t=0, l=1, r=1e9, tmp;
    while(t<100){
        cin >> tmp;
        if(l>tmp || r<tmp){
            if(l>tmp) cout << '>' << endl;
            else cout << '<' << endl;
        }
        else if(l==r){
            cout << '=' << endl;
            break;
        }
        else if(tmp-l>r-tmp){
            r=tmp-1;
            cout << '<' << endl;
        }
        else{
            l=tmp+1;
            cout << '>' << endl;
        }
        t++;
    }
    
    return 0;
}