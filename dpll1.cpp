#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<iterator>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef map<int,int> mi;
#define all(v) v.begin(),v.end()
#define f1(c, x)(find(all(c), x) != c.end())
#define pb push_back

mi m1;

vi check(vvi cnf){
    for(auto i:cnf){
        if(i.size()==1)
            return i;
    }
    vi v;
    v.pb(0);
    return v;
}

bool dpll(vvi cnf,mi m){
    while((check(cnf))[0]!=0){
        vi j=check(cnf);
        int k=j[0];
        if(m.find(-k)!=m.end())
            return false;
        m[k]=1;
        auto it=cnf.begin();
        for(auto i:cnf){
            if(f1(i,k)){
                cnf.erase(it);
            }
            else if(f1(i,-k)){
                i.erase(find(all(i),-k));
                *it=i;
            }
            it++;
        }
        
    }
    
    if(cnf.empty()){
        m1=m;
        return true;
    }
    for(auto i:cnf){
        if(i.empty())
            return false;
    }
    vvi cnf1=cnf,cnf2=cnf;
    vi v,v1;
    v.pb(cnf[0][0]);
    v1.pb(-cnf[0][0]);
    cnf1.pb(v);
    cnf2.pb(v1);
    return dpll(cnf1,m) || dpll(cnf2,m);
}


int main(){
    int i,j,k;
    int clauses, literals, removed;
    vvi claus;
    freopen("testcases/uf20-01.cnf", "r", stdin);
    string x;
    char y[1000000];
    while(1){
        scanf("%[^\n]%*c", y);
        if(y[0]=='c')
            continue;
        if(y[0]=='p'){
            istringstream stream(y);
            vector<string>y1((istream_iterator<string>(stream)),istream_iterator<string>());
            clauses=stoi(y1[3]);
            literals=stoi(y1[2]);
        }
        claus.resize(clauses);
        for(i =0;i< clauses;i++){
            scanf("%[^\n]%*c", y);
            if(y[0]=='c'){
               i--;
               continue;
            }
            else{
                istringstream stream(y);
                vector<string>y2((istream_iterator<string>(stream)),istream_iterator<string>());
                int n = y2.size();
                for(j=0;j<n;j++){
                    int prop = stoi(y2[j]);
                    if(prop!=0){
                        claus[i].push_back(prop);   
                    }
                }    
            }     
        }
        break;
    }
    for(i=0;i<clauses;i++){
        sort(claus[i].begin(),claus[i].end());
    }
    int init_clauses = clauses;
    vvi init_claus = claus;
    clauses=claus.size();
    mi m;
    bool z=dpll(claus,m);
    cout<<z<<endl;
    for(int i=1;i<=literals;i++){
        if(m1.find(i)==m1.end())
            cout<<-i<<' ';
        else
            cout<<i<<' ';
    }
    return 0;
}