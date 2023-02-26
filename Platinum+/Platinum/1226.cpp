#include <bits/stdc++.h>
using namespace std;

int dp[100100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, sum=0; cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
        sum+=arr[i].first;
    }

    sort(arr.begin(), arr.end());

    memset(dp, 0, sizeof(dp));

    for(int i=n-1; i>-1; i--){
        for(int j=sum; j>0; j--){
            if(dp[j] && !dp[j+arr[i].first]) dp[j+arr[i].first]=arr[i].first;
        }
        if(!dp[arr[i].first]) dp[arr[i].first]=arr[i].first;
    }

    int h=sum/2, ans;
    for(int i=h+1; i<=sum; i++){
        if(dp[i]>=i-h) ans=i;
    }

	priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> num;

    while(ans){
        pq.push(dp[ans]);
        ans-=dp[ans];
    }

    for(int i=n-1; i>-1; i--){
        if(pq.empty()) break;

        int cur = pq.top();
        pq.pop();
        while(arr[i].first!=cur) i--;

        num.push(arr[i].second);
    }

    cout << num.size() << '\n';
    while(!num.empty()){
        cout << num.top() << ' ';
        num.pop();
    }
    return 0;
}