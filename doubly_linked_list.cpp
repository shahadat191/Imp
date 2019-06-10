#include <iostream>
using namespace std;

struct node{
    int val;
    node *left, *right;
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
        temp->left = NULL;
        temp->right = NULL;
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        tail->right = temp;
        temp->left = tail;
        tail = temp;
    }
    void pop_back(){
        if(tail == NULL){
            head = NULL;
            cout << "nai, kichu" << endl;
            return;
        }
        node* cur = tail;
        tail = tail->left;
        tail->right = NULL;
        delete(cur);
    }
    
    void print(){
        //cout << tail->val << endl;
        node* cur = head;
        while(cur != NULL){
            cout << cur->val << " ";
            cur = cur->right;
        }
        cout << endl;
    }
};


void solve(){
}

int32_t main(){
    Vector ar;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        ar.push_back(temp);
    }
    ar.print();
    ar.pop_back();
    ar.pop_back();
    ar.pop_back();
    ar.print();
}

