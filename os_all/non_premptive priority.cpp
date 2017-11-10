#include<bits/stdc++.h>
using namespace std;
struct process{
	int pri,pid,at,bt,ct,tat,wt,rt,flag;
	process(){
		this->flag=false;
	}
};
int next(vector<process>p,int ct)
{
	int n=p.size();
	int index=-1,max_p=0;
	for(int i=0;i<n;i++)
	{
		if(!p[i].flag&&p[i].at<=ct)
		{
			if(p[i].pri>max_p)
			{
				index=i;
				max_p=p[i].pri;
			}
		}
	}
	return index;
}
int main()
{
	int n;
	cout<<"enter no of process:";
	cin>>n;
	vector<process>p(n);
	for(int i=0;i<n;i++)
	{
		cin>>p[i].pri>>p[i].pid>>p[i].at>>p[i].bt;
	}
	int ct=0;
	float avg_wt=0,avg_tat=0;
	vector<pair<int,int> >gun;
	for(int i=0;i<n;i++)
	{   
		int ind=next(p,ct);
		if(ind!=-1){
		gun.push_back(make_pair(p[ind].pid,ind));
		p[ind].flag=true;
		p[ind].rt=ct;
		ct=ct+p[ind].bt;
		p[ind].ct=ct;
		p[ind].tat=p[ind].ct-p[ind].at;
		p[ind].wt=p[ind].tat-p[ind].bt;
		avg_wt+=p[ind].wt;
		avg_tat+=p[ind].tat;
	    }
	    else
	    {
	    	ct++;
	    	i--;
		}
	}
	cout<<"gantt chart:";
	for(int i=0;i<gun.size();i++)
	  cout<<gun[i].first<<" ";
	  cout<<endl;
	cout<<"pri\tpid\tat\tbt\tct\ttat\twt\trt\n";
	for(int j=0;j<gun.size();j++)
	{   int i=gun[j].second;
		cout<<p[i].pri<<"\t";
		cout<<p[i].pid<<"\t";
		cout<<p[i].at<<"\t";
		cout<<p[i].bt<<"\t";
		cout<<p[i].ct<<"\t";
		cout<<p[i].tat<<"\t";
		cout<<p[i].wt<<"\t";
		cout<<p[i].rt<<"\t";
		cout<<endl;
	}
	avg_wt=avg_wt/n;
	avg_tat=avg_tat/n;
	cout<<"average waiting time:"<<avg_wt<<endl;
	cout<<"average tat time:"<<avg_tat<<endl;
}
