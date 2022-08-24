#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define FOR(i,a)    for(int i = 0; i < a; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
int inf=1e9+7, MOD=1e9+7;

int w = 1;

struct Tree{
    public :
            bool isResourceInUse; 
        bool isLocked;
        bool isLockable;
        int id;
        int ma;
        Tree* p;
        vector<Tree*> c; 
        Tree(){
            isLocked = false;
            isLockable = true;
            id = -1;
            ma = w++;
            p = NULL;
        }
        Tree(Tree* parent){
            isLocked = false;
            isLockable = true;
            id = -1;
            ma = w++;
            p = parent;
        }
};
        // bool ll(Tree* n) return n->l;

        bool locking(Tree* n, int uuid){
                if(n->isResourceInUse) while(n->isResourceInUse);
            n->isResourceInUse = true;
            if(n->isLockable == false || (n->isLocked)) { n->isResourceInUse = false; return false;}
            
            Tree* T = n;
            queue<Tree*> q;
            vector<Tree*> st;
            st.push(T);
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                        if(x->isResourceInUse) while(x->isResourceInUse);
                        x->isResourceInUse = true;
                    st.push_back(x);
                    if(x->isLocked) {
                            for(int i = 0; i < st.size(); i++){
                            st[i]->isResourceInUse = false;
                        }
                            return false; 
                    }
                    q.push(x);
                }
            }
            n->id = uuid;
            n->isLocked = true;
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    x->isLockable = false;
                    q.push(x);
                    x->isResourceInUse = false;
                }
            }
            n->isResourceInUse = false;
            return true;
        }
        
        bool unlocking(Tree* n,int uuid){
                if(n->isResourceInUse) while(n->isResourceInUse);
            n->isResourceInUse = true;
            if(n->isLockable == false || n -> isLocked == false || (n->isLocked && uuid != n->id)) { 
                    n->isResourceInUse = false; 
                return false; 
            }
            Tree* T = n;
            n->isLocked= false;
            n->id = -1;
            queue<Tree*> q;
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                        if(x->isResourceInUse) while(x->isResourceInUse);
                    x->isLockable = true;
                    q.push(x);
                }
            }
            n->isResourceInUse = false; 
            return true;
        }
                
        void unblockResource(Tree* n){
                queue<Tree*> q;
            q.push(n);      
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                        x->isResourceInUse = false;
                    q.push(x);
                }
            }
        }
                
        bool update(Tree* n,int uuid){
                if(n->isResourceInUse) while(n->isResourceInUse);
            n->isResourceInUse = true;
            if(n->isLockable == false || n->isLocked == true) {
                    n->isResourceInUse = false;
                return false;
            }
            Tree* T = n;
            queue<Tree*> q;
            q.push(T);
            vector<Tree*> st;
            st.push(T);
            bool f = false;
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                        if(x->isResourceInUse) while(x->isResourceInUse);
                        x->isResourceInUse = true;
                    st.push_back(x);
                    if(x->isLocked == true && x->id != uuid) { 
                            for(int i = 0; i < st.size(); i++){
                            st[i]->isResourceInUse = false;
                        }
                        return false; 
                    }
                    if(x->isLocked) f = true;
                    q.push(x);
                }
            }
            if(!f) {
                    for(int i = 0; i < st.size(); i++){
                    st[i]->isResourceInUse = false;
                    }
                    return false;
            }
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                        if(x->isResourceInUse) while(x->isResourceInUse);
                    if(x->isLocked){
                            unblockResource(x);
                        if(x->isResourceInUse) while(x->isResourceInUse);
                        unlocking(x,uuid)
                    }
                    x->isResourceInUse = false;
                    q.push(x);
                }
            }
            if(n->isResourceInUse) while(n->isResourceInUse);
            return locking(n,uuid);
        }

        void Print(Tree* n){
            queue<Tree*> q;
            q.push(n);
            // cout << n->ma <<"\n";
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    cout << temp->ma << " -> " << x->ma << " ";
                }
            }
        }

unordered_map<string, Tree*> sToT;


int main(){
    int n,m,q;
    cin >> n >> m >>q;
    // adj.resize(n+1,vector<int>());
    // nuid.resize(n+1,-1);
    // p.resize(n+1,-1);
    // intime.resize(n+1,-1);
    // outtime.resize(n+1,-1);
    // p[1]=1;
    // int x = n/m;
    // for(int k = 1; k <= x; k++){
    //     for(int l = 1; l <= m; l++){
    //         adj[k].pb(m*(k-1)+l+1);
    //         p[m*(k-1)+l+1] = k;
    //     }
    // }
    // FOR(i,adj.size()) {
    //     FOR(j,p.size()) cout << j << " " <<p[j] <<" "; 
    //     cout <<"\n";
    // }
    
    Tree* t = new Tree(); 
    string d;
    cin >> d;

    // a.c.push_back(&t);
    sToT[d] = t;
    queue<Tree*> queue;
    queue.push(t);
    int k = 1;
    while(!queue.empty()){
        auto temp = queue.front();
        queue.pop();
        // cout << temp->ma <<"\n";
        while(k < n && (int)temp->c.size() < m){
            string s;
            cin >> s;
            // cout << s <<"\n";
            Tree* u = new Tree(temp);
            sToT[s] = u;
            temp->c.push_back(u);
            queue.push(u);
            k++;
            // cout << s <<" "<<sToT[s]->ma <<"\n";
        }
    }
    // Print(t);
    // dfs(1);
    FOR(i,q) {
        int qn,uuid;
        string name;
        bool ans;
        cin >> qn >> name >> uuid;
        if(qn == 1){
            ans = locking(sToT[name],uuid);
            // cout << name<<" "<< sToT[name]->id << " " << uuid << "\n";
        }
        else if(qn == 2){
            ans = unlocking(sToT[name],uuid);
            // cout << name<<" "<< sToT[name]->id << " " << uuid << "\n";
        }
        else {
            ans = update(sToT[name],uuid);
            // cout << ans << "\n";
        }
        // FOR(j,nuid.size()) cout << j << " " << nuid[j] <<" ";
        // cout <<"\n";
        if(ans) cout << "true\n";
        else cout << "false\n";
    }
    return 0;
}




