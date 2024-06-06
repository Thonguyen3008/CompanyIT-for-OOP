#include <iostream>
#include <string>
#include <vector>

using namespace std;

class employee {
    int thePayrollNumber;
    float theMonthlySalary;
    string theName;
public:
    // Getter and setter
    int getThePayrollNumber() {
        return this->thePayrollNumber;
    }
    void setThePayrollNumber(int thePayrollNumber) {
        this->thePayrollNumber = thePayrollNumber;
    }
    float getTheMonthlySalary() {
        return this->theMonthlySalary;
    }
    void setTheMonthlySalary(float theMonthlySalary) {
        this->theMonthlySalary = theMonthlySalary;
    }
    string getTheName() {
        return this->theName;
    }
    void setTheName(string theName) {
        this->theName = theName;
    }
    // Constructor    
    employee(int thePayrollNumber, float theMonthlySalary, string theName) {
        this->setThePayrollNumber(thePayrollNumber);
        this->setTheMonthlySalary(theMonthlySalary);
        this->setTheName(theName);
    }
    virtual void display() {
        cout << "Number for pay: " << this->getThePayrollNumber() << endl;
        cout << "Salary: " << this->getTheMonthlySalary() << endl;
        cout << "The name of employee: " << this->getTheName() << endl;
    }
};

class Programmer : public employee {
    string theLanguage;
public:
    string getTheLanguage() {
        return this->theLanguage;
    }
    void setTheLanguage(string theLanguage) {
        this->theLanguage = theLanguage;
    }
    Programmer(int thePayrollNumber, float theMonthlySalary, string theName, string theLanguage)
        : employee(thePayrollNumber, theMonthlySalary, theName) {
        setTheLanguage(theLanguage);
    }
    void display() override {
        employee::display();
        cout << "The language of programmer: " << this->getTheLanguage() << endl;
    }
};
//add member become 1 team to manage person
class ProjectLeader : public Programmer {
    string nameLeader;
    vector<Programmer*> theTeam;
public:
    string getNameLeader() {
        return this->nameLeader;
    }
    void setNameLeader(string nameLeader) {
        this->nameLeader = nameLeader;
    }
    // Add a programmer to the team
    void addProgrammers(Programmer* p) {
        this->theTeam.push_back(p);
    }
    ProjectLeader(int thePayrollNumber, float theMonthlySalary, string theName, string theLanguage, string nameLeader)
        : Programmer(thePayrollNumber, theMonthlySalary, theName, theLanguage) {
        this->setNameLeader(nameLeader);
    }
    // Display members in team
    void displayTeam() {
        cout << "The team members are:" << endl;
        for (auto p : this->theTeam)
            p->display();
    }
    // Display the name of leader
    void displayLeader() {
        cout << "The name of Leader: " << this->getNameLeader() << endl;
        Programmer::display();
    }
};

// admin the hien cac quyen voi cac lop quan ly nhan vien
class administration : public employee {
    string department;
public:
    string getDepartment() {
        return this->department;
    }
    void setDepartment(string department) {
        this->department = department;
    }
    administration(int thePayrollNumber, float theMonthlySalary, string theName, string department)
        : employee(thePayrollNumber, theMonthlySalary, theName) {
        this->setDepartment(department);
    }
    void display() override {
        cout << "The administration of the project:" << endl;
        cout << "Payroll Number: " << this->getThePayrollNumber() << endl;
        cout << "Monthly Salary: " << this->getTheMonthlySalary() << endl;
        cout << "Name: " << this->getTheName() << endl;
        cout << "Department: " << this->getDepartment() << endl;
    }
};

class SoftwareHouse {
    string nameSoftwareHouse;
    vector<employee*> staff;
public:
    string getNameSoftwareHouse() {
        return this->nameSoftwareHouse;
    }
    void setNameSoftwareHouse(string nameSoftwareHouse) {
        this->nameSoftwareHouse = nameSoftwareHouse;
    }
    SoftwareHouse(string nameSoftwareHouse) {
        this->setNameSoftwareHouse(nameSoftwareHouse);
    }
    void addStaffs(employee* e) {
        this->staff.push_back(e);
    }
    void display() {
        cout << "The name of software house: " << this->getNameSoftwareHouse() << endl;
        for (auto e : this->staff) {
            e->display();
        }
    }
};

int main() {
    SoftwareHouse swh("HCMUS");
    Programmer p1(1, 2000, "Alice", "C# ASP");
    Programmer p2(2, 3000, "Bob", "C++");
    ProjectLeader pl1(3, 4000, "Charlie", "Python", "Leader1");
    
    swh.addStaffs(&p1);
    swh.addStaffs(&p2);
    swh.addStaffs(&pl1);

    swh.display();

    return 0;
}
