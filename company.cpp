#include <iostream>
#include <string>
#include <list>

using namespace std;

class Officer{
   string name;
   int age;
   string gender;
   string address;
   public:
   //getter and setter
   string getName(){
    return this->name;
   }
   void setName(string name){
    this->name = name;
   }
   int getAge(){
    return this->age;
   }
   void setAge(int age){
    this->age = age;
   }
   string getGender(){
    return this->gender;
   }
   void setGender(string gender){
    this->gender  = gender;
   }
   string getAddress(){
    return  this->address;
   }
   void setAddress(string address){
    this->address = address;
   }
   //contructor
   Officer(string name, int age, string gender, string address){
    this->setName(name);
    this->setAge(age);
    this->setGender(gender);
    this->setAddress(address);
   }
   virtual void display(){
    cout<<"Name of Officer:"<<this->getName()<<endl;
    cout<<"Age:"<<this->getAge()<<endl;
    cout<<"Gender(Female or male):"<<this->getGender()<<endl;
    cout<<"Address:"<<this->getAddress()<<endl;
   }
};
class Staff: public Officer{
    string task;
    public:
    string getTask(){
        return this->task;
    }
    void setTask(string task){
        this->task = task;
    }
    Staff(string name, int age, string gender, string address, string task): Officer(name,age, gender, address){
        this->setTask(task);
    }
    void display() override{
        Officer :: display();
        cout<<"Task of Staff:"<<this->getTask()<<endl;
    }
};
class Engineer: public Officer{
    string branch;
    public:
    string getBranch(){
        return this->branch;
    }
    void setBranch(string branch){
        this->branch = branch;
    }
    Engineer(string name, int age, string gender, string address, string branch): Officer(name, age, gender, address){
        this->setBranch(branch);
    }
    void display() override{
        Officer :: display(); //Bo sung them thuoc tinh co san trong lop Officer
        cout<<"The branch of engineer:"<<this->getBranch()<<endl;
    }
};
class Worker: public Officer{
    int level;
    public: 
    int getLevel(){
        return this->level;
    }
    void setLevel(int level){
        this->level = level;
    }
    Worker(string name, int age, string gender, string address, int level): Officer(name, age, gender, address){
        this->setLevel(level);
    }
    void display() override{
        Officer :: display();
        cout<<"The level of Worker:"<<this->getLevel()<<endl;
    }
};
class ManageOfficer{
    list <Officer*> officers;
    public:
    void addOfficer(Officer* of){
        this->officers.push_back(of);
    }
    list<Officer*> searchOfficerByName(string name){ //Tim kiem theo ten cua can bo
        list<Officer*> result;
        for(auto of: this->officers){ //tim kiem cac ten trung khop sau do goi no ra
            if(of->getName()==name){
                result.push_back(of);
            }
        }
        return result;
    }
    void showListInfoOfficer(){
        for(auto of: this->officers){
            cout<<"This is the infomation of Officers:"<<endl;
            of->display();// goi ham display de hien thi thong tin tung can bo
        }
    }
};


int main(){
    cout<<"The application for management Officer" << endl;
    Officer p1("Alice", 20, "Female", "New York");
    Officer p2("Bob", 25, "Male", "Canada");
    Officer p3("Nam", 30, "Male","VietNam");

    Staff s("John", 35, "Male", "Australia", "Desiner");
    Worker k("Min", 40, "Female", "VietNam", 3);
    ManageOfficer manager;

    // Thêm các sĩ quan vào danh sách quản lý
    manager.addOfficer(&p1);
    manager.addOfficer(&p2);
    manager.addOfficer(&p3);
    manager.addOfficer(&s);
    manager.addOfficer(&k);

    manager.showListInfoOfficer();
    return 0;

}
