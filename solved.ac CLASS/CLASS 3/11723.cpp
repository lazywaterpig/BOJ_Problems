#include <stdio.h>
#include <memory.h>

int main(){
    bool arr[22];
    char ord[9];
    int n, num;

    memset(arr, 0, sizeof(arr));
    scanf("%d\n", &n);
    while(n--){
        scanf("%s ", ord);
        if(ord[0]=='a' && ord[1]=='l') memset(arr, 1, sizeof(arr));
        else if(ord[0]=='e') memset(arr, 0, sizeof(arr));
        else if(ord[0]=='c'){
            scanf("%d\n", &num);
            if(1<=num && num<=20) printf("%d\n", arr[num]);
        }
        else if(ord[0]=='r'){
            scanf("%d\n", &num);
            if(1<=num && num<=20) arr[num]=0;
        }
        else if(ord[0]=='t'){
            scanf("%d\n", &num);
            if(1<=num && num<=20) arr[num]^=1;
        }
        else if(ord[0]=='a'){
            scanf("%d\n", &num);
            if(1<=num && num<=20) arr[num]=1;
        }
		else{
            continue;
        }
    }
    return 0;
}