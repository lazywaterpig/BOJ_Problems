#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b; cin >> a >> b;

    for(int i=1; i<=a.size(); i++){
        for(int j=1; j<=b.size(); j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[a.size()][b.size()] << endl;
    if(dp[a.size()][b.size()]){
        stack<char> s;
        int x=a.size(), y=b.size();
        for(int i=0; i<dp[a.size()][b.size()]; i++){
            while(1){
                if(dp[x][y]==dp[x-1][y]) x--;
                else if(dp[x][y]==dp[x][y-1]) y--;
                else{
                    s.push(a[x-1]);
                    x--; y--;
                    break;
                }
            }
        }

        while(!s.empty()){
            cout << s.top();
            s.pop();
        }
    }
    return 0;
}