#include <iostream>
#include <string>
#include <list>

using namespace std;

class ThiSinh{
    int SBD;
    string name;
    string address;
    string priority;
    public:
    int getSBD(){
        return this->SBD;
    }
    void setSBD(int SBD){
        this->SBD = SBD;
    }
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    string getAddress(){
        return this->address;
    }
    void setAddress(string address){
        this->address = address;
    }
    string getPriority(){
        return this->priority;
    }
    void setPriority(string priority){
        this->priority = priority;
    }
    ThiSinh(int SBD, string name, string address, string priority){
        this->setSBD(SBD);
        this->setName(name);
        this->setAddress(address);
        this->setPriority(priority);
    }
    virtual void display(){
        cout<<"==========This is application for management student================"<<endl;
        cout<<"Number ID:"<<this->getSBD()<<endl;
        cout<<"Name:"<<this->getName()<<endl;
        cout<<"Address:"<<this->getAddress()<<endl;
        cout<<"Priority:"<<this->getPriority()<<endl;
    }
};
class KhoiA : public ThiSinh{
    string Mon_Toan = "Toan";
    string Mon_Ly= "Ly";
    string Mon_Hoa = "Hoa";
    public:
    KhoiA(int SBD, string name, string address, string priority):ThiSinh(SBD, name, address, priority){
    }
    void display() override{
        cout<<"This is the information of student candidateA:"<<endl;
        ThiSinh ::display();
        cout << "Subjects: " << Mon_Toan << ", " << Mon_Ly << ", " << Mon_Hoa << endl;
    }
};
class KhoiB : public ThiSinh{
    string Mon_Toan = "Toan";
    string Mon_Sinh= "Sinh";
    string Mon_Hoa = "Hoa";
    public:
    KhoiB(int SBD, string name, string address, string priority):ThiSinh(SBD, name, address, priority){
    }
    void display() override{
        cout<<"This is the information of student candidateB:"<<endl;
        ThiSinh ::display();
        cout << "Subjects: " << Mon_Toan << ", " << Mon_Sinh << ", " << Mon_Hoa << endl;
    }
};
class KhoiC : public ThiSinh{
    string Mon_Van = "Van";
    string Mon_Su= "Su";
    string Mon_Dia = "Dia";
    public:
    KhoiC(int SBD, string name, string address, string priority):ThiSinh(SBD, name, address, priority){
    }
    void display() override{
        cout<<"This is the information of student candidateC:"<<endl;
        ThiSinh ::display();
        cout << "Subjects: " << Mon_Van << ", " << Mon_Su << ", " << Mon_Dia << endl;
    }
};
class TuyenSinh{
    list<ThiSinh*> students;
    public:
    void addStudent(ThiSinh* st){ // void addStudent(Tên lớp cần truy vấn* st)
        this->students.push_back(st);
    }
    list<ThiSinh*> searchStudentByID(int SBD){
        list<ThiSinh*> result;
        for(auto id: this->students){ //dua vao vong lap tim kiem so bao danh trung khop
            if(id->getSBD() == SBD){
                result.push_back(id);
            }
        }
        return result;
    }
    void showListStudent(){
        for(auto st: this->students){
            st->display();
        }
    }
};
int main(){
    KhoiA st1(123, "Alice", "Vietnam", "1");
    KhoiB st2(234, "Bob", "Vietnam", "2");
    KhoiC st3(245, "Lili", "Vietnam", "3");

    TuyenSinh Management;
    Management.addStudent(&st1);
    Management.addStudent(&st2);
    Management.addStudent(&st3);

    Management.showListStudent();

    return 0;
}   