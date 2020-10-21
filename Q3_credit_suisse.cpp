#include<bits/stdc++.h>
using namespace std;
string find_min_days(int val, int price[], int n)
{
    string re = "";
    int l=0,r=sqrt(INT_MAX);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if( val==(price[j]-price[i])  && j<=r && i>=l)
            {
                l = i;
                r = j;
                break;
            }
        }
    }
    if( r-l!=INT_MAX ) re += to_string(l+1) + " " + to_string(r+1);
    else re += "-1";
    return re;
}

int main ()
{
	int n,d,i;
	string answer="";
	string result = "";
	int flag  = 0;
	cin>>n>>d;
	int price[n];
	int profit[d];
	for (i=0;i<n;i++)
		cin>>price[i];
	for (i=0;i<d;i++)
	    cin>>profit[i];
	
	for(int i=0;i<d;i++)
	{
        result = find_min_days(profit[i],price,n);
        if(flag==0 )
        {
            answer = result;
            flag = 1;
        }
        else if(flag==1 )
        {
            answer += "," + result;
        }
    }
    // Do not remove below line
	cout<<answer<<endl;
    // Do not print anything after this line

	return 0;
}