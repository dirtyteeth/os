#include<bits/stdc++.h>
using namespace std;
void print(deque<int>v)
{
 deque<int>::iterator it=v.begin();
 while(it!=v.end())
 {
    cout<<*it<<" ";
    it++;
 }
 cout<<endl;
}
int fifo(vector<int>v,int nf)
{
  int np=v.size();
  deque<int>mem;
  for(int j=0;j<nf;j++)
  { 
    mem.push_back(v[j]);
    print(mem);
  }
    //print(mem);
    int cnt=nf;
    
  for(int i=nf;i<np;i++)
  {
    if(find(mem.begin(),mem.end(),v[i])==mem.end())
    { 
    	mem.pop_front();
    	mem.push_back(v[i]);
    	cnt++;
    }
    print(mem);
  }
  cout<<"fifo:"<<cnt<<endl;
}
int lru(vector<int>v,int nf)
{
  int np=v.size();
  deque<int>mem;
  for(int j=0;j<nf;j++){
    mem.push_front(v[j]);
    print(mem);
    }
    int cnt=nf;
    deque<int>::iterator it;
   for(int i=nf;i<np;i++)
  { it=find(mem.begin(),mem.end(),v[i]);
    if(it==mem.end())
    { 
    	mem.pop_back();
    	mem.push_front(v[i]);
    	cnt++;
    	print(mem);
    }
    else
    {
        mem.erase(it);
        mem.push_front(v[i]);
        print(mem);
    }
  }
    cout<<"lru:"<<cnt<<endl;
}
int mru(vector<int>v,int nf)
{
	int np=v.size();
  deque<int>mem;
  for(int j=0;j<nf;j++){
    mem.push_back(v[j]);
    print(mem);
    }
    int cnt=nf;
    deque<int>::iterator it;
   for(int i=nf;i<np;i++)
  { it=find(mem.begin(),mem.end(),v[i]);
    if(it==mem.end())
    { 
    	mem.pop_back();
    	mem.push_back(v[i]);
    	cnt++;
    	print(mem);
    }
    else
    {
        mem.erase(it);
        mem.push_back(v[i]);
        print(mem);
    }
  }
    cout<<"mru:"<<cnt<<endl;
    
}
int main()
{
	int nf,np;
	cout<<"enter no of page:";
	cin>>np;
	cout<<"enter no of frame:";
	cin>>nf;
	vector<int>v(np);
	for(int i=0;i<np;i++)
	 cin>>v[i]; 
	 fifo(v,nf);
	 lru(v,nf);
	 mru(v,nf);
}
