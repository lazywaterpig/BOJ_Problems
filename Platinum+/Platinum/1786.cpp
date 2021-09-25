#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int pi[1000002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string T, P;

    getline(cin, T);
    getline(cin, P);
    memset(pi, 0, sizeof(pi));

    int tsz=T.size(), psz=P.size();

    int piv=0;
    for(int i=1; i<psz; i++){
        while(piv>0 && P[i]!=P[piv]) piv=pi[piv-1];
        if(P[i]==P[piv]) pi[i]=++piv;
    }

    piv=0;
    queue<int> q;
    for(int i=0; i<tsz; i++){
        while(piv>0 && T[i]!=P[piv]) piv=pi[piv-1];
        if(T[i]==P[piv]){
            if(piv==psz-1){
                q.push(i-psz+2);
                piv=pi[piv];
            }
            else piv++;
        }
    }
    cout << q.size() << endl;
    while(!q.empty()){
    	cout << q.front() << endl;
    	q.pop();
    }

    return 0;
}