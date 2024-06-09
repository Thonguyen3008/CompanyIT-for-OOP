#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Customer {
    string name;
    int age;
    int CMND;
    int numberRent;
public:
    Customer(string name, int age, int CMND, int numberRent)
        : name(name), age(age), CMND(CMND), numberRent(numberRent) {}

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    int getAge() {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getCMND() {
        return CMND;
    }

    void setCMND(int CMND) {
        this->CMND = CMND;
    }

    int getNumberRent() {
        return numberRent;
    }

    void setNumberRent(int numberRent) {
        this->numberRent = numberRent;
    }

    virtual void display() {
        cout << "This is the information of customer:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CMND: " << CMND << endl;
        cout << "Number of Rent: " << numberRent << endl;
    }
};

class Room : public Customer {
    string category;
    int price;
public:
    Room(string name, int age, int CMND, int numberRent, string category, int price)
        : Customer(name, age, CMND, numberRent), category(category), price(price) {}

    string getCategory() {
        return category;
    }

    void setCategory(string category) {
        this->category = category;
    }

    int getPrice() {
        return price;
    }

    void setPrice(int price) {
        this->price = price;
    }

    void display() override {
        Customer::display();
        cout << "The category of room: " << category << endl;
        cout << "The price: " << price << endl;
    }
};

class RoomA : public Room {
    int Room_A = 500;
public:
    RoomA(string name, int age, int CMND, int numberRent, string category, int price)
        : Room(name, age, CMND, numberRent, category, price) {}

    void display() override {
        Room::display();
        cout << "PriceA: " << Room_A << endl;
    }
};

class RoomB : public Room {
    int Room_B = 300;
public:
    RoomB(string name, int age, int CMND, int numberRent, string category, int price)
        : Room(name, age, CMND, numberRent, category, price) {}

    void display() override {
        Room::display();
        cout << "PriceB: $" << Room_B << endl;
    }
};

class RoomC : public Room {
    int Room_C = 100;
public:
    RoomC(string name, int age, int CMND, int numberRent, string category, int price)
        : Room(name, age, CMND, numberRent, category, price) {}

    void display() override {
        Room::display();
        cout << "PriceC: " << Room_C << endl;
    }
};

class Hotel {
    vector<Customer*> customers;
public:
    void addCustomer(Customer* KH) {
        customers.push_back(KH);
    }

    bool deletePerson(int CMND) {
        auto it = find_if(customers.begin(), customers.end(), [=](Customer* c) {
            return c->getCMND() == CMND;
        });

        if (it == customers.end()) {
            return false;
        } else {
            customers.erase(it);
            return true;
        }
    }

    int calculator(int CMND) {
        auto it = find_if(customers.begin(), customers.end(), [=](Customer* c) {
            return c->getCMND() == CMND;
        });

        if (it == customers.end()) {
            return 0;
        }
        
        Room* room = dynamic_cast<Room*>(*it); // Use dynamic_cast to convert from Customer* to Room*
        if (room) {
            return room->getPrice() * room->getNumberRent();
        } else {
            return 0;
        }
    }

    void showDisplay() {
        for (Customer* customer : customers) {
            customer->display();
            cout << endl;
        }
    }
};

int main() {
    Hotel hotel;

    hotel.addCustomer(new RoomA("Alice", 30, 123456, 2, "Deluxe", 500));
    hotel.addCustomer(new RoomB("Bob", 25, 654321, 3, "Standard", 300));
    hotel.addCustomer(new RoomC("Charlie", 35, 112233, 5, "Economy", 100));

    cout << "Before deletion:" << endl;
    hotel.showDisplay();

    bool deleted = hotel.deletePerson(654321);
    if (deleted) {
        cout << "Customer with CMND 654321 deleted successfully." << endl;
    } else {
        cout << "Customer with CMND 654321 not found." << endl;
    }

    cout << "After deletion:" << endl;
    hotel.showDisplay();

    int cost = hotel.calculator(123456);
    cout << "Total cost for customer with CMND 123456: " << cost << endl;

    int costs = hotel.calculator(112233);
    cout  <<"Total cost for customer with CMND  112233:"  <<costs <<endl;

    return 0;
}
