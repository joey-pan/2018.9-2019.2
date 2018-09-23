#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*
 初始化输入格式：
    车辆类型
    单价（分钟）
    车位总数n
    之后n行为：楼层 字母编号 数字编号
 重复以上内容直至四类车辆的车位情况全部录入
 录入完成后会显示system open。
 =======================
 样例输入：
 car
 2
 5
 1 A 2
 2 B 1
 3 C 1
 3 C 2
 3 C 4
 motorbike
 3
 1
 1 A 3
 bicycle
 4
 1
 1 A 4
 van
 1
 3
 1 A 1
 2 B 2
 3 C 3
 样例输出：
 system open
 =======================
 出现system open后，开始车辆出入停车场的输入。输出ticket后重复此操作。
 进入停车场的输入格式：
 enter
 车辆的id
 车辆类型
 时间
 输入后会输出arrival ticket
 =======================
 样例输入：
 enter
 1234
 van
 12:00
 样例输出：（基于之前的数据）
 ----------------------
 Arrival Ticket
 arrival time: 12:00
 Vehicle type: van
 empty slot:floor 1 A1
 ----------------------
 =======================
 离开停车场的输入格式：
 exit
 车辆id
 时间
 输入后会输出departure ticket
 =======================
 样例输入：
 exit
 1234
 15:00
 样例输出：（基于之前的数据）
 ----------------------
 Departure ticket
 Time spent: 180 minute(s)
 Vehicle type: van
 Price: 180
 Thank you!
 ----------------------
 =======================
 中止停车场程序的输入命令：
 shut
 输出：
 system shut down
 之后程序退出。
 */
const int maxn = 10000;
const int maxv = 40000;
struct location{
    int floor;
    char x;
    int y;
    int condition;//1 = full, 0 = empty
};
struct lot{
    //init univalence of all types of parking lot
    //0:van 1:car 2:motorbike 3:bicycle
    float uni;//univalence
    int limit;//limitation of this type
    location loc[maxn];
}slot[4];
void init(){//initialize the lot
    for (int i = 0 ; i < 4; i++){
        char t[20];
        gets(t);
        int type = 0;
        if (strcmp(t,"van") == 0) {
            type = 0;
        }
        else if(strcmp(t,"car") == 0){
            type = 1;
        }
        else if(strcmp(t,"motorbike") == 0){
            type = 2;
        }
        else if(strcmp(t,"bicycle") == 0){
            type = 3;
        }
        cin >> slot[type].uni >> slot[type].limit;
        for (int j = 0; j < slot[type].limit; j++) {
            cin >> slot[type].loc[j].floor >> slot[type].loc[j].x >> slot[type].loc[j].y;
        }
        getchar();
    }
    return;
}
struct vehicle{
    char id[20];
    int in_hour;
    int in_minute;
    int type;
    int loca;
    int ou_hour;
    int ou_minute;
    int in_rev_time;
    int ou_rev_time;
    int lstime;
    float unicost;
    float price;
}veh[maxv];
void enter(int flag){
    gets(veh[flag].id);
    char t[20];
    gets(t);
    if (strcmp(t,"van") == 0) {
        veh[flag].type = 0;
    }
    else if(strcmp(t,"car") == 0){
        veh[flag].type = 1;
    }
    else if(strcmp(t,"motorbike") == 0){
        veh[flag].type = 2;
    }
    else if(strcmp(t,"bicycle") == 0){
        veh[flag].type = 3;
    }
    veh[flag].unicost = slot[veh[flag].type].uni;
    cin >> veh[flag].in_hour;
    getchar();
    cin >> veh[flag].in_minute;
    veh[flag].in_rev_time = veh[flag].in_hour * 60 + veh[flag].in_minute;
    getchar();
    cout << "----------------------" << endl;
    cout << "Arrival Ticket" << endl;
    if (veh[flag].in_minute < 10) {
        cout << "arrival time: " << veh[flag].in_hour << ":0" << veh[flag].in_minute << endl;
    }
    else {
        cout << "arrival time: " << veh[flag].in_hour << ":" << veh[flag].in_minute << endl;
    }
    
    if (veh[flag].type == 0) {
        cout << "Vehicle type: van" << endl;
    }
    else if (veh[flag].type == 1) {
        cout << "Vehicle type: car" << endl;
    }
    else if (veh[flag].type == 2) {
        cout << "Vehicle type: motorbike" << endl;
    }
    else if (veh[flag].type == 3) {
        cout << "Vehicle type: bicycle" << endl;
    }
    
    for (int i = 0; i < slot[veh[flag].type].limit; i++) {
        if (slot[veh[flag].type].loc[i].condition == 0) {
            slot[veh[flag].type].loc[i].condition = 1;
            veh[flag].loca = i;
            cout << "empty slot:" << "floor " << slot[veh[flag].type].loc[i].floor << " ";
            cout << slot[veh[flag].type].loc[i].x << slot[veh[flag].type].loc[i].y<<endl;
            cout << "----------------------" << endl;
            break;
        }
    }
    return;
}
void exitl(int flag){
    char ex[20];
    gets(ex);
    for (int i = 0; i < maxv; i++) {
        if (strcmp(ex, veh[i].id) == 0) {
            flag = i;
            break;
        }
    }
    cin >> veh[flag].ou_hour;
    getchar();
    cin >> veh[flag].ou_minute;
    veh[flag].ou_rev_time = veh[flag].ou_hour * 60 + veh[flag].ou_minute;
    getchar();
    veh[flag].lstime = veh[flag].ou_rev_time - veh[flag].in_rev_time;
    veh[flag].price = veh[flag].lstime * veh[flag].unicost;
    slot[veh[flag].type].loc[veh[flag].loca].condition = 0;
    cout << "----------------------" << endl;
    cout << "Departure ticket" << endl;
    cout << "Time spent: " << veh[flag].lstime << " minute(s)" << endl;
    if (veh[flag].type == 0) {
        cout << "Vehicle type: van" << endl;
    }
    else if (veh[flag].type == 1) {
        cout << "Vehicle type: car" << endl;
    }
    else if (veh[flag].type == 2) {
        cout << "Vehicle type: motorbike" << endl;
    }
    else if (veh[flag].type == 3) {
        cout << "Vehicle type: bicycle" << endl;
    }
    cout << "Price: " << veh[flag].price << " yuan" <<endl;
    cout << "Thank you!" << endl;
    cout << "----------------------" << endl;
    return;
}
int main(){
    init();
    cout << "system open" <<endl;
    int in_flag = 0, ou_flag = 0;
    while (1) {
        char p[20];
        gets(p);
        if (strcmp(p,"enter") == 0) {
            enter(in_flag);
            in_flag++;
        }
        else if(strcmp(p,"exit") == 0){
            exitl(ou_flag);
        }
        else if(strcmp(p,"shut") == 0){
            cout << "system shut down" << endl;
            break;
        }
    }
    return 0;
}