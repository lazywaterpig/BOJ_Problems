#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i, j, n, ord, cnt, tmp;
	deque <int> dq, num;

	cin >> n;
    for(i=1; i<n+1; i++) num.push_back(i);
    for(i=0; i<n; i++){
        cin >> tmp;
        dq.push_back(tmp);
    }

    for(i=0; i<n-1; i++){
        ord=dq.front();
        dq.pop_front();
        cout << num.front() << ' ';
        num.pop_front();
        while(ord!=0 && ord!=1){
            if(ord>0){
                dq.push_back(dq.front());
                num.push_back(num.front());
                dq.pop_front();
                num.pop_front();
                ord--;
            }
            else{
                dq.push_front(dq.back());
                num.push_front(num.back());
                dq.pop_back();
                num.pop_back();
                ord++;
            }
        }
    }
    
    cout << num.front();
	return 0;
}