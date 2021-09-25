#include <bits/stdc++.h>
using namespace std;

int p[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int piv=0, tmp, n; cin >> n;
    string s; cin >> s;
    for(int i=1; i<n; i++){
        while(piv>0 && s[i]!=s[piv]) piv=p[piv-1];
        if(s[i]==s[piv]){
            piv++;
            p[i]=piv;
        }
    }
    
    for(int i=1; i<n; i++){
    	if(p[i]!=0){
    		piv=p[i];
	        while(p[piv-1]>0 && s[i]==s[piv-1]) piv=p[piv-1]; //reduce fail function to non-zero minimum value;
	        p[i]=piv;
    	}
    }
    
    long long cnt=0;
    for(int i=0; i<n; i++){
        if(p[i]!=0) cnt+=i+1-p[i];
    }
    cout << cnt;
    return 0;
}