
/*


    
    Solution by Rahul Surana
    

    ************************************************************************



Locking the tree of space


You have a world map represented as an M-Ary tree (sample tree below)


 

You need to define three operations on it


	lock(X, uid)
	unlock(X, uid)
	upgradeLock(x, uid)


where X the name of a node in the tree (that would be unique) and uid is the user who is performing the operation

Here are the definitions for the Operations:

Lock(X, uid)

Lock takes an exclusive access on the subtree rooted at X. It is formally defined like this:<br>
Once lock(X, uid) succeeds, then:


	lock(A, anyUserId) should fail (returns false), where A is a descendent of X,
	lock(B, anyUserId) should fail (returns false), where X is a descendent of B
	Lock operation cannot be performed on a node which is already locked i.e. lock(X, anyUserId) should fail (returns false).


Unlock(X, uid)


	Unlock reverts what was done by the Lock operation. It can only be called on same node on which user uid had called a Lock on before. Returns true if it is successful.


UpgradeLock(X, uid)


	It helps the user uid upgrade their lock to an ancestor node. It is only possible if the node X already has locked descendants and all of them are only locked by the same user uid. Upgrade should fail if there is any node which is descendant of X that is locked by a different user. Successful Upgrade will 'Lock' the node. UpgradeLock call shouldn't violate the consistency model that Lock/Unlock function requires.


Notes

1) The number of nodes in the tree N is very large. So, optimize the time complexity for the above algorithms

2) The below section contains the input format.


	The first line contains the number of Nodes in the tree (N).
	The second line contains number of children per node (value m in m-ary Tree).
	The third line contains number of queries (Q).
	Next N lines contains the NodeName (string) in the m-Ary Tree.
	Next Q lines contains queries which are in format: OperationType NodeName UserId
	OperationType →<br>
	1 for Lock<br>
	2 for unlock<br>
	3 for upgradeLock
	NodeName → Name of any node (unique) in m-Ary Tree.
	UserId → Integer value representing a unique user.


Example input:

7

2

3

World

Asia

Africa

China

India

SouthAfrica

Egypt

1 China 9

2 India 9

3 Asia 9

    
With the above input you represents a 2-ary tree with 7 nodes as follows:

                      World

                  /             \

              Asia              Africa

            /      \          /          \ 

        China     India    SouthAfrica    Egypt

Additional Notes:

1) Here ‘1 China 3’ indicates the following ‘OperationType NodeName UserId’

2) The tree is always fully balanced

3) Constraints on the inputs are as follows<br>
        1 &lt; N &lt; 5 * 10^5<br>
        1 &lt; m &lt; 30<br>
        1 &lt; Q  &lt; 5 * 10 ^ 5<br>
        1 &lt; length of NodeName &lt; 20

4) Optimize the time complexity 


	Lock  - O(log<sub>m</sub>N)
	Unlock - O(log<sub>m</sub>N)
	UpgradeLock - O(numberOfLockedNodes * log<sub>m</sub>N)


5) Lock operation on already locked node should fail.

6) Once UpgradeLock(X,uid) succeeds on X. It is equivalent to X being locked by uid. So, Lock(A/B, anyuser) should fail as per the definition of Lock and Unlock(X, uid) should also work. <br>
7) Upgrade lock operation on a node having no locked descendants should fail and upgrade lock on already locked node should also fail.




    **************************************************************************




*/





















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
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
int inf=1e9+7, MOD=1e9+7;

// vector<vector<int>> adj;
map<int, Tree*> nToT;
map<string, int> sToI;
// vector<int> nuid;
// vector<int> p;

// vector<int> intime;
// vector<int> outtime;
// int timer = 0;

// bool isPurvaj(int a,int b){
//     return intime[a] > intime[b] && outtime[b] > outtime[a];
// }

// void dfs(int u){
//     intime[u] = timer++; 
//     for (auto x: adj[u]){
//         dfs(x);
//     }
//     outtime[u] = timer++;
// }

// bool df(int u){
//     if(nuid[u] != -1) return false;
//     bool ans = true;
//     for(auto x : adj[u]){
//         ans = df(x);
//         if(ans) break;
//     }
//     return ans;
// }

// void change(int u, int uuid){
//     nuid[u] = uuid;
//     for(auto x : adj[u]){
//         change(x,uuid);
//     }
// }

// bool lock(int nodeName,int uuid){
//     if(nuid[nodeName] != -1) return false;
//     bool ans = true;
//     for(auto x : adj[nodeName]){
//         // cout << x << "\n";
//         ans = df(x);
//         if(!ans) break;
//     }
//     if(ans){
//         nuid[nodeName] = uuid;
//         for(auto x : adj[nodeName]){
//             change(x,uuid);
//         }
//     }
//     return ans;
// }

// bool udf(int u, int uid){
//     if(nuid[u] != uid) return false;
//     bool ans = true;
//     for(auto x : adj[u]){
//         ans = udf(x,uid);
//         if(!ans) break;
//     }
//     return ans;
// }

// bool unlock(int nn, int uuid){
//     // cout << nuid[nn] << " " << nuid[p[nn]] <<" "<<uuid<<"\n"; 
//     if(nuid[nn] != uuid || nuid[p[nn]] == uuid) return false;
//     bool ans = true;
//     for(auto x: adj[nn]) {
//         ans = udf(x,uuid);
//         if(!ans) break;
//     }
//     if(ans){
//         nuid[nn] = -1;
//         for(auto x: adj[nn]) {
//             change(x,-1);
//         }
//     }
//     return ans;
// }

// bool uudf(int u, int id){
//     if(nuid[u] != -1 && nuid[u] != id) return false;
//     bool ans = true;
//     for(auto x: adj[u]) {
//         ans = uudf(x,id);
//         if(!ans) break;
//     }
//     return ans;
// }

// bool update(int nn, int uid){
//     if((nuid[nn] != -1) || nuid[p[nn]] != -1) return false;
//     bool ans = true;
//     for(auto x: adj[nn]) {
//         ans = uudf(x,uid);
//         if(!ans) break;
//     }
//     if(df(nn)) ans = true; 
//     if(ans){
//         nuid[nn] = uid;
//         for(auto x: adj[nn]) {
//             change(x,uid);
//         }
//     }
//     return ans;
// }

public class Tree{
    public :
        bool l;
        bool la;
        int luid;
        Tree* p;
        vector<Tree*> c; 
        Tree(){
            l =false;
            la=true;
            luid = -1;
            p = NULL;
        }
        Tree(Tree* parent){
            l = false;
            la=true;
            luid = -1;
            this->p = parent;
        }

        bool ll(Tree* n) return n->l;

        void locking(Tree* n, int uuid){
            if(n->la == false || (n->la == true && n->luid != uuid) ) return;
            Tree* T = n;
            luid = uuid;
            bool f = false;
            while(T != NULL){
                if(T->l == true){
                    f = true;
                    break;
                }
                T=T->p;
            }
            if(flag) return;
            else{
                n->l = true;
                T = n;
                while(T!=NULL){
                    T->la = false;
                    T->luid = uuid;
                    T=T->p;
                }
            }
        }
        
        void unlocking(Tree* n){
            if(n -> l == false) return;
            Tree* T = n;
            n->luid = -1;
            n->l=false;
            while(T!=NULL){
                T->la = true;
                T->luid = -1;
                T=T->p;
            }
        }
}




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
    string d;
    cin >> d;
    Tree* t = new Tree();
    sToI.inser({s,1});
    nToT.insert({1,t});

    FOR(i,n) {
        string s;
        cin >> s;
        sToI.insert({s,i+2});
        Tree* x = new Tree(nToT[(int)(i+2)/m]);
        nToT[(int)(i+2)/m].c.pb(x);
        nToT.insert({i+2,x});
    }

    // dfs(1);
    FOR(i,q) {
        int qn,uuid;
        string name;
        bool ans;
        cin >> qn >> name >> uuid;
        if(qn == 1){
            ans = lock(nToi[name],uuid);
            // cout << name<<" "<< nToi[name] << " " << uuid << "\n";
        }
        else if(qn == 2){
            ans = unlock(nToi[name],uuid);
            // cout << name<<" "<< nToi[name] << " " << uuid << "\n";
        }
        else {
            ans = update(nToi[name],uuid);
            // cout << ans << "\n";
        }
        // FOR(j,nuid.size()) cout << j << " " << nuid[j] <<" ";
        // cout <<"\n";
        if(ans) cout << "true\n";
        else cout << "false\n";
    }
    return 0;
}