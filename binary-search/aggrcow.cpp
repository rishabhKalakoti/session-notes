#include<stdio.h>
#include<algorithm>
#include<vector>
 
using namespace std;
 
#define ll long long
#define forep(i,N) for(ll i=0;i<N;i++)
#define sc(N) scanf("%lli",&N)
ll N,C;
vector<ll>stall;
ll check(ll index){
    ll prev=stall[0];
    ll cnt=1;
    for(ll i=1;i<N;i++){
        if(stall[i]-prev>=index){
            cnt++;
            prev=stall[i];
        }
        if(cnt==C)
            return 1;
    }
    return 0;
}
 
int main(){
    ll T;
    sc(T);
    while(T--){
        sc(N);
        sc(C);
        stall.resize(N);
        forep(i,N)
            sc(stall[i]);
        sort(stall.begin(),stall.end());
        // binary search for a value
        ll left=0;
        ll right=10000000000;
        // check for a value
        ll mid=(left+right)/2;
        do{
            //printf("%lli\n",mid);
            if(check(mid)==0)
                right=mid-1;
            else
                left=mid+1;
            if(left>right)
                break;
            mid=(left+right)/2;
        }while(!(check(mid)==1 && check(mid+1)==0));
        printf("%lli\n",mid);
        // check(i)==1 && check[i-1]==0
    }
    return 0;
} 
