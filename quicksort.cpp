#include<stdio.h>
#include<stdlib.h> 
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int partition(vector<int>&v,int start, int end)
{
    int index = end;
    int i = start;
    for(int j =i;j<end;j++)
    {
        if(v[j]<v[index])
        {
            swap(v[i],v[j]);
            i++;
        }
    }
    swap(v[i],v[end]);
    return i++;
}

void quicksort(vector<int> &v, int start, int end)
{
    if(start<end)
    {
        int pindex = partition(v,start,end);
        quicksort(v,start,pindex-1);
        quicksort(v,pindex+1,end);
    }
}

int main() 
{ 
    //vector<int> v = {3,4,9,8,2,5,1,7,3,4,4,5,2};
    vector<int> v;
    v.push_back(1);
    quicksort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
} 
