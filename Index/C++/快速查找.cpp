#include<iostream>
using namespace std;
void sort(int *a,int m){
		if(m<1)return ;
	int l = 0;
	int r = m-1;
	int t = a[l];
	while(l<r){
		while(l<r&&a[l]<=a[r])r--;
		a[l] = a[r];
		while(l<r&&a[l]<=a[r])l++;
		a[r] = a[l];
	}
	//a[l]=t;
	sort(a,l);
	sort(a+l+1,m-l-1);

}
int main()
{
		int a[10] = {1,5748,5748,574,231,3254,655,34,6,231};
		sort(a,10);
		for(int i = 0;i<10;i++)
			cout<<a[i]<<' ';
		cout<<endl;

		return 0;
}
