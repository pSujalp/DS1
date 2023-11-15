#include<bits/stdc++.h>
using namespace std;

class PQ
{
    private:
    vector<int>v;
    public:

    bool isEmpty()
    {
        return v.size()==0;
    }
    int getsize()
    {
        return v.size();
    }
    void insert(int d)
    {
        v.push_back(d);
        int ci=v.size()-1;
        while(ci>0)
        {
            int pi=(ci-1)/2;
            if(v[pi]>v[ci])
            {
                swap(v[ci],v[pi]);
                ci=pi;
            }
            else break;
        }
    }
    int top()
    {
        if(v.size()==0) return INT_MIN;

        return *(v.begin());
     }

     void pop()
     {
        if(v.size()==0) return;

        if(v.size()==1)
        {
             v.pop_back();
             return;
        }

        swap(v[v.size()-1],v[0]);
        v.pop_back();
        int pi=0;

        while(pi!=v.size()-1)
        {
            int ci1=2*pi+1;
            int ci2=2*pi+2;
            int mini=pi;
            
            if(ci1<v.size() && v[ci1]<v[mini]) mini=ci1;

            if(ci2<v.size() && v[ci2]<v[mini]) mini=ci2;

            if(pi==mini) break;

            swap(v[pi],v[mini]);
            pi=mini;
        }
     }

};

class PQM
{
    private:
    vector<int>v;
    public:

    bool isEmpty()
    {
        return v.size()==0;
    }
    int getsize()
    {
        return v.size();
    }
    void insert(int d)
    {
        v.push_back(d);
        int ci=v.size()-1;
        while(ci>0)
        {
            int pi=(ci-1)/2;
            if(v[pi]<v[ci])
            {
                swap(v[ci],v[pi]);
                ci=pi;
            }
            else break;
        }
    }
    int top()
    {
        if(v.size()==0) return INT_MIN;

        return *(v.begin());
     }

     void pop()
     {
        if(v.size()==0) return;

        if(v.size()==1)
        {
             v.pop_back();
             return;
        }

        swap(v[v.size()-1],v[0]);
        v.pop_back();
        int pi=0;

        while(pi!=v.size()-1)
        {
            int ci1=2*pi+1;
            int ci2=2*pi+2;
            int mini=pi;
            
            if(ci1<v.size() && v[ci1]>v[mini]) mini=ci1;

            if(ci2<v.size() && v[ci2]>v[mini]) mini=ci2;

            if(pi==mini) break;

            swap(v[pi],v[mini]);
            pi=mini;
        }
     }

};

int main()
{
    PQM q;

    q.insert(4);
    q.insert(5);
    q.insert(9);
    q.insert(888);
    q.insert(987);
    q.pop();
    q.pop();
    

    cout<<q.top();
}