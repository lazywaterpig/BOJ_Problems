#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int tt;
    cin >> tt;
    while(tt--){
    	int i, j, n, cnt, tmp=0, flag=0, rev=0; //rev 주의
        string ord, input_tmp;
	    deque <int> dq;

        cin >> ord;
	    cin >> n;
        cin >> input_tmp;

        for(i=1; i<input_tmp.size(); i++){
            if(48<=input_tmp[i] && input_tmp[i]<=57){
                tmp*=10;
                tmp+=input_tmp[i]-48;
            }
            else{
                if(tmp!=0) dq.push_back(tmp);
                tmp=0;
            }
        }
        
        for(i=0; i<dq.size(); i++){
        	dq.push_back(dq.front());
        	dq.pop_front();
        }

        for(i=0; i<ord.size(); i++){
            if(ord[i]=='R'){
                rev+=1;
                rev%=2;
            }
            else{
                if(dq.empty()){
                    cout << "error\n";
                    flag=1;
                    break;
                }
                else if(rev==0) dq.pop_front();
                else dq.pop_back();
            }
        }
        
        tmp=dq.size();
        if(flag==0){
            cout << '[';
            if(rev==0){
                for(i=0; i<tmp-1; i++){
                    cout << dq.front() << ',';
                    dq.pop_front();
                }
            }
            else{
                for(i=0; i<tmp-1; i++){
                    cout << dq.back() << ',';
                    dq.pop_back();
                }
            }
            if(!dq.empty()) cout << dq.front();
            cout << "]\n";
        }
    }

	return 0;
}