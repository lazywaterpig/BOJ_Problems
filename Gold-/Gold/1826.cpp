#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

vector <pair<int,int>> arr;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

int main(){
    fastio;

    priority_queue <int> pq;
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
    
    int i, n, l, p, piv=1, cnt=0, flag=0, buf1, buf2;

    cin >> n;
    for(i=0; i<n; i++) { cin >> buf1 >> buf2; arr.push_back({buf1, buf2}); }
    sort(arr.begin(), arr.end(), cmp);
    cin >> l >> p;
    
    while(l>p){
        while(piv<n && p>arr[piv].first){
            pq.push(arr[piv].second);
            piv++;
        }
        if(pq.empty()) { cout << "-1"; flag=1; break; }
        p+=pq.top();
        pq.pop();
        cnt++;
    }

    if(flag==0) cout << cnt;
    return 0;
}