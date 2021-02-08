#include<iostream>
#include<bits/stdc++.h>
#include<limits>
#include<time.h>
#include<unistd.h>

using namespace std;

int mcm(int p[], int n){
	int m[1000][1000];
	int i, j, k, l, q;
	for(i=1; i<n; i++)
		m[i][i]=0;
	for (l=2; l<n;l++){
		for (i=1; i<n-l+1; i++){
			j = i+l-1;
			m[i][j] = INT_MAX;
			for (k=i;k<=j-1; k++){
				//sleep(5);
				q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
					m[i][j] = q;


			}
		}
	}

	return m[1][n-1];

}

int main(){
	int a[50], size, i;
	clock_t start, end;
	cout<<"enter size";
	cout<<endl;
	cin>>size;
	cout<<"Enter the numbers";
	cout<<endl;
	for(i=0; i<size;i++){
		cin>>a[i];
	}
		start = clock();
		//cout<<"Min. no. of multiplications is"<<" "<<
		mcm(a, size);
		end = clock();
		
		cout<<"The time is"<<" "<<(double((end-start))/double(CLK_TCK))<<setprecision(1000)<<endl;
		return 0;
	
}