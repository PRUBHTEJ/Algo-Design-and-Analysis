#include <bits/stdc++.h>
#include<time.h>
 using namespace std; 
 #define d 256 
 void search(string pat,string txt, int q) {
  int M = pat.length();
   int N = txt.length(); 
   int i, j; 
   int p = 0; 
   int t = 0; 
   int h = 1;
   for (i = 0; i < M - 1; i++) 
   h = (h * d) % q; 
   for (i = 0; i < M; i++) {
    p = (d * p + pat[i]) % q; 
    t = (d * t + txt[i]) % q; 
    }
     for (i = 0; i <= N - M; i++) { 
     if ( p == t ) {
      for (j = 0; j < M; j++) { 
      if (txt[i+j] != pat[j]) 
      break; 
      } 
      if (j == M)
       cout<<"Pattern found at index "<< i<<endl;
        } 
        if ( i < N-M ) 
        { 
        t = (d*(t - txt[i]*h) + txt[i+M])%q;
         if (t < 0) t = (t + q);
          } 
          } 
          }
int main() 
{ clock_t start, end;
cout<<"Enter the string and the pattern\n";
 string pat,txt; 
 cin>>txt>>pat; 
 int q = 101; 
 start  = clock();
 search(pat, txt, q); 
 end = clock();
 cout<<endl;
 cout<<"Time taken is: "<<double(end-start)/double(CLK_TCK);
 return 0; 
}