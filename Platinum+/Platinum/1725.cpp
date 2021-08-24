#include <bits/stdc++.h>
using namespace std;

int hist[100002], sw[100002][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, n, ans=0;
    stack <int> s, co;

    cin >> n;
    for(i=0; i<n; i++) cin >> hist[i];

    for(i=0; i<n; i++){
        sw[i][0]=n;
        sw[i][1]=-1;
    }

    for(i=0; i<n; i++){
        if(s.empty()){
            s.push(hist[i]);
            co.push(i);
        }
        else{
            while(!s.empty() && !(s.top()<hist[i])){
                s.pop();
                sw[co.top()][0]=i;
                co.pop();
            }
            s.push(hist[i]);
            co.push(i);
        }
    }

    s=stack <int>();
    co=stack <int>();
    for(i=n-1; i>0; i--){
        if(s.empty()){
            s.push(hist[i]);
            co.push(i);
        }
        else{
            while(!s.empty() && !(s.top()<hist[i])){
                s.pop();
                sw[co.top()][1]=i;
                co.pop();
            }
            s.push(hist[i]);
            co.push(i);
        }
    }

    for(i=0; i<n; i++){
        if(ans<hist[i]*(sw[i][0]-sw[i][1]-1)) ans=hist[i]*(sw[i][0]-sw[i][1]-1);
    }
    cout << ans;
    return 0;
}