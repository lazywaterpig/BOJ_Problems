#include <bits/stdc++.h>
using namespace std;

int dp[100002];
int p[501][10002];
int sz[501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));
    string s; cin >> s;
    int n; cin >> n;

    string cur[501];
    for(int i=0; i<n; i++){
        cin >> cur[i];
        sz[i]=cur[i].size();
    }

    memset(p, 0, sizeof(p));

    for(int j=0; j<n; j++){
        int piv=0;
        for(int i=1; i<sz[j]; i++){
            while(piv>0 && cur[j][i]!=cur[j][piv]) piv=p[j][piv-1];
            if(cur[j][i]==cur[j][piv]) p[j][i]=++piv;
        }
    }
    
    int piv[501]={0};
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<n; j++){
            while(piv[j]>0 && s[i]!=cur[j][piv[j]]) piv[j]=p[j][piv[j]-1];
            if(s[i]==cur[j][piv[j]]){
                if(piv[j]==sz[j]-1){
                    if(i==0 || i-sz[j]==-1) dp[i]=sz[j];
                    else dp[i]=max(dp[i], dp[i-sz[j]]+sz[j]);
                    piv[j]=p[j][piv[j]];
                }
                else{
                    piv[j]++;
                }
            }
        }
        if(i!=0) dp[i]=max(dp[i-1], dp[i]);
    }

    cout << dp[s.size()-1];
    return 0;
}