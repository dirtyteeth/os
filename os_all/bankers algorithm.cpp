#include<bits/stdc++.h>
using namespace std;
struct pro{
	int maxn[3];
	int calloc[3];
	int rem[3];
};
pro p[100];
bool v[100];
void cal(int n,int z,int a,int b,int c,string ans)
{
	if(z==n)
	{
		for(int i=0;i<n;i++)
		cout<<ans[i]<<"->";
		cout<<endl;
		return;
	}
	for(int j=0;j<n;j++)
		if(v[j]==false&&p[j].rem[0]<=a&&p[j].rem[1]<=b&&p[j].rem[2]<=c){
			v[j]=true;
			int x=j+48;
			char ch=x;
		cal(n,z+1,a+p[j].calloc[0],b+p[j].calloc[1],c+p[j].calloc[2],ans+ch);
		   v[j]=false;
		}
	}
int main(){
	int n;
	cout<<"enter the total no. of process:";
	cin>>n;
	cout<<"enter the max matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		  	cin>>p[i].maxn[j];
	}
	cout<<"enter the current allocation matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>p[i].calloc[j];
			p[i].rem[j]=p[i].maxn[j]-p[i].calloc[j];
		}  	
	}
	int a,b,c;
	cout<<"enter the current available value:";
	cin>>a>>b>>c;
	string ans="";
	cal(n,0,a,b,c,ans);      
			
}
