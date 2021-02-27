#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    if(a.size()==b.size()) return a<b;
    return a.size()<b.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector <string> v;
    int i, n;
    cin >> n;
    v.resize(n);
    for(i=0; i<n; i++) cin >> v[i];

    sort(v.begin(), v.end(), cmp);

    for(i=0; i<n; i++) cout << v[i] << '\n';
    return 0;
}