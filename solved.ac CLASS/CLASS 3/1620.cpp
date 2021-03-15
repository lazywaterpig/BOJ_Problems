#include <bits/stdc++.h>
using namespace std;

map <int, string> num;
map <string, int> name;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    string s;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> s;
        num[i]=s;
        name[s]=i;
    }
    for(int i=0; i<m; i++){
        cin >> s;
        if(atoi(s.c_str())==0) cout << name[s] << '\n';
        else cout << num[atoi(s.c_str())] << '\n';
    }
    
    return 0;
}