#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool isleap(int year){
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int monthDay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string dayName[] = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"};

string findDayName(int d, int m, int y){
    int tday = 0;
    for(int i = 1; i < y; i++){
        tday += isleap(i) ? 366 : 365;
    }
    for(int i = 1; i < m; i++){
        tday += monthDay[i];
        if(i == 2 && isleap(y)) tday++;
    }
    tday += d;
    tday = (tday - 1 + 7) % 7;
    string res =  dayName[tday];
    return res;
}
string findDayName(int d, int m, int y){
    int prev = y - 1;
    int tday = d + (prev * 365) + prev/4 - prev/100 + prev/400;
    for(int i = 1; i < m; i++){
        tday += monthDay[i];
        if(i == 2 && isleap(y)) tday++;
    }
    tday = (tday - 1 + 7) % 7;
    string res =  dayName[tday];
    return res;
}

int main(){
    int d, m, y;
    cin >> d >> m >> y;
    string res = findDayName(d, m, y);
    cout << res << '\n';
}
