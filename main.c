#include<stdio.h>

void dijikstras(int cost[50][50], int n, int src)
{
    int ne=1,i,j,distance[50],visited[50],min,pred[50],node;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        distance[i]=cost[src][i];
        pred[i]=src;
    }
    visited[src]=1;
    distance[src]=0;
    while(ne<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            if(distance[i]<min &&!visited[i])
            {
                min=distance[i];
                node=i;
            }
        }
        visited[node]=i;
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                if(min+cost[node][i]<distance[i])
                {
                    distance[i]=min+cost[node][i];
                    pred[i]=node;
                }
            }
        }
        ne++;
    }
    for(i=1;i<=n;i++)
    {
        if(i!=src)
        {
            printf("\nDistance of %d from %d is %d\n",i,src,distance[i]);
            printf("Path = %d",i);
            j=i;
            do
            {
                j=pred[j];
                printf(" <- %d",j);
            }
            while(j!=src);
        }
    }
}


void main()
{
    int n,cost[50][50],i,j,src;
    printf("Enter the nodes\n");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    printf("Enter the source node\n");
    scanf("%d",&src);
    dijikstras(cost,n,src);
}