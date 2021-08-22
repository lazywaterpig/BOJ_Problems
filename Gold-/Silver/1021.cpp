#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i, j, n, m, sum=0, cnt, arr[51];
	deque <int> dq;

	cin >> n >> m;
    for(i=1; i<n+1; i++) dq.push_back(i);
    for(i=0; i<m; i++){
        cin >> arr[i];
    }
    
    for(i=0; i<m; i++){
        cnt=0;
        for(j=0; j<dq.size(); j++){
            if(dq.front()==arr[i]) break;
            dq.push_back(dq.front());
            dq.pop_front();
            cnt++;
        }
        if(dq.size()-cnt<cnt) cnt=dq.size()-cnt;
        dq.pop_front();
        sum+=cnt;
    }

    cout << sum;
	return 0;
}