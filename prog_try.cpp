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


int main()
{
int size_arr[]={10,100,1000,2000,3000,4000,5000,6000,7000,8000,9000};

int size_arr1[]={10,100,10000,20000,30000,40000,50000,60000,70000,80000,90000};

string cases[]={"WORST","BEST"};
string names[]={"Matrix Chain Mutl."};
int (*sort_select[])(int[], int) = {mcm};

for(int k=0;k<1;k++)
{ cout<<" "<<names[k]<<"\n\n";

for(int u=0;u<2;u++)
{
cout<<"FOR "<<cases[u]<<" CASE\n";
cout<<"SIZE OF ARRAY"<<setw(20)<<" TIME_TAKEN(IN MICROSECONDS)\n";

for(int j=0;j<sizeof(size_arr)/sizeof(int);j++)
{ int n;
if(k==0)
n=size_arr[j];
else n=size_arr1[j];
int arr[n],mainarr[n];
for(int i=0;i<n;i++)
{ arr[i]=i;
mainarr[i]=arr[i]; 
}
if(u==0)
arr[n-1]=5;
clock_t start,end;

start=clock();
(*sort_select[k])(arr,n);

end=clock();
float duration=float(end-start)/float(CLOCKS_PER_SEC);
if(k==0)
cout <<setw(6)<< size_arr[j]<<setw(20)<<duration<<setprecision(10)<< endl;
else cout <<setw(6)<< size_arr1[j]<<setw(20)<<duration<<setprecision(10)<< endl;}
cout<<endl;}}
return 0;
}