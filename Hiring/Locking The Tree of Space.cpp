
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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
int inf=1e9+7, MOD=1e9+7;

int w = 1;

struct Tree{
    public :
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
            if(n->isLockable == false || (n->isLocked)) return false;
            Tree* T = n;
            queue<Tree*> q;
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    if(x->isLocked) return false;
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
                }
            }
            return true;
        }
        
        bool unlocking(Tree* n,int uuid){
            if(n->isLockable == false || n -> isLocked == false || (n->isLocked && uuid != n->id)) return false;
            Tree* T = n;
            n->isLocked= false;
            n->id = -1;
            queue<Tree*> q;
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    x->isLockable = true;
                    q.push(x);
                }
            }
            return true;
        }

        bool update(Tree* n,int uuid){
            if(n->isLockable == false || n->isLocked == true) return false;
            Tree* T = n;
            queue<Tree*> q;
            q.push(T);
            bool f = false;
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    if(x->isLocked == true && x->id != uuid) { return false; }
                    if(x->isLocked) f = true;
                    q.push(x);
                }
            }
            if(!f) return false;
            // n->isLocked =  true;
            // n->id = uuid;
            // queue<Tree*> q;
            q.push(T);
            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();
                for(auto x: temp->c){
                    if(x->isLocked){
                        // x->isLocked = false;
                        if(!unlocking(x,uuid)) return false;
                    }
                    q.push(x);
                }
            }
            // locking(n,uuid);
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