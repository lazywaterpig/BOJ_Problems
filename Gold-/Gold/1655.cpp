#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, n;
    priority_queue <int> smol;
    priority_queue <int, vector<int>, greater<int>> big;
    
    cin >> n;

    while(n--){
        int tmp;
        cin >> tmp;
        if(smol.empty()){
            smol.push(tmp);
        }
        else{
            if(tmp<=smol.top()) smol.push(tmp);
            else big.push(tmp);

            if(smol.size()>big.size()+1){
                big.push(smol.top());
                smol.pop();
            }
            if(big.size()>smol.size()){
                smol.push(big.top());
                big.pop();
            }
        }

        cout << smol.top() << "\n";
    }

    return 0;
}