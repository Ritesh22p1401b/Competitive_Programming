#include<bits/stdc++.h>
using namespace std;

int main(){
	int num=2012,count,temp;cin>>num;
	while(num>0){
		count++;
		num=num/10;
	}
	cout<<count<<endl;
	return 0;
}
