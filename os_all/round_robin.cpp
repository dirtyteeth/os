#include<bits/stdc++.h>
using namespace std;
int wt[105],rem_bt[105],ft[105],rt[105];
struct process{
    int id,at,bt,tat;
};
bool cmp(process a,process b){
        return a.at<b.at;
}
bool cmp1(process a,process b){
        return a.id<b.id;
}
int main(){
    int cs = -1 ;
    int n,quant,i;
    cout<<"enter the no. of processes & quantum value: ";
    cin>>n>>quant;
    vector<process> v(n);
    cout<<"enter the process id,arrival time & burst time: ";
    for(i=0;i<n;i++)
        cin>>v[i].id>>v[i].at>>v[i].bt;
cout<<"Sequence of execution:"<<endl;
    sort(v.begin(),v.end(),cmp);
for(i=0;i<n;i++)
        rem_bt[v[i].id]=v[i].bt;
int done=0,t=0,j=0;
    queue<process> q;
    while(j<n&&v[j].at<=t)
        q.push(v[j++]);
    while(done<n){
        if(!q.empty()){
            process tp=q.front();
            q.pop();
            int id=tp.id;          
cout << id << "-> " ; cs++ ;
            if(rem_bt[id]==tp.bt)
                rt[id]=t-tp.at;
            if(rem_bt[id]>quant){
                rem_bt[id]-=quant;
                t+=quant;
            }
            else{
                t+=rem_bt[id];
                rem_bt[id]=0;
                done++;
                ft[id]=t;
                wt[id]=ft[id]-tp.at-tp.bt;
            }
            while(j<n&&v[j].at<=t)
                q.push(v[j++]);
            if(rem_bt[id])
                q.push(tp);
        }
        else{
            t++;
            while(j<n&&v[j].at<=t)
                q.push(v[j++]);
        }
    }
    int totTT=0,totWT=0,totRT=0;
    cout << "END" <<endl ;
    cout<<"ID\tAT\tBT\tFT\tTAT\tWT\tRT\n";
    sort(v.begin(),v.end(),cmp1);
    for(i=0;i<n;i++){
        int id=v[i].id;
        v[i].tat=ft[id]-v[i].at;
        cout<<v[i].id<<'\t'<<v[i].at<<'\t'<<v[i].bt<<'\t'<<ft[id]<<'\t'<<v[i].tat<<'\t'<<wt[id]<<'\t'<<rt[id]<<endl;
        totWT+=wt[id],totTT+=v[i].tat,totRT+=rt[id];
    }
    cout<<"Avg. TAT: "<<totTT/(double)n<<endl;
    cout<<"Avg. WT: "<<totWT/(double)n<<endl;
    cout<<"No. of context switch: "<<cs<<endl;
    cout<<"Throughput : "<<n/(double)t<<endl;
    }

