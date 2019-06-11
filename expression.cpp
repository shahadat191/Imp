#include <iostream>
using namespace std;
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
 
int ar[20];
int op[10];
int n, m, os, make;
int res = 100;
char str[20];
 
int check(int pos){
    int nums[10]; char marks[10];
   
    int n = 0, m = 0;
    int now = 0;
    for(int i = 0; i < pos; i++){
        if(str[i] >= '0' && str[i] <= '9')
            now = now * 10 + (str[i] - '0');
        else{
            nums[n++] = now;
            marks[m++] = str[i];
            now = 0;
        }
    }
    nums[n++] = now;
    int res = nums[0];
    for(int i = 1; i < n; i++){
        if(marks[i-1] == '+'){
            res += nums[i];
        }
        else if(marks[i-1] == '-'){
            res -= nums[i];
        }
        else if(marks[i-1] == '*'){
            res *= nums[i];
        }
        else{
            if(nums[i] == 0 || res % nums[i] != 0) return -1;
            res /= nums[i];
        }
    }
    return res;
}
 
void fun(int pos){
    if(pos > os) return;
    if(pos <= os){
        int temp = check(pos);
        for(int i = 0; i < pos; i++)
            cout << str[i];
        cout << "    ";
        cout << temp << '\n';
        if(temp == make) {
            res = min(res, pos);
            return;
        }
    }
   
    for(int i = 0; i < n; i++){
        str[pos] = ar[i] + '0';
        fun(pos + 1);
    }
 
    if(pos != 0 && pos != os - 1){
        for(int i = 0; i < m; i++){
            char mark;
            if(op[i] == 1) mark = '+';
            else if(op[i] == 2) mark = '-';
            else if(op[i] == 3) mark = '*';
            else if(op[i] == 4) mark = '/';
            if(str[pos - 1] >= '0' && str[pos - 1] <= '9'){
                str[pos] = mark;
                fun(pos + 1);
            }
        }
    }
}
bool ache(int val){
    while(val != 0){
        int idx = val % 10;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(idx == ar[i]){
                flag = true;
                continue;
            }
        }
        if(!flag) return false;
        val /= 10;
    }
    return true;
}
 
int32_t main(){
   
    input;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> os;
       
        for(int i = 0; i < n; i++){
            cin >> ar[i];
        }
        for(int i = 0; i < m; i++){
            cin >> op[i];
        }
        cin >> make;
       
        bool f = ache(make);
        if(!f){
            os--;
            fun(0);
            cout << res + 1 << '\n';
        }
        else{
            int cnt = 0;
            while(make != 0){
                make /= 10;
                cnt++;
            }
            cout << cnt << '\n';
        }
    }
}
