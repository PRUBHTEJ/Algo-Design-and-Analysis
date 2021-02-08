#include<bits/stdc++.h>
#include<time.h>
#include<unistd.h>
using namespace std;
int cost[10][10], i, j, k, stk[10], visit[10], visited[10],top,v, u;

int main(){
    clock_t start, end;
    int n, m, c;
    cout<<"Enter no. of vertices";
    cin>>n;
    cout<<endl;
    cout<<"Enter no. of edges";
    cin>>m;
    cout<<endl;
    cout<<"Edges Cost: ";
    for(k=1; k<=m; k++){
        cin>>i>>j>>c;
        cost[i][j] = c;

    }
    start = clock();
    for(i=1; i<=n; i++)
        for(j=1; j<=n;j++)
            if (cost[i][j]==0)
                cost[i][j]=31999;
            cout<<"Order of visited vertices";
            cout<<endl;
            k=1;
            while(k<n){
                m=31999;
                if(k==1){
                    for(i=1; i<=n;i++)
                    for(j=1;j<=n;j++)
                        if(cost[i][j]<m){
                            m=cost[i][j];
                            u=i;
                        }
                }

                else{

                    for(j=n; j>=1; j--)
                        if(cost[v][j]<m&&visited[j]!=1&&visit[j]!=1){
                            visit[j] = 1;
                            stk[top] = j;
                            top++;
                            m = cost[v][j];
                            u = j;
                        }
                }
                cost[v][u] = 31999;
                v = u;
                cout<<v<<" ";
                cout<<endl;
                k++;
               // sleep(200);
                visit[v] = 0;
                visited[v] = 1;

            }
            end = clock();
            cout<<"Time Taken is: "<<double(end-start)/double(CLK_TCK);

}
