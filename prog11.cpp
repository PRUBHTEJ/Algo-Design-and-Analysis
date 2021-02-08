#include<bits/stdc++.h>
#include<iostream>
#include<time.h>
#include<unistd.h>
using namespace std;
#define infinity 9999
#define MAX 20
int g[MAX][MAX], spanning[MAX][MAX], n;
int prims(){
    int cost[MAX][MAX];
    int u, v, min_dist, distance[MAX], from[MAX], min_cost;
    int visited[MAX], edges, i, min, j;
    for(i=0; i<n; i++)
        for(j=0; j<n;j++){
            //sleep(5);
            if(g[i][j]==0)
                cost[i][j]=infinity;
            else
                cost[i][j]=g[i][j];
            spanning[i][j]=0;

        }
        distance[0]=0;
        visited[0]=1;
        for(i=1; i<n;i++){
            distance[i] = cost[0][i];
            from[i]=0;
            visited[i]=0;

        }

        min_cost = 0;
        edges = n-1;
        while(edges>0){
            min_dist = infinity;
            for(i=0; i<n; i++)
                if(visited[i]==0&&distance[i]<min_dist){
                    v=i;
                    min_dist = distance[i];
                }

                u = from[v];
                spanning[u][v] = distance[v];
                spanning[v][u] = distance[v];
                edges--;
                visited[v]=1;
                for(i=1; i<n; i++)
                    if(visited[i]==0&&cost[i][v]<distance[i]){
                        distance[i] = cost[i][v];
                        from[i] = v;

                    }
                    min_cost = min_cost+cost[u][v];
                }
            return (min_cost);

}

int main(){
    clock_t start, end;
    int i, j, total_cost;
    cout<<"Enter the no. of vertices";
    cin>>n;
    cout<<"Enter the adjecency matrix";
    for(i=0; i<n;i++)
        for(j=0; j<n;j++)
            cin>>g[i][j];
        start = clock();
        total_cost = prims();
        cout<<"spanning tree matrix: ";
        cout<<endl;
        end = clock();
        for(i = 0; i<n; i++){
            for(j=0; j<n; j++){
                cout<<spanning[i][j]<<"\t";
              }
              cout<<endl;

        }

        cout<<"Time taken is: "<<double(end-start)/double(CLK_TCK);
        cout<<endl;
        cout<<"Total cost of spanning tree is: "<<total_cost;

        }