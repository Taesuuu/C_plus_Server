//
//  thread2.cpp
//  C_Server
//
//  Created by 정태수 on 2022/03/17.
//

#include <thread>
#include <iostream>
#include <chrono>
#include <string>

using namespace std;

void Propose(string name, string hisname) {
    cout << name << " 반가워 " << hisname << endl;
    cout << name << " 안녕 " << hisname << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
}

string taesu = "";
mutex taesu_maum;

void getlove(string name) {
    
    taesu_maum.lock();
    taesu = name;
    Propose("수", taesu);
    this_thread::sleep_for(chrono::milliseconds(5000));
    taesu_maum.unlock();
}
int main() {
    
    
    thread na_seok_hoon(getlove, "11");
    thread oh_jeong_seok(getlove, "22");
    na_seok_hoon.join();
    oh_jeong_seok.join();
    
    //this_thread::sleep_for(chrono::milliseconds(5000));
    //Propose("수", taesu);
    
}
