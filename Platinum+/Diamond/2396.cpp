#include <bits/stdc++.h>
using namespace std;

int n, solv, sz;
priority_queue <int> pq;
int arr[100];
//int cnt[100];
//stack <int> s_cnt;
int stick[100]={0};
bool flag=false;

bool cmp(int a, int b){
    return a>b;
}

void backtrack(int depth){
    if(depth==n){
        flag=true;
        return;
    }

    for(int i=0; i<solv; i++){
        if(flag==true) return;
        if(sz-stick[i]>=arr[depth]){
            stick[i]+=arr[depth];
            backtrack(depth+1);
            stick[i]-=arr[depth];
        }

        if(stick[i]==0) return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int sum, tmp;
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    sort(arr, arr+n, cmp);

    for(int i=100; i>1; i--){
        if(sum%i==0) pq.push(i);
    }

    int s=pq.size();
    for(int i=0; i<s; i++){
        solv=pq.top();
        sz=sum/solv;
        for(int j=0; j<solv; j++) stick[i]=0;

        //for(int j=0; j<n; j++) cnt[arr[j]]++;
        //s_cnt=stack <int>();
        if(arr[0]<=sz) backtrack(0);
        if(flag==true) break;
        pq.pop();
    }

    if(flag==true) cout << sum/pq.top();
    else cout << sum;
}