#include <bits/stdc++.h>
using namespace std;

void reverseStr(string& str)
{
    int num=str.length();

    for(int i=0; i<num/2; i++)
        swap(str[i], str[num-i-1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, k, n, nbomb, xcnt=0;
    string x, bomb, res="";
    stack <char> s;

    cin >> x;
    cin >> bomb;
    n=x.size();
    nbomb=bomb.size();
    for(i=0; i<n; i++){
        s.push(x[i]);
        if(x[i]==bomb[xcnt]) xcnt++;
        else if(x[i]==bomb[0]) xcnt=1;
        else xcnt=0;

        if(xcnt==nbomb){
            for(j=0; j<nbomb; j++) s.pop();
            
            if(s.size()!=0){
            	for(j=nbomb-2; j>-1; j--){
                	if(s.top()==bomb[j]) break;
            	}
            	if(j==-1) xcnt=0;
            	else{
            		for(k=j-1; k>-1; k--){
                		s.pop();
                		if(s.top()!=bomb[k]) break;
            		}
            		if(k!=-1) xcnt=0;
	            	else{ xcnt=j+1; s.pop(); }
            	
            		while(k!=j){
                		k++;
                		s.push(bomb[k]);
            		}
            	}
            }
        }
    }

    n=s.size();
    if(n==0) cout << "FRULA";
    else{
    	for(i=0; i<n; i++){
        	res+=s.top();
        	s.pop();
    	}
        reverseStr(res);
    	cout << res;
    }
    return 0;
}