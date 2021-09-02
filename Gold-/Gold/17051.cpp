#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int n;
int arr[MAX];
int dat[MAX*2][2];
int parent[MAX*2]={0};
bool b[MAX*2]; // + = 0(false), - = 1

bool cur=false; // true = -, false = +
int cnt[2]={0}; // + = 0, - = 1

void dfs(int node){
    if(node>n){
        if(b[node]==false){
            dfs(dat[node][0]);
            dfs(dat[node][1]);
        }
        else{
            dfs(dat[node][0]);
            cur^=1;
            dfs(dat[node][1]);
            cur^=1;
        }
    }
    else cnt[cur]++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    char boool;
    int buf1, buf2;
    for(int i=n+1; i<2*n; i++){
        cin >> boool >> buf1 >> buf2;
        if(boool=='+') b[i]=0;
        else b[i]=1;

        dat[i][0]=buf1;
        dat[i][1]=buf2;
        parent[buf1]=i;
        parent[buf2]=i;
    }

    dfs(2*n-1);

    int ans=0;
    for(int i=0; i<cnt[1]; i++) ans-=arr[i];
    for(int i=0; i<cnt[0]; i++) ans+=arr[i+cnt[1]];
    cout << ans;

    return 0;
}