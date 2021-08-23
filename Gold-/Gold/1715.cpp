#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int main(){
    fastio;
    ll i, n, tmp, tmp2, tot=0;
    cin >> n;

    priority_queue <int, vector<int>, greater<int>> pq; //작은값부터
    //priority_queue <int, vector<int>, less<int>> pq == p_q <int> pq 큰값부터
/*  struct a{
        int start;
        int end;
        int value;
    };
 
    struct cmp{
        bool operator()(a t, a u){
            return t.value < u.value;
        }
    };
 
    priority_queue<a,vector<a>,cmp> pq; 임의의 cmp함수

    출처: https://koosaga.com/9 [구사과]
*/
    
    for(i=0; i<n; i++){
        cin >> tmp;
        pq.push(tmp);
    }

    for(i=0; i<n-1; i++){
        tmp=pq.top();
        pq.pop();
        tmp2=pq.top();
        pq.pop();
        tot+=tmp+tmp2;
        pq.push(tmp+tmp2);
    }
    cout << tot;
    return 0;
}