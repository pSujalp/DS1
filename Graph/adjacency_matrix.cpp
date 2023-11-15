#include<iostream>
#include<vector>
#include<unordered_set>
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>mat,int sv,vector<bool>&v)
{

   cout<<sv<<" ";
   v[sv]=true;
   int n=mat.size();
   int i=0;
   for(i=0;i<n;i++)
   {
      if(mat[sv][i]==1 && v[i]==false)
      {
         DFS(mat,i,v);
      }
   }
}

void DFSForDisConnectedGraph(vector<vector<int>>mat)
{
   int n=mat.size();
   vector<bool>v(n,false);

   for(int i=0;i<v.size();i++)
   {
      if(v[i]==false)
      {
         DFS(mat,i,v);
      }


   }
}

void BFS(vector<vector<int>>mat,int sv,vector<bool>&v)
{

   queue<int>q;
   q.push(sv);
   v[sv]=true;
   while(!q.empty())
   {
      int f=q.front();
      q.pop();
      cout<<f<<" ";
      for(int i=0;i<mat.size();i++)
      {
         if(mat[f][i]==1 && v[i]==false)
         { 
            q.push(i);
            v[i]=true;
         }
      }
      
   }

}

void BFSforDisconnectedGraph(vector<vector<int>>mat)
{
   vector<bool>v((int)mat.size(),false);

   for(int i=0;i<mat.size();i++)
   {
      if(v[i]==false)
      {
         BFS(mat,i,v);
      }
   }
}
int main()
{
   int n,e;
   cout<<"Enter the number of nodes";
   cin>>n;
   cout<<"Enter the no of edges";
   cin>>e;

   vector<vector<int> > matrix(n,vector<int>(n,0));

   for(int i=1;i<=e;i++)
   {
      cout<<"Connected edge"<<endl;
    int fv,sv;
    cin>>fv;
    cin>>sv;
    cout<<endl;
    matrix[fv][sv] = 1;
    matrix[sv][fv] = 1;
   }
   
   //BFS(matrix,0);

   BFSforDisconnectedGraph(matrix);
   
   return 0;
}