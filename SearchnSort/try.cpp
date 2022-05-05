#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int t,num,i;
    cin>>t;
    while(t--){
        int ct=0;
        cin>>num;
        while(num!=0){
            for( i=0;i<=11;i++)
            {
                if(num<(int)(pow(2,i-1)+0.5)){
             num=num-(int)(pow(2,i-1)+0.5);
             ct++;
             break;
                }
            }
            if(i==11)
            {
                num=num-(int)(pow(2,i-1)+0.5);
                ct++;
            }
        }
        cout<<ct;
    }
	// your code goes here
	return 0;
}
