#include <bits/stdc++.h>
using namespace std;

const int m=10007;

string s; 
int dp[1001][1001];

int rec(int l, int r){
    if(l>r) return 0;
    if(l==r) return dp[l][r]=1;
    if(dp[l][r]!=-1) return dp[l][r];

    dp[l][r]=(m+rec(l+1,r)+rec(l,r-1)-rec(l+1,r-1))%m;
    if(s[l]==s[r]) dp[l][r]=(m+dp[l][r]+rec(l+1,r-1)+1)%m;
    return dp[l][r];
}

int main(){
    cin >> s;

    memset(dp, -1, sizeof(dp));
    cout << rec(0, s.size()-1);
    return 0;

}