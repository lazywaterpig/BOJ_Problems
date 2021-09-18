#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

vector<pair<int,int>> ans;
int arr[500005];
int maxi[500005];
int vis[500005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n-2; i++){
        cin >> arr[i];
        maxi[arr[i]]=i;
        vis[arr[i]]=1;
    }

    priority_queue<int> pq;
    for(int i=1; i<=n; i++){
        if(vis[i]==0) pq.push(i);
    }

    for(int i=0; i<n-2; i++){
        ans.push_back({min(pq.top(),arr[i]), max(pq.top(),arr[i])});
        pq.pop();
        if(maxi[arr[i]]==i) pq.push(arr[i]);
    }
    int b1, b2;
    b1=pq.top();
    pq.pop();
    b2=pq.top();
    ans.push_back({min(b1,b2), max(b1,b2)});

    sort(ans.begin(), ans.end());

    for(auto i : ans) cout << i.first << ' ' << i.second << endl;

    return 0;
}