#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// This function takes the last element
// as pivot, places
// the pivot element at its correct
// position in sorted array, and 
// places all smaller (smaller than pivot)
// to left of pivot and all greater 
// elements to right of pivot
int partition(int arr[], int low, int high)
{
    // pivot
    int pivot = arr[high]; 
   
    // Index of smaller element
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++) 
    {
        // If current element is smaller
        // than or equal to pivot
        if (arr[j] <= pivot) {
 
            // increment index of 
            // smaller element
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
}
 
/* The main function that implements
QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
 
        /* pi is partitioning index,
        arr[p] is now
        at right place */
        int pi = partition_r(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 

// Driver Code
int main()
{
int size_arr[]={10,100,1000,2000,3000,4000,5000,6000,7000,8000,9000};

int size_arr1[]={10,100,10000,20000,30000,40000,50000,60000,70000,80000,90000};

string cases[]={"WORST","BEST"};
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

start=clock();
(*sort_select[k])(arr,0,n-1);

end=clock();
float duration=float(end-start)/float(CLOCKS_PER_SEC);
if(k==0)
cout <<setw(6)<< size_arr[j]<<setw(20)<<duration*1000000<<setprecision(10)<< endl;
else cout <<setw(6)<< size_arr1[j]<<setw(20)<<duration*1000000<<setprecision(10)<< endl;}
cout<<endl;}}
return 0;
}