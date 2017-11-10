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
	else
	return false;
}
bool fn1(task a,task b)
{
	if(a.bt<b.bt)
	return true;
	else
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
	int CT;
	CT = t[0].bt + t[0].at;
	vector<task> ans;
	for(int i=1;i<n;i++)
	{
		if(t[i].at<CT)
		ans.push_back(t[i]);
	}
	sort(ans.begin(),ans.end(),fn1);
	int ct[n];
	int tat[n];
	int wt[n];
	ct[0] = CT;
	tat[0] = ct[0]-t[0].at;
	wt[0] = tat[0]-t[0].bt;
	for(int i=0;i<n-1;i++)
	{
		ct[i+1] = ct[i] + ans[i].bt;
		tat[i+1] = ct[i+1]-ans[i].at;
		wt[i+1] = tat[i+1]-ans[i].bt;
	}
	cout<<"AT \t"<<"BT\t "<<"CT \t"<<"TAT\t "<<"WT \t"<<endl;
	int avtat=tat[0];
	int avwt=wt[0];
	
	cout<<t[0].at<<"\t "<<t[0].bt<<"\t "<<ct[0]<<"\t "<<tat[0]<<"\t "<<wt[0]<<endl;
	for(int i=0;i<n-1;i++)
	{
		cout<<ans[i].at<<"\t "<<ans[i].bt<<"\t "<<ct[i+1]<<"\t "<<tat[i+1]<<"\t "<<wt[i+1]<<endl;
		avtat+=tat[i+1];
		avwt+=wt[i+1];
	}
	cout<<(float)avtat/n<<" "<<(float)avwt/n<<endl;
	
			
	
}
