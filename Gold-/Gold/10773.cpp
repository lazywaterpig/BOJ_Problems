#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k, sum=0; cin >> k;
    stack <int> s;
    
    while(k--){
        int tmp; cin >> tmp;
        if(tmp) s.push(tmp);
        else s.pop();
    }

	int sz;
	sz = s.size();
	for(int i=0; i<sz; i++){
	    sum+=s.top();
	    s.pop();
	}
    cout << sum;
    return 0;
}