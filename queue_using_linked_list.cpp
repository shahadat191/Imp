#include <iostream>
using namespace std;

struct node{
    int val;
    node* next;
};

class queue{
private:
    node *head, *tail;
public:
    queue(){
        head = NULL;
        tail = NULL;
    }
    int front(){
        return head->val;
    }
    void pop(){
        if(head == NULL){
            tail = NULL;
            return;
        }
        node* cur = head;
        head = head->next;
        delete(cur);
    }
    
    bool empty(){
        if(head == NULL) return true;
        else return false;
    }
    void push(int value){
        node* temp = new node;
        temp->val = value;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
};

class Vector{
public:
    node *head, *tail;
    Vector(){
        head = NULL;
        tail = NULL;
    }
    void push_back(int value){
        node *temp = new node();
        temp->val = value;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
    void del(){
        node *cur = head;
        while(cur != NULL){
            node* temp = cur;
            cur = cur->next;
            delete(temp);
        }
        head = NULL;
    }
};


Vector edge[1010];
int level[1010], visit[1010];
int n, m;

void bfs(int start){
    queue S;
    S.push(start);
    visit[start] = 1;
    
    while(!S.empty()){
        int temp = S.front();
        S.pop();
        node* cur = edge[temp].head;
        while(cur != NULL){
            int t2 = cur->val;
            cur = cur->next;
            if(visit[t2] == 0){
                visit[t2] = 1;
                level[t2] = level[temp] + 1;
                S.push(t2);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        level[i] = -1;
        visit[i] = 0;
        edge[i].del();
    }
    
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int start;
    cin >> start;
    level[start] = 0;
    bfs(start);
    
    for(int i = 1 ; i <= n; i++){
        if(i == start) continue;
        if(level[i] > 0) cout << 6*level[i];
        else cout << -1;
        if(i != n) cout << ' ';
    }
    cout << '\n';
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

