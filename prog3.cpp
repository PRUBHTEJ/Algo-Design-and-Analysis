#include <bits/stdc++.h>
using namespace std;
int partition (int arr[], int low, int high)
{ int pivot = arr[high];
int i = (low - 1);

for (int j = low; j <= high - 1; j++)
{if (arr[j] < pivot)
{ i++;
swap(arr[i], arr[j]);}
}
swap(arr[i + 1], arr[high]);
return (i + 1);}

void quickSort(int arr[], int low, int high)
{ if (low < high)
{ int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}

int main()
{int size_arr[]={10,100,1000,2000,3000,4000,5000,6000,7000,8000,9000};
int size_arr1[]={10,100,10000,20000,30000,40000,50000,60000,70000,80000,90000};
string cases[]={"BEST","WORST"};
string names[]={"QUICK_SORT"};
void (*sort_select[])(int[], int,int) = {quickSort};

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
if(k==0)
cout <<setw(6)<< size_arr[j]<<setw(20)<<duration*1000000<<setprecision(10)<< endl;
else cout <<setw(6)<< size_arr1[j]<<setw(20)<<duration*1000000<<setprecision(10)<< endl;}
cout<<endl;}}
return 0;}

