#include <bits/stdc++.h>
using namespace std;

int p[1000002];
bool vis[1000002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    string t=s.substr(1, s.size()-2);
    int piv=0;
    for(int i=1; i<s.size(); i++){
        while(piv>0 && s[i]!=s[piv]) piv=p[piv-1];
        if(s[i]==s[piv]) p[i]=++piv;
    }

    piv=p[s.size()-1];
    while(piv!=0){
    	vis[piv]=1;
    	piv=p[piv-1];
    }
    
    int maxv=0, maxi=-1;
    for(int i=0; i<t.size(); i++){
        while(piv>0 && t[i]!=s[piv]) piv=p[piv-1];
        if(t[i]==s[piv]){
            piv++;
            if(maxv<piv && vis[piv]){
                maxv=piv;
                maxi=i;
            }
        }
    }

    if(maxi==-1) cout << "-1";
    else{
        maxi-=(maxv-1);
        cout << t.substr(maxi, maxv);
    }

    return 0;
}