#include<bits/stdc++.h>
using namespace std;

struct task
{
	int at;
	int bt;
};
bool fn(task a,task b)
{
	if(a.at<b.at)
	return true;
	if(a.at==b.at)
	{
		if(a.bt<b.bt)
		return true;
		else
		return false;
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	task t[n];
	for(int i=0;i<n;i++)
	{
		cin>>t[i].at>>t[i].bt;
	}
	sort(t,t+n,fn);
	int ct[n];
	int tat[n];
	int wt[n];
	ct[0] =  t[0].at + t[0].bt;
	tat[0] = ct[0]-t[0].at;
	wt[0] = tat[0]-t[0].bt;
	for(int i=1;i<n;i++)
	{
		ct[i] = ct[i-1] + t[i].bt;
		tat[i] = ct[i]-t[i].at;
		wt[i] = tat[i]-t[i].bt;
		if(wt[i]<0)
		wt[i]=0;
	}
	cout<<"AT \t"<<"BT\t "<<"CT \t"<<"TAT\t "<<"WT \t"<<endl;
	int avtat=0;
	int avwt=0;
	for(int i=0;i<n;i++)
	{
		cout<<t[i].at<<"\t "<<t[i].bt<<"\t "<<ct[i]<<"\t "<<tat[i]<<"\t "<<wt[i]<<endl;
		avtat+=tat[i];
		avwt+=wt[i];
	}
	cout<<(float)avtat/n<<" "<<(float)avwt/n<<endl;
	
}
