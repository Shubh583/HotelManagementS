#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;
int total_room = 20; int availableRoom = 20;
class costumers {
public:
    string date;
    int room;
    vector<string>partner;
    string id;
};
vector<costumers>record;
void Book_room(int reqroom, string ID, vector<string>& people, string dt) {
    costumers a;
    a.room = reqroom; a.id = ID; a.partner = people; a.date = dt;
    availableRoom = total_room - reqroom;
    record.push_back(a);
    cout << " \n\t** congratulation your room/rooms are booked **\n";
}

void show_record() {
    for (int i = 0; i < record.size(); i++) {
        cout << record[i].date; cout << "   "; cout << record[i].room << "   ";
        for (int j = 0; j < record[i].partner.size(); j++) {
            cout << endl << record[i].partner[j] << endl;
        }cout << endl << endl;
    }cout << endl;
}
vector<string>menu;
void Recipe(string s) {
    menu.push_back(s);
}

int main() {

    int croom = 0; int cpartner = 0;
    cout << "\n \t ** Provide the Description of today's MEAL ** \n";

    int mn;
    cout << "\nEnter Total number of menu\n "; cin >> mn;
    cout << "\nEnter Recipe's\n" << endl;
    while (mn--) {
        string s = "";
        cin >> s;
        Recipe(s);
    }


Label1: { system("cls");
    int option;
    cout << "=========================================\n";
    cout << "| *  Wel-Come To The Sunrise Hotel  *   |\n";
    cout << "=========================================\n";
    cout << "!                                       !\n";
    cout << "! 1. Book A Room                        !\n";
    cout << "! 2. View Costumer Record               !\n";
    cout << "! 3. Today's Menu                       !\n";
    cout << "! 4. Generate Bill                      !\n";
    cout << "! 5. About                              !\n";
    cout << "!                                       !\n";
    cout << "=========================================\n";
    cout << endl;
    cin >> option;
    if (option == 1)
    {
        if (availableRoom == 0)cout << "\nSorry all rooms are full \n";
        else {
            string date;
            cout << "\nEnter Date \n ";
            cin >> date;
            cout << "\nHow many people are you  \n ";
            int partner;
            cin >> partner; cpartner = partner;
            vector<string>people(partner);
            cout << "\n Provide the full names of your Companions \n ";
            for (int i = 0; i < partner; i++) {
                string name = ""; string surname = "";// string fullname="";
                cin >> name >> surname;
                people[i] = name + " " + surname;
            }
            cout << "\nPlease enter any 1 Identity card of any 1 adult person  - \n 1. Driving licence \n 2. Aadhar card \n 3. pan card \n 4. voter id \n";
            cout << "\n\nEnter the Identification seriel number-\n";

            int n; cin >> n; string ID = ""; string FID = ""; bool check = true;
            if (n == 1) {
                cout << "\n Enter 16 Digit Driving Licence Number-\n";
                cin >> ID;
                FID = "Driving licence = " + ID; if (ID.size() < 16 || ID.size() > 16) { cout << "Invalid Number!!!\n"; check = false; Sleep(1500); system("cls"); }
            }
            else if (n == 2) {
                cout << "\n Enter 12 Digit Aadhar Number-\n";
                cin >> ID; if (ID.size() < 12 || ID.size() > 12) { cout << "Invalid Number!!!\n"; check = false; Sleep(1500); system("cls"); }
                FID = "Aadhar card = " + ID;
            }
            else if (n == 3) {
                cout << "\n Enter 10 Digit Pan Number-\n";
                cin >> ID;
                if (ID.size() < 10 || ID.size() > 10) { cout << "Invalid Number!!!\n"; check = false; Sleep(1500); system("cls"); }
                FID = "Pan card = " + ID;
            }
            else if (n == 4) {
                cout << "\n Enter 10 Digit Voter ID Number-\n";
                cin >> ID; if (ID.size() < 10 || ID.size() > 10) { cout << "Invalid Number!!!\n"; check = false; Sleep(1500); system("cls"); }
                FID = "Voter card = " + ID;
            }
            int reqroom = 0;
            reqroom = partner % 4 == 0 ? partner / 4 : (partner / 4) + 1;
            croom = reqroom;
            if (reqroom > availableRoom) {
                cout << " Heartly Sorry!! Available rooms are less then required room. \n  \n";
            }
            else if (check == true) Book_room(reqroom, FID, people, date);

            cout << "\nEnter 'yes' for goto main menu \n"; string like = "";
            cin >> like;
            if (like == "yes")goto Label1;   //else exit;   
        }
    }
    else if (option == 2) {
        if (record.size() > 0)show_record();
        else cout << "\n\tNo record found!!! \n";
        cout << "\nEnter 'yes' for goto main menu \n"; string like = "";
        cin >> like;
        if (like == "yes")goto Label1;   //else exit;   
    }
    else  if (option == 3) {
        cout << "\n** Our delicious food and your trust making relation much strong **\n";
        for (int i = 0; i < menu.size(); i++) {
            cout << menu[i] << endl;
        }
        cout << "\n Enter 'yes' for goto main menu \n"; string like = "";
        cin >> like;
        if (like == "yes")goto Label1;   ///else exit;   
    }
    else if (option == 4) {
        int amount = croom * 2000;
        if (amount == 0)cout << "\nPlease give us a chance to serve you first. \n\n";
        else {
            int canteen_bill = 150 * cpartner;
            int Total_charge = amount + canteen_bill;
            double gst = 0.0 + Total_charge * (18.0 / 100);
            double grand_total = Total_charge + gst;
            system("cls");
            cout << "=========================================\n";
            cout << "|           * Visit again *             |\n";
            cout << "=========================================\n";
            cout << "!                                       !\n";
            cout << "!   Room Charge-   " << amount << "                 !\n";
            cout << "!   Canteen Charge- " << canteen_bill << "                 !\n";
            cout << "!   GST-           " << gst << "                  !\n";
            cout << "!   Total Charge-  " << grand_total << "                 !\n";
            cout << "!                                       !\n";
            cout << "=========================================\n";
        }
        cout << "\n Enter 'yes' for goto main menu \n"; string like = "";
        cin >> like;
        if (like == "yes")goto Label1;   //else exit;   
    }

    else if (option == 5) {
        cout << "Hotel Sunrise has been serving since 1995.\n";
        cout << "Here one gets assurance of purity and faith with food.\n";


        cout << "\n Enter 'yes' for goto main menu \n"; string like = "";
        cin >> like;
        if (like == "yes")goto Label1;   //else exit; 

    }

    }
}

