#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cnt[6]={0};

int main(){
    ll x1,x2,y1,y2; cin >> x1 >> y1 >> x2 >> y2;




    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cnt[6]={0};

bool isHorizontal(ll x, ll y){
    return ((x/5+y/5)%2==0);
}

void corner(ll x1, ll y1, ll x2, ll y2, ll t){
    if(x1==x2 || y1==y2) return;

    if(t==1){
        if(isHorizontal(x1,y1)) cnt[x2-x1]+=(y2-y1);
        else cnt[y2-y1]+=(x2-x1);
    }
    if(t==2){
        if(isHorizontal(x2,y1)) cnt[x2-x1]+=(y2-y1);
        else cnt[y2-y1]+=(x2-x1);
    }
    if(t==3){
        if(isHorizontal(x1,y2)) cnt[x2-x1]+=(y2-y1);
        else cnt[y2-y1]+=(x2-x1);
    }
    if(t==4){
        if(isHorizontal(x2,y2)) cnt[x2-x1]+=(y2-y1);
        else cnt[y2-y1]+=(x2-x1);
    }
}

void side(ll x1, ll y1, ll x2, ll y2){
    if(x1==x2 || y1==y2) return;

    if((x2-x1)%5==0){
        if((x2-x1)%2==0){
            cnt[5]+=(y2-y1)*(x2-x1)/10;
            cnt[y2-y1]+=(x2-x1)/2;
        }
        else{
            if(isHorizontal(x1, y1)) cnt[5]+=(y2-y1);
            else cnt[y2-y1]+=5;
            
            cnt[5]+=(y2-y1)*(x2-x1-5)/10;
            cnt[y2-y1]+=(x2-x1-5)/2;
        }
    }
    else{
        if((y2-y1)%2==0){
            cnt[5]+=(x2-x1)*(y2-y1)/10;
            cnt[x2-x1]+=(y2-y1)/2;
        }
        else{
            if(!isHorizontal(x1, y1)) cnt[5]+=(x2-x1);
            else cnt[x2-x1]+=5;
            
            cnt[5]+=(x2-x1)*(y2-y1-5)/10;
            cnt[x2-x1]+=(y2-y1-5)/2;
        }
    }
}

int main(){
    ll x[2], y[2];
    cin >> x[0] >> y[0] >> x[1] >> y[1];

    ll cutx[2], cuty[2];
    cutx[0]=((x[0]-1)/5+1)*5;
    cutx[1]=(x[1]/5)*5;
    cuty[0]=((y[0]-1)/5+1)*5;
    cuty[1]=(y[1]/5)*5;
    if(x[0]==0) cutx[0]=0;
    if(y[0]==0) cuty[0]=0;

    cnt[5]+=(cutx[1]-cutx[0])*(cuty[1]-cuty[0])/5;

    side(x[0], cuty[0], cutx[0], cuty[1]);
    side(cutx[0], y[0], cutx[1], cuty[0]);
    side(cutx[1], cuty[0], x[1], cuty[1]);
    side(cutx[0], cuty[1], cutx[1], y[1]);

    corner(x[0], y[0], cutx[0], cuty[0], 1);
    corner(cutx[1], y[0], x[1], cuty[0], 2);
    corner(x[0], cuty[1], cutx[0], y[1], 3);
    corner(cutx[1], cuty[1], x[1], y[1], 4);

    ll ans=cnt[5];
    ans+=cnt[4];
    cnt[1]-=cnt[4];
    ans+=cnt[3];
    cnt[2]-=cnt[3];
    if(cnt[2]>0){
        if(cnt[1]>0){
            ans+=cnt[2]/2;
            cnt[1]-=cnt[2]/2;
            cnt[2]-=cnt[2]/2*2;
            if(cnt[2]!=0){
                if(cnt[1]>=0) ans+=(cnt[1]+6)/5;
                else ans+=1;
            }
            else ans+=(cnt[1]+4)/5;
        }
        else ans+=(cnt[2]+1)/2;
    }
    else{
        if(cnt[1]>0) ans+=(cnt[1]+4)/5;
    }

    cout << ans << endl;
    return 0;
}