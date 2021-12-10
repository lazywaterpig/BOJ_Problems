#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp, s; cin >> n;
    vector<int> v, vrev, arr;
    v.resize(n+1);
    vrev.resize(n+1);
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> tmp;
        vrev[i]=tmp;
        v[tmp]=i;
    }
    for(int i=0; i<n; i++){
        cin >> arr[i];
        arr[i]=v[arr[i]];
        if(!arr[i]) s=i;
    }


    if(q.size()!=n) cout << "-1";
    else{
        for(int i=0; i<n; i++){
            cout << vrev[q.front()] << ' ';
            q.pop();
        }
    }

    return 0;
}