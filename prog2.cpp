#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{ int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1+ j];
i = 0; j = 0; k = l;
while (i < n1 && j < n2)
{ if (L[i] <= R[j])
{ arr[k] = L[i];
i++;}
else{arr[k] = R[j];
j++;}
k++;}
while (i < n1)
{ arr[k] = L[i];
i++;
k++;}
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}
void mergeSort(int arr[], int l, int r)
{
if (l < r)
{ int m = l+(r-l)/2;
mergeSort(arr, l, m);
mergeSort(arr, m+1, r);
merge(arr, l, m, r);
}
}
int main()
{
int size_arr1[]={10,100,10000,20000,30000,40000,50000,60000,70000,80000,90000};
string cases[]={"WORST","BEST"};
string names[]={"MERGE_SORT"};
void (*sort_select[])(int[],int,int) = {mergeSort};
for(int k=0;k<1;k++)
{ cout<<" "<<names[k]<<"\n\n";
for(int u=0;u<2;u++)
{
cout<<"FOR "<<cases[u]<<" CASE\n";
cout<<"SIZE OF ARRAY"<<setw(20)<<" TIME_TAKEN(IN MICROSECONDS)\n";
for(int j=0;j<sizeof(size_arr1)/sizeof(int);j++)
{ int n;

n=size_arr1[j];
int arr[n],mainarr[n];
for(int i=0;i<n;i++)
{ arr[i]=i;
mainarr[i]=arr[i]; }
if(u==0)
arr[n-1]=5;
clock_t start,end;
// auto start = high_resolution_clock::now();
start=clock();
(*sort_select[k])(arr,0,n-1);
//auto stop = high_resolution_clock::now();
end=clock();
float duration=float(end-start)/float(CLOCKS_PER_SEC);

cout <<setw(6)<< size_arr1[j]<<setw(20)<<duration*1000000<<setprecision(10)<< endl;}
cout<<endl;
}
}
return 0;
}