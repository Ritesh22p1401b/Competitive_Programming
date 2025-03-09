#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int *ptr1;
	int *ptr2;
	ptr1=&a;
	ptr2=ptr1;
	ptr1=&b;
	cout<<*ptr1<<" "<<*ptr2;
}

