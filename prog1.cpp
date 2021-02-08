#include <bits/stdc++.h>
using namespace std;

void insertionS(int arr[], int n)
{ int i, key, j;
for (i = 1; i < n; i++)
    { key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key)
     { arr[j + 1] = arr[j];
       j = j - 1;
      }
arr[j + 1] = key;
    }
}

int main()
{ int size_arr[]={10,100,1000,2000,3000,4000,5000,6000,7000,8000,9000};
string cases[]={"BEST","WORST"};
cout<<"For Insertion Sort: ";
cout<<"\n\n";
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
float start,end;
// auto start = high_resolution_clock::now();
start=clock();
insertionS(arr,n);
//auto stop = high_resolution_clock::now();
end=clock();
double duration=double(end-start)/double(CLOCKS_PER_SEC);
cout <<setw(6)<< size_arr[j]<<setw(20)<<duration*1000000<<setprecision(10)<< endl;}
cout<<endl;
}
return 0;
}
