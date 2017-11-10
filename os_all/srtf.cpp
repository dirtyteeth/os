#include<bits/stdc++.h>
using namespace std;
int wt[105],rem_bt[105],ft[105],rt[105];
struct process{
    int id,at,bt,tat,wt,ft,rem_bt;
};
bool cmp(process a,process b){
        return a.at<b.at;
}
bool cmp1(process a,process b){
        return a.id<b.id;
}
int main(){
    int past = 0 ;    
    int n,quant=1,i,j;int cs = 0;
    cout<<"enter the no. of processes: ";
    cin>>n;
int flag[n] ;
int restime[n];
for(int i = 0 ; i < n ;i++) flag[i] = 0 ;
    vector<process> v(n);
    cout<<"enter the process id,arrival time & burst time: ";
    for(i=0;i<n;i++){
        cin>>v[i].id>>v[i].at>>v[i].bt;
        v[i].rem_bt=v[i].bt;
    }
    cout <<"\nSEQUENCE of Execution: " <<endl;
    int done=0,t=0;
    while(done<n){
        int min_id=-1,mm=INT_MAX;
        for(i=0;i<n;i++){
            if(v[i].at<=t&&v[i].rem_bt!=0&&v[i].rem_bt<mm){
                mm=v[i].rem_bt;
                min_id=i;
            }
        }
if(min_id!=-1){
if(flag[min_id]==0)
{
    restime[min_id] = t ;
    flag[min_id] = 1 ;
}
    if(past!=v[min_id].id)   
                {
                    cout << v[min_id].id << " -> " ;
                    past = v[min_id].id;cs ++;
                }
            if(v[min_id].rem_bt>quant){
                    v[min_id].rem_bt-=quant;
       
                    t+=quant;
            }
            else{
                    t+=v[min_id].rem_bt;
                    v[min_id].rem_bt=0;
                    done++;
                    v[min_id].ft=t;
                    v[min_id].wt=v[min_id].ft-v[min_id].at-v[min_id].bt;
            }
        }
        else
            t++;
    }
int totTT=0,totWT=0;
       cout << "END " <<endl ;
    cout<<"ID\tAT\tBT\tFT\tTAT\tWT\n";
    sort(v.begin(),v.end(),cmp1);
    for(i=0;i<n;i++){
        v[i].tat=v[i].ft-v[i].at;
        cout<<v[i].id<<'\t'<<v[i].at<<'\t'<<v[i].bt<<'\t'<<v[i].ft<<'\t'<<v[i].tat<<'\t'<<v[i].wt<<endl;
        totWT+=v[i].wt,totTT+=v[i].tat;
    }
    cout<<"Avg. TAT: "<<totTT/(double)n<<endl;
    cout<<"Avg. WT: "<<totWT/(double)n<<endl;
    cout << "Response Time  : " << endl ;
    for(int i = 0 ; i < n ; i ++ )
    {
    cout << i+1 << "->" <<  restime[i]-v[i].at <<endl ; 
        }
    cout << "Throughput  : " << n/(double)t <<endl ;
    cout << "No. of context switch: " << cs-1 << endl ;
}

