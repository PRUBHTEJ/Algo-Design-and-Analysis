#include<bits/stdc++.h>

using namespace std;



void bubbleSort(int arr[], int n)
{ int i, j;
for (i = 0; i < n-1; i++)
for (j = 0; j < n-i-1; j++)
if (arr[j] > arr[j+1])
swap(arr[j], arr[j+1]);
}
int main()
{ int size_arr[]={10,100,1000,2000,3000,4000,5000,6000,7000,8000,9000};
string cases[]={"BEST","WORST"};
string names[]={"BUBBLE_SORT"};
void (*sort_select[])(int[], int) = {bubbleSort};
for(int k=0;k<1;k++)
{ cout<<" "<<names[k]<<"\n\n";
for(int u=0;u<2;u++)
{ cout<<"FOR "<<cases[u]<<" CASE\n";
cout<<"SIZE OF ARRAY"<<setw(20)<<" TIME_TAKEN(IN MICROSECONDS)\n";
for(int j=0;j<sizeof(size_arr)/sizeof(int);j++)
{ int n=size_arr[j];
int arr[n],mainarr[n];
for(int i=0;i<n;i++)
{ if(u==0)
arr[i]=i;
else if (u==1)
arr[i]=rand()%1000;
else arr[i]=n-i;
mainarr[i]=arr[i]; }
clock_t start,end;
// auto start = high_resolution_clock::now();
start=clock();
(*sort_select[k])(arr,n);
//auto stop = high_resolution_clock::now();
end=clock();
double duration=double(end-start)/double(CLOCKS_PER_SEC);
cout <<setw(6)<< size_arr[j]<<setw(20)<<duration*1000000<<setprecision(10)<< endl;}
cout<<endl;
}}
return 0;}