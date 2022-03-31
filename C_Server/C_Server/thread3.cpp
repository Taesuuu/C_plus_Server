////
////  thread3.cpp
////  C_Server
////
////  Created by 정태수 on 2022/03/31.
////
//
//#include <thread>
//#include <iostream>
//#include <chrono>
//#include <string>
//
//using namespace std;
//
//class Actor {
//public:
//    string name;
//    mutex heart;
//    thread th;
//    Actor() {}
//    virtual void Run(){}
//};
//
//class Hoon : public Actor{
//    public :
//    void (Hoon::* RunPoint)();
//    Hoon() {
//
//    }
//
//    void Run() {
//        cout << "테스트 \n\n";
////        FallinLove();
//    }
//
//    void Floating(Actor *actor){
//        this_thread::sleep_for(chrono::milliseconds(1000));
//        cout << "훈 :" << actor->name << " 111\n\n";
//        this_thread::sleep_for(chrono::milliseconds(1000));
//    }
//
//    void FallinLove(Actor *actor) {
//        this_thread::sleep_for(chrono::milliseconds(1000));
//        heart.lock();
//        cout << "훈 : " << actor->name << "222\n\n";
//    }
//
//    void fucks(Actor *actor) {
//        this_thread::sleep_for(chrono::milliseconds(1000));
//        cout << "훈 : " << actor->name << "33333\n\n";
//        this_thread::sleep_for(chrono::milliseconds(1000));
//        heart.unlock();
//    }
//};
//
////void Propose(string name, string hisname) {
////    cout << name << " 반가워 " << hisname << endl;
////    cout << name << " 안녕 " << hisname << endl;
////    this_thread::sleep_for(chrono::milliseconds(1000));
////}
//
//string taesu = "";
//mutex taesu_maum;
//
////void getlove(string name) {
////
////    taesu_maum.lock();
////    taesu = name;
////    Propose("수", taesu);
////    this_thread::sleep_for(chrono::milliseconds(5000));
////    taesu_maum.unlock();
////}
//
//
//int main() {
//
////    thread na_seok_hoon(getlove, "112");
////    thread oh_jeong_seok(getlove, "223");
////    thread jeong_taesu(getlove, "565");
////    na_seok_hoon.join();
////    oh_jeong_seok.join();
////    jeong_taesu.join();
////
////    //this_thread::sleep_for(chrono::milliseconds(5000));
////    //Propose("수", taesu);
////    return 0;
//
//    Actor *h = new Hoon();
//}

//목요드라마 석 & 훈
#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <chrono>

using namespace std;

class Actor
{
public:
    string name;
    thread th;
    mutex heart;
    
    Actor() {}
    virtual void Start(Actor* actor) {}
    virtual void Run(Actor* actor) {}
};


class Hoon : public Actor
{
public:
    void(Hoon::*RunPointer)(Actor* actor);

    Hoon()
    {
        name = "훈이";
    }

    void Start(Actor* actor)
    {
        RunPointer = &Hoon::Run;
        th = thread(RunPointer, this, actor);
        //th.join();
    }

    void Run(Actor* actor) {
        FallinLove(actor);
        Flirting(actor);
        Fuckyou(actor);
    }

    void FallinLove(Actor *actor)
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "훈 : (나 갑자기..." << actor->name << "을(를) 보니 너무 설렌다....)\n\n";
        this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    void Flirting(Actor * actor)
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "훈 : " << actor->name << "... 내방에서... 라면먹고갈래??\n\n";
        heart.lock();
    }

    void Fuckyou(Actor* actor)
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "훈 : (아..." << actor->name << "...정떨어져...\n\n";
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        heart.unlock();
    }
};

class Seok : public Actor
{
public:
    void(Seok::*RunPointer)(Actor* actor);
    Seok() {
        name = "석이";
    }
    
    void Start(Actor* actor)
    {
        RunPointer = &Seok::Run;
        th = thread(RunPointer, this, actor);
//        th.join();
    }

    void Run(Actor* actor) {
        FallinLove(actor);
        Flirting(actor);
        Fuckyou(actor);
    }

    void FallinLove(Actor *actor)
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "석 : (나 갑자기..." << actor->name << "을(를) 보니 너무 설렌다....)\n\n";
        this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    void Flirting(Actor * actor)
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "석 : " << actor->name << "... 내방에서... 라면먹고갈래??\n\n";
        heart.lock();
    }

    void Fuckyou(Actor* actor)
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "석 : (아..." << actor->name << "...정떨어져...\n\n";
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        heart.unlock();
    }
};

class Su : public Actor
{
public:
    void(Su::*RunPointer)(Actor* actor);
    Su()
    {
        name = "수";
    }
    void Start(Actor* actor)
    {
        RunPointer = &Su::Run;
        th = thread(RunPointer, this, actor);
        //th.join();
    }

    void Run(Actor* actor) {
        FallinLove(actor);
        Flirting(actor);
        Fuckyou(actor);
    }

    void FallinLove(Actor *actor)
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "수 : (나 갑자기..." << actor->name << "을(를) 보니 너무 설렌다....)\n\n";
        this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    void Flirting(Actor * actor)
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "수 : " << actor->name << "... 내방에서... 라면먹고갈래??\n\n";
        heart.lock();
    }

    void Fuckyou(Actor* actor)
    {
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "수 : (아..." << actor->name << "...정떨어져...\n\n";
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        heart.unlock();
    }
};

int main() //Thread0 PD : 이은석 (main)
{
    Actor* h = new Hoon();
    Actor* s = new Seok();
    Actor* t = new Su();
    
//    h->Start(???);
    
        h->Start(s);
        s->Start(t);
        t->Start(h);
    
   
     
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    delete(h);
    delete(s);
    delete(t);
    

}

