#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i, j, n, k, tmp;
	queue <int> q;
	cin >> n >> k;
	
    for(i=1; i<n+1; i++) q.push(i);

    cout << '<';
    for(i=0; i<n-1; i++){
        for(j=0; j<k-1; j++){
            tmp=q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << '>';

	return 0;
}