#include <iostream>
#include <string>
#include<cmath>
using namespace std;

// Structure 
struct Service {
    string serviceName;
    double price;
    int id;
    double kwh;
};

// StationSystem 
class StationSystem {
private:
    string myUser;
    string myPass;
    Service chargeList[20];
    Service washList[20];
    Service mechanicList[20];

    int chargeNum;
    int washNum;
    int mechanicNum;

public:
    StationSystem() {
        myUser = "OMAR";
        myPass = "1234";
        chargeNum = 0;
        washNum = 0;
        mechanicNum = 0;
    }

    // Login part
    bool login() {
        string inputUser, inputPass;
        int tries = 0;
        while (tries < 3) {
            try {
                cout << "\n--- Welcome! Please Login ---\n";
                cout << "Username: ";
                cin >> inputUser;
                cout << "Password: ";
                cin >> inputPass;

                if (inputUser == myUser && inputPass == myPass) {
                    return true;
                }
                else {
                    tries++;
                    if (tries < 3) {
                        throw "Wrong info. Try again.";
                    }
                }
            }
            catch (const char* msg) {
                cout << msg << " Remaining tries: " << (3 - tries) << endl;
            }
        }
        cout << "\nSorry, you cannot use the program because you entered wrong data 3 times.\n";
        return false;
    }

    // Main Menu 
    void mainMenu() {
        int choice;
        do {
            cout << "\n*-*-*-*-* Main Menu *-*-*-*-*\n";
            cout << " 1. Charging\n 2. Washing\n 3. Mechanic\n 4. History\n 5. Logout\n 0. Exit\n";
            cout << "Choose a service: ";
            cin >> choice;

            switch (choice) {
            case 1: charg(); break;
            case 2: wash(); break;
            case 3: mechanicMenu(); break;
            case 4: History(); break;
            case 5: return;
            case 0: exit(0); break;
            default: cout << "Invalid number. Try again.\n";
            }
        } while (choice != 0);
    }

    // Charging Service
    void charg() {
        double kwh, cost, discount = 0;
        int ok;
        do {
            cout << "\n--- Charging Service ---\n";
            cout << "How many kWh do you want? ";
            cin >> kwh;
            cost = kwh * 0.08;

            if (kwh >= 60) discount = cost * 0.02;
            else if (kwh >= 50) discount = cost * 0.01;
            double finalPrice = cost - discount;
            cout << "Original Cost: " << cost << "\nYour Discount: " << discount << "\nFinal Price: " << finalPrice << endl;
            cout << " 1. Agree and Save\n 2. Try Again\n 0. Back to Main Menu\n Your choice: ";
            cin >> ok;

            if (ok == 1 && chargeNum < 20) {
                chargeList[chargeNum].serviceName = "Charging";
                chargeList[chargeNum].price = finalPrice;
                chargeList[chargeNum].id = chargeNum + 1;
                chargeList[chargeNum].kwh = kwh;
                cout << "\n--- Details Saved ---\n";
                chargeNum++;
                ok = 0;
            }
        } while (ok == 2);
    }

    // Washing Service
    void wash() {
        int type, ok;
        double basePrice = 0;
        string carType;
        do {
            cout << "\n--- Washing Service ---\n";
            cout << " 1. Small Car (3)\n 2. Salon Car (4)\n 3. Small Bus (5)\n 4. Big Bus (6)\n 5. Machines (7)\n 0. Back\nChoose: ";
            cin >> type;

            if (type == 0) return;

            switch (type) {
            case 1: basePrice = 3; carType = "Small Car"; break;
            case 2: basePrice = 4; carType = "Salon Car"; break;
            case 3: basePrice = 5; carType = "Small Bus"; break;
            case 4: basePrice = 6; carType = "Big Bus"; break;
            case 5: basePrice = 7; carType = "Machine"; break;
            default: cout << "Invalid choice!\n"; continue;
            }

            double finalPrice = basePrice * 1.16;
            cout << "Final Price with Tax: " << finalPrice << "\n 1. Agree\n 2. Try Again\n 0. Back\n Choose: ";
            cin >> ok;

            if (ok == 1 && washNum < 20) {
                washList[washNum].serviceName = carType;
                washList[washNum].price = finalPrice;
                washList[washNum].id = washNum + 1;
                washNum++;
                ok = 0;
            }
        } while (ok == 2);
    }

    void mechanicMenu() {
        int mChoice;
        do {
            cout << "\n--- Mechanic Menu ---\n 1. Oil Change\n 2. Electricity\n 0. Back\n ";
            cin >> mChoice;
            if (mChoice == 1) oil();
            else if (mChoice == 2) electricityMenu();
            else if (mChoice == 0) return;
        } while (mChoice != 0);
    }

    void oil() {
        string oilType;
        int ok;
        do {
            cout << "\n--- Oil Change ---\nWhat type of oil? ";
            cin >> oilType;
            double finalPrice = 20.0 * 1.16;
            cout << "Total Cost with tax: " << finalPrice << "\n 1. Agree\n 2. Try Again\n 0. Back\n ";
            cin >> ok;

            if (ok == 1 && mechanicNum < 20) {
                mechanicList[mechanicNum].serviceName = "Oil: " + oilType;
                mechanicList[mechanicNum].price = finalPrice;
                mechanicList[mechanicNum].id = mechanicNum + 1;
                mechanicNum++;
                ok = 0;
            }
        } while (ok == 2);
    }

    void electricityMenu() {
        int eChoice, ok;
        double price = 0; string name;
        do {
            cout << "\n--- Electricity ---\n 1. Front Light (5)\n 2. Back Light (4)\n 3. Spark Plugs (15)\n 0. Back\n";
            cin >> eChoice;
            if (eChoice == 0) return;
            if (eChoice == 1) { price = 5; name = "Front Light"; }
            else if (eChoice == 2) { price = 4; name = "Back Light"; }
            else if (eChoice == 3) { price = 15; name = "Spark Plugs"; }
            else continue;

            double finalPrice = price * 1.16;
            cout << "Cost: " << finalPrice << "\n 1. Agree\n 2. Try Again\n 0. Back\n ";
            cin >> ok;

            if (ok == 1 && mechanicNum < 20) {
                mechanicList[mechanicNum].serviceName = name;
                mechanicList[mechanicNum].price = finalPrice;
                mechanicList[mechanicNum].id = mechanicNum + 1;
                mechanicNum++;
                ok = 0;
            }
        } while (ok == 2);
    }

    void History() {
        int Choice;
        cout << "\n--- History ---\n1. Charging\n2. Washing\n3. Mechanic\n0. Back\nChoose: ";
        cin >> Choice;
        if (Choice == 1) {
            for (int i = 0; i < chargeNum; i++)
                cout << "ID: " << chargeList[i].id << " | Cost: " << chargeList[i].price << " | kWh: " << chargeList[i].kwh << endl;
        }
        else if (Choice == 2) {
            for (int i = 0; i < washNum; i++)
                cout << "ID: " << washList[i].id << " | Cost: " << washList[i].price << " | Type: " << washList[i].serviceName << endl;
        }
        else if (Choice == 3) {
            for (int i = 0; i < mechanicNum; i++)
                cout << "ID: " << mechanicList[i].id << " | Cost: " << mechanicList[i].price << " | Service: " << mechanicList[i].serviceName << endl;
        }
    }
};

int main() {
    StationSystem myApp;
    while (true) {
        if (myApp.login()) {
            myApp.mainMenu();
        }
        else {
            break;
        }
    }
    return 0;
}