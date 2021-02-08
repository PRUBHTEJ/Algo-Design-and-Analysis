#include<bits/stdc++.h>
#include<iostream>

#include<string>
#include<time.h>
#include<unistd.h>
using namespace std;
int max(int a, int b){
	return(a>b)? a:b;
}
	
	int lcs(char * x, char * y, int m, int n ){
		int l[50][50], i, j;
		//sleep(50);
		for(i=0; i<=m; i++){
			for (j=0; j<=n; j++){
				
				if(i==0||j==0)
					l[i][j]=0;
				else if (x[i-1] == y[j-1])
					l[i][j]=l[i-1][j-1]+1;
				else
					l[i][j] = max(l[i-1][j], l[i][j-1]);
			}
		}
	return l[m][n];

	}

int main(){
	clock_t start, end;
	char x[50], y[50];
   	cout<<"Enter first Sequence"<<endl;
   	cin>>x;
   	cout<<"Enter second sequence"<<endl;
   	cin>>y;
   	int m = strlen(x);
   	int n = strlen(y);
   	start = clock();
   	cout<<"length of lcs is:"<<" "<<lcs(x, y, m, n);
   	end = clock();
   	cout<<endl;
   	cout<<"The time is"<<double(end-start)/double(CLK_TCK);
   	return 0;

}