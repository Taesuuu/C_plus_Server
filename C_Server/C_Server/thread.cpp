//
//  thread.cpp
//  C_Server
//
//  Created by 정태수 on 2022/03/10.
//

#include <thread>
#include <iostream>
#include <chrono>

using namespace std;
int trigger;
void seokHoon(){
    
    while (trigger==0) {
        cout << "안녕\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    
}

void JeongSeok() {
    while (trigger==0) {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "반가워\n";
    }
}

int main() {
    trigger = 0;
    thread ta(seokHoon);
    thread na(JeongSeok);
    
    while (trigger==0) {
        cin >> trigger;
    }
    
    ta.join();
    na.join();
    return 0;
}
