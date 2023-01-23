#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    stack <long long> s;
    long long n, tmp, cnt=0; cin >> n;

    for(long long i=0; i<n; i++){
        cin >> tmp;
        if(s.empty() || s.top()>tmp) s.push(tmp);
        else{
            while(!s.empty() && s.top()<=tmp){
                cnt+=s.size()-1;
                s.pop();
            }
            s.push(tmp);
        }
    }
    cnt+=(s.size())*(s.size()-1)/2;
    cout << cnt << "\n";
    return 0;
}