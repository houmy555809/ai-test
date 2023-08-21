#include<bits/stdc++.h>
using namespace std;
int n,m;
double w[110][110];
double val[110];
bool out[110];
double u[110];
int id[110],cur;
int ideg[110],cideg[110],odeg[110];
bool vis[110];
const double e=2.71828;
inline double f(double out){
    return 2.0/(pow(e,-out*1.5)+1)-1.0;
}
int main(){
    memset(out,1,sizeof(out));
    ifstream fin("data.txt");
    fin>>n>>m;
    for(int i=1;i<=n;i++){
    	fin>>u[i];
        cin>>val[i];
    }
    queue<int> q;
    for(int i=1;i<=m;i++){
        int from,to;
		double weight;
        fin>>from>>to>>weight;
        if(weight!=0){
            ideg[to]++;
            odeg[from]++;
            out[from]=false;
            w[from][to]=weight;
        }
    }
    for(int i=1;i<=n;i++){
        if(ideg[i]==0){
            q.push(i);
            vis[i]=true;
        }
        cideg[i]=ideg[i];
    }
    while(!q.empty()){
        int cv=q.front();
        q.pop();
        id[cur++]=cv;
        for(int i=1;i<=n;i++){
            if(w[cv][i]!=0){
                cideg[i]--;
                if(cideg[i]==0){
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        int cv=id[i];
        if(ideg[cv]==0)continue;
        double outp=0;
        for(int j=1;j<=n;j++){
            if(w[j][cv]&&val[j]>=0){
                outp+=w[j][cv]*val[j];
            }
        }
        val[cv]=f(outp-u[cv]);
    }
    for(int i=1;i<=n;i++){
        if(out[i]){
            cout<<val[i]<<endl;
        }
    }
}
