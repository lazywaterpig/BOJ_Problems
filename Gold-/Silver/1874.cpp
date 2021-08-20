#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, n, v, cnt=1, nt;
    bool flag=0;
    stack <int> s;
    queue <char> q;
    cin >> n;
    nt=n;

    while(nt>0){
        int num;
        cin >> num;
        if(cnt>num){
            if(s.top()!=num){
                cout << "NO";
                flag=1;
                break;
            }
            else{
                s.pop();
                q.push('-');
            }
        }
        else if(cnt<num){
            while(cnt<num){
                s.push(cnt);
                q.push('+');
                cnt++;
            }
            q.push('+');
            q.push('-');
            cnt++;
        }
        else{
            q.push('+');
            q.push('-');
            cnt++;
        }
        nt--;
    }
    if(flag==0){
        for(i=0; i<2*n; i++){
            cout << q.front() << "\n";
            q.pop();
        }
    }
    return 0;
}