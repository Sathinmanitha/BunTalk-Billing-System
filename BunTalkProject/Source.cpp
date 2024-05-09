#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>



using namespace std;

// Function to display home
void displayHome() {

    cout << "===========================================" << endl;
    cout << "\n    Welcome to Bun Talk Billing System" << endl;
    cout << "  Address: 365 Havelolock Town Colombo 05" << endl;
    cout << "          Contact: 0112459245" << endl;
    cout << "         www.buntalksrilanka.lk\n" << endl;
    cout << "===========================================";

    cout << endl << endl;
}


// Help Function
void displayHelp() {

    cout << "\n--------------------------" << endl;
    cout << "           Help " << endl;
    cout << "--------------------------" << endl;

    cout << "\n\nView Bakery Items:\n" << endl;
    cout << "This option allows you to browse through the list of bakery items available in the system." << endl;
    cout << "You can use this to see what items are currently in stock or to check for specific products." << endl;

    cout << "\n\nSelect Bakery Items:\n" << endl;
    cout << "Use this option to choose the bakery items you wish to purchase." << endl;
    cout << "You can add items to your order or cart using this feature." << endl;

    cout << "\n\nExecute a Bill:\n" << endl;
    cout << "This option helps you calculate the total cost of the selected bakery items." << endl;
    cout << "It typically involves summing up the prices of the selected items and applying any applicable taxes or discounts." << endl;

    cout << "\n\nPrint Bill:\n" << endl;
    cout << "Once you've executed a bill, you can use this option to generate a printed copy of the bill." << endl;
    cout << "The printed bill is often provided as a receipt for your purchase." << endl;


}


void userGuild() {

    system("cls");

    cout << "\n------------------------------------------" << endl;
    cout << "Bun Talk Bakery Billing System User Guide " << endl;
    cout << "--------------------------------------------\n\n" << endl;

    cout << "Welcome to the Bun Talk Bakery Billing System!\n" << endl;
    cout << "This system allows you to manage bakery items, staff details, and execute bills efficiently." << endl;
    cout << "This guide will walk you through the main features and functionalities of the system.\n" << endl;

    cout << "\n--------------------------------" << endl;
    cout << "      Table of Contents" << endl;
    cout << "--------------------------------" << endl;

    cout << "\n\n1. Login\n" << endl;

    cout << "2. Admin Function" << endl;
    cout << "\n   * View Bakery Items" << endl;
    cout << "   * Add New Bakery Items" << endl;
    cout << "   * Add Staff" << endl;
    cout << "   * View Staff Details" << endl;
    cout << "   * Logout\n" << endl;

    cout << "3. Cashier Function" << endl;
    cout << "\n   * View Bakery Items" << endl;
    cout << "   * Select Bakery Items" << endl;
    cout << "   * Execute a Bill" << endl;
    cout << "   * Print Bill" << endl;
    cout << "   * Help" << endl;
    cout << "   * Logout\n" << endl;

    cout << "4. Exiting the system" << endl;

}



//Bakery Item
struct Item {
    int bakeryID;
    string bakeryItem;
    double itemPrice;
};


// Function to display bakery items

vector<Item> bakeryItems; // vector

void displaybakeryItems() {

    system("cls"); //clear old console printed data

    cout << "\n--------------------------" << endl;
    cout << "    Bakery Items Menu" << endl;
    cout << "--------------------------\n" << endl;

    bakeryItems.clear();
    ifstream file("menu.txt"); // Use ifstream for reading

    if (!file.is_open()) {
        cout << "Failed to open file" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {

        istringstream iss(line);
        Item item;

        if (iss >> item.bakeryID >> item.bakeryItem >> item.itemPrice) {
            bakeryItems.push_back(item);
        }

    }
    file.close();
}





// Function to add bakery items
void addBakeryItem() {

    cout << "\n--------------------------" << endl;
    cout << "   Add New Bakery Items" << endl;
    cout << "--------------------------" << endl;


    cout << "\n\nEnter Bakery ID: ";
    int id;
    cin >> id;


    cout << "Enter Bakery Item Name: ";
    string name;
    cin.ignore();
    getline(cin, name);

    cout << "Enter Item Price: ";
    double price;
    cin >> price;

    Item newItem = { id, name, price };
    bakeryItems.push_back(newItem);

    ofstream file("menu.txt", ios::app); // Use ofstream for appending

    if (file.is_open()) {
        file << newItem.bakeryID << " " << newItem.bakeryItem << " " << newItem.itemPrice << endl;
        file.close();
        cout << "\n\nBakery item added successfully!" << endl;

    }
    else {
        cerr << "Error!! Failed to open this file" << endl;
    }
}



//Staff Details 
struct Staff {
    int staffID;
    string memberName;
    double memberAge;
};



// Function to display staff details

vector<Staff> staffDetails; // vector

void displaystaffDetails() {
    system("cls");

    cout << "\n--------------------------" << endl;
    cout << "       Staff Details" << endl;
    cout << "--------------------------" << endl;

    staffDetails.clear();

    ifstream file("staff.txt"); // Use ifstream for reading
    if (!file.is_open()) {
        cout << "Failed to open menu.txt" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {

        istringstream iss(line);
        Staff details;

        if (iss >> details.staffID >> details.memberName >> details.memberAge) {
            staffDetails.push_back(details);
        }
        else {
            cerr << "Error: Invalid data format in menu.txt" << endl;
        }
    }
    file.close();
}




// Function to add staff
void addstaffDetails() {

    cout << "\n--------------------------" << endl;
    cout << "       Add Staff" << endl;
    cout << "--------------------------" << endl;

    cout << "\n\nEnter Staff ID: ";
    int id;
    cin >> id;

    cout << "Enter Member Name : ";
    string name;
    cin.ignore();
    getline(cin, name);

    cout << "Enter Member Age : ";
    double age;
    cin >> age;

    Staff newMember = { id, name, age };
    staffDetails.push_back(newMember);

    ofstream file("staff.txt", ios::app); // Use ofstream for appending

    if (file.is_open()) {

        file << newMember.staffID << " " << newMember.memberName << " " << newMember.memberAge << endl;
        file.close();

        cout << "\n\nMember added successfully!" << endl;
    }

    else {
        cerr << "Error!! Failed to open this file" << endl;
    }
}




//select bakery items
vector<Item> selectbakeryItems() {

    vector<Item> selectedItems; //New vector for select items

    int itemId;

    cout << "\n\nSelect Bakery Items (Enter 0 to finish):\n";

    while (true) {

        cout << "Enter item ID (0 to finish): ";
        cin >> itemId;

        if (itemId == 0) {
            break;
        }
        bool found = false;

        for (const Item& item : bakeryItems) {

            if (item.bakeryID == itemId) {
                selectedItems.push_back(item);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Invalid item ID. Please enter a valid ID." << endl;
        }
    }
    return selectedItems;
}


// Function to calculate the total price of selected items
double calculatetotalPrice(const vector<Item>& selectedItems) {
    double totalPrice = 0;

    for (const Item& item : selectedItems) {
        totalPrice += item.itemPrice;
    }
    return totalPrice;
}

// Function to execute a bill
void executeBill() {
    vector<Item> selectedItems = selectbakeryItems();

    double totalPrice = calculatetotalPrice(selectedItems);
    cout << "\nBill executed successfully. Total Price: Rs." << totalPrice << endl;
}



// Function to print a bill
void printBill(const vector<Item>& selectedItems, double totalPrice) {

    system("cls"); //clear console

    cout << "\n--------------------------" << endl;
    cout << "           Bill" << endl;
    cout << "--------------------------\n" << endl;
    cout << "Selected Items:\n";

    for (const Item& item : selectedItems) {
        cout << "\nID: " << item.bakeryID << endl << "Name: " << item.bakeryItem << endl << "Price: Rs." << item.itemPrice << endl;
    }

    cout << "\nTotal Price: Rs." << totalPrice << endl;
    cout << "\n--------------------------\n\n\n" << endl;
}







int main() {



    const string adminUsername = "admin"; //admin username
    const string adminPassword = "admin123"; //admin password

    const string cashierUsername = "cashier"; //cashier username
    const string cashierPassword = "cashier123"; //cashier password

    // Max 3 Attempts 
    int adminAttempts = 0;
    int cashierAttempts = 0;
    int maxAttempts = 3;

    vector<Item> selectedItems;

    while (true) {
        system("cls");

        displayHome(); // Home function calling

        // User Type selection (Admin or Cashier)
        cout << "1. Admin\n";
        cout << "2. Cashier\n";
        cout << "3. User Guild\n";
        cout << "4. Exit\n" << endl;
        cout << "Select User Choice : ";
        int userType;
        cin >> userType;


        switch (userType) {

        case 1:
            //Admin Section
            while (adminAttempts < maxAttempts) {
                cout << "\nEnter Admin Username: ";
                string username;
                cin >> username;

                cout << "Enter Admin Password: ";
                string password;
                cin >> password;

                if (username == adminUsername && password == adminPassword) {
                    system("cls");
                    cout << "\nAdmin Login Successful. Welcome, Admin!\n\n" << endl;

                    // Admin view
                    int adminView;
                    do {
                        // Display admin menu
                        cout << "\n-----------------------------------" << endl;
                        cout << "\n  Bun Talk Restaurant Admin Menu\n" << endl;
                        cout << "-----------------------------------\n";
                        cout << endl << endl;
                        cout << "1. View Bakery Items" << endl;
                        cout << "2. Add New Bakery Items" << endl;
                        cout << "3. Add Staff" << endl;
                        cout << "4. View Staff Details" << endl;
                        cout << "5. Log Out" << endl;
                        cout << "\nEnter Your Choice: ";
                        cin >> adminView;

                        // Admin select options
                        switch (adminView) {
                        case 1:
                            displaybakeryItems();
                            for (const Item& item : bakeryItems) {
                                cout << "\nID: " << item.bakeryID << endl << "Name: " << item.bakeryItem << endl << "Price: Rs." << item.itemPrice << endl;
                            }
                            break;

                        case 2:
                            addBakeryItem();
                            break;

                        case 3:
                            addstaffDetails();
                            break;

                        case 4:
                            displaystaffDetails();
                            for (const Staff& staff : staffDetails) {
                                cout << "\nID: " << staff.staffID << endl << "Name: " << staff.memberName << endl << "Age: " << staff.memberAge << endl;
                            }
                            break;

                        case 5:
                            cout << "\nLog out Success!!.\n"; // Log out
                            break;

                        default:
                            cout << "\nInvalid choice. Please enter a valid option." << endl;
                            break;
                        }
                    } while (adminView != 5);
                    break;

                    adminAttempts = 0;
                    break;
                }
                else {
                    adminAttempts++;
                    cout << "\n\nLogin Failed. Remaining Attempts: " << maxAttempts - adminAttempts << endl;
                }
            }

            if (adminAttempts == maxAttempts) {
                cout << "\n\nSorry, can't access the system --Maximum login attempts reached for Admin.--" << endl;
            }
            break;

        case 2:

            //Cashier Section
            while (cashierAttempts < maxAttempts) {
                cout << "\nEnter Cashier Username: ";
                string username;
                cin >> username;

                cout << "Enter Cashier Password: ";
                string password;
                cin >> password;

                if (username == cashierUsername && password == cashierPassword) {
                    system("cls");  // Clear console
                    cout << "\nCashier Login Successful. Welcome, Cashier!\n\n" << endl;

                    // Cashier view
                    int cashierView;
                    do {
                        // Display cashier menu
                        cout << "\n-----------------------------------" << endl;
                        cout << "\n  Bun Talk Restaurant Cashier Menu\n" << endl;
                        cout << "-----------------------------------\n";
                        cout << endl << endl;
                        cout << "1. View Bakery Items" << endl;
                        cout << "2. Select Bakery Items" << endl;
                        cout << "3. Execute a bill" << endl;
                        cout << "4. Print bill" << endl;
                        cout << "5. Help" << endl;
                        cout << "6. Exit\n\n" << endl;
                        cout << "Enter Your Choice : ";
                        cin >> cashierView;

                        // Cashier select options
                        switch (cashierView) {
                        case 1:
                            displaybakeryItems();
                            for (const Item& item : bakeryItems) {
                                cout << "\nID: " << item.bakeryID << endl << "Name: " << item.bakeryItem << endl << "Price: Rs." << item.itemPrice << endl;
                            }
                            break;

                        case 2:
                            cout << "\n\nSelect Bakery Items:\n";
                            selectedItems = selectbakeryItems();  // Assign the result to selectedItems
                            break;

                        case 3:
                            if (selectedItems.empty()) {
                                cout << "\nPlease select items first before executing a bill.\n";
                            }
                            else {
                                cout << "\n--------------------------" << endl;
                                cout << "       Execute a Bill" << endl;
                                executeBill(); // ExecuteBill() function calling
                            }
                            break;

                        case 4:
                            if (!selectedItems.empty()) {
                                double totalPrice = calculatetotalPrice(selectedItems);
                                printBill(selectedItems, totalPrice);
                            }
                            else {
                                cout << "\nNo items selected. Cannot print a bill.\n";
                            }
                            break;

                        case 5:
                            system("cls"); // Clear console
                            displayHelp(); // Help function calling
                            break;

                        case 6:
                            cout << "\nLog out.\n"; // Log out
                            break;

                        default:
                            cout << "\nInvalid choice. Please enter a valid option." << endl;
                            break;
                        }
                    } while (cashierView != 6);
                    break;

                    adminAttempts = 0;
                    break;

                }
                else {
                    cashierAttempts++;
                    cout << "\n\nLogin Failed. Remaining Attempts: " << maxAttempts - cashierAttempts << endl;
                }
            }

            if (cashierAttempts == maxAttempts) {
                cout << "\n\nSorry Can't Access the System --Maximum login attempts reached for Cashier.--" << endl;
            }
            break;


        case 3:

            userGuild(); //User Guild Function Calling

            //For the go back to main menu
            int guidMenu;
            cout << "\n\nPress 0 to back to main menu : ";
            cin >> guidMenu;


            break;

        case 4:
            //For the exit the program
            cout << "\nExit successfull\n";
            return 0;

        default:

            //User entered invalid user choise
            cout << "\nInvalid User Choice. Please enter a valid user choice number." << endl;
            int invalidOp;
            cout << "\n\nPress 0 to back to main menu and try again : ";
            cin >> invalidOp;

            break;
        }
    }
    return 0;
}
