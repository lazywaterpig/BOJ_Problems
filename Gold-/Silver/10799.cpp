#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, n, cnt=0, sum=0;
    string x;
    cin >> x;
    n=x.size();
    for(i=0; i<n; i++){
        if(x[i]=='(') cnt++;
        else{
            cnt--;
            if(x[i-1]=='(') sum+=cnt;
            else sum++;
        }
    }
    cout << sum;
    return 0;
}