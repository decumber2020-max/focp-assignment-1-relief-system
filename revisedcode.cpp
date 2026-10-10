#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // Resources available for delivery
    int trucks = 5;        // number of trucks 
    int supplyPacks = 120; // food and other supplies
    int helicopters = 2;
    int boats = 3;
    int ambulances = 4;
    int police = 3;

    //Request Details
    string damage;                    // Low, Medium, High
    int familiesAffected;        // range: 10 to 200
    string accessRoute;      // Open, Damaged,Closed
    bool floodWarning;         // true = Yes, false = No
    bool medicalNeed;          // true = Yes, false = No
    bool previousAid;                 // true = Yes, false = No

    cout << "-----ALL RESOURCES---------" << endl;
    cout << "Trucks: \t" << trucks << endl;
    cout << "Supply Packs: \t" << supplyPacks << endl;
    cout << "Helicopters \t" << helicopters << endl;
    cout << "Boats:      \t" << boats << endl;
    cout << "Ambulances: \t" << ambulances << endl;
    cout << "police: \t" << police << endl;

    string request = "request";

    while (request != "stop") {
        cout << "\nEnter request (for aid) or enter stop (to finish):" << endl;
        cin >> request;

        if (request == "stop") {
            break;
        }
        //tkae input request details
        cout << "Enter damage level (Low,Medium,High):              ";
        cin >> damage;
        transform(damage.begin(), damage.end(), damage.begin(), ::tolower);

        cout << "Enter number of families affected (10 to 200):     ";
        cin >> familiesAffected;

        cout << "Enter access route status (Open, Damaged, Closed): ";
        cin >> accessRoute;
        transform(accessRoute.begin(), accessRoute.end(), accessRoute.begin(), ::tolower);

        cout << "Is there a flood warning? (true/false):            ";
        cin >> boolalpha >> floodWarning;

        cout << "Is there a medical need? (true/false):             ";
        cin >> boolalpha >> medicalNeed;

        cout << "Was previous aid given? (true/false):              ";
        cin >> boolalpha >> previousAid;


        // ---------- Need Score calculation ----------

        // Damage score
        int damageScore = 0;
        if (damage == "low") {
            damageScore = 10;
        }
        else if (damage == "medium") {
            damageScore = 20;
        }
        else if (damage == "high") {
            damageScore = 35;
        }

        // Families affected score
        int familiesScore = 0;
        if (familiesAffected <= 50) {
            familiesScore = 5;        // 1-50
        }
        else if (familiesAffected <= 100) {
            familiesScore = 10;       // 51-100
        }
        else if (familiesAffected < 150) {
            familiesScore = 15;       // 101-150
        }
        else {
            familiesScore = 20;       // 150+
        }

        // Route score (Open = 0, otherwise damaged/closed = 7)
        int routeScore = (accessRoute == "open") ? 0 : 7;

        // Flood warning score
        int floodScore = floodWarning ? 9 : 0;

        // Medical need score
        int medicalScore = medicalNeed ? 16 : 0;

        // Previous aid score will get lower priority
        int previousAidScore = previousAid ? 12 : 0;

        int needScore = damageScore + familiesScore + routeScore
            + floodScore + medicalScore - previousAidScore;

        // Resources needed by the chosen action
        string actionName;
        int needTrucks = 0, needPacks = 0, needHelicopters = 0, needBoats = 0, needAmbulances = 0, needpolice = 0;

        char action;
        // 1. Set resource requirements for current action
        if (needScore >= 80)
        {
            action = 'A';
        }
        else if (needScore >= 60) {
            action = 'B';
        }
        else if (needScore >= 30) {
            action = 'C';
        }
        else {
            action = 'D';
        }

        while (true)
        {
            

            switch (action) {
            case 'A':
                actionName = "Full Relief";
                needTrucks = 2;
                needPacks = 50;
                needHelicopters = 1;
                needBoats = 1;
                needAmbulances = 2;
                needpolice = 2;
                break;
            case 'B':
                actionName = "Standard Relief";
                needTrucks = 1;
                needPacks = 30;
                needHelicopters = 0;
                needBoats = 1;
                needAmbulances = 1;
                needpolice = 0;
                break;
            case 'C':
                actionName = "Emergency Kit Only";
                needTrucks = 1;
                needPacks = 10;
                needHelicopters = 0;
                needBoats = 0;
                needAmbulances = 1;
                needpolice = 1;
                break;
            case 'D':
                actionName = "Defer / Monitor";
                needTrucks = 0;
                needPacks = 0;
                needHelicopters = 0;
                needBoats = 0;
                needAmbulances = 0;
                needpolice = 0;
                break;


            }
            //check if sufficienct sources are available
            if (trucks >= needTrucks &&
                supplyPacks >= needPacks &&
                helicopters >= needHelicopters &&
                boats >= needBoats &&
                ambulances >= needAmbulances &&
                police >= needpolice)
            {
                // Perform the selected action
                cout << "\n----- Relief Action Details -----" << endl;
                cout << "\nSelected Action: " << actionName << endl;

                cout << "Resources Allocated: " << endl;
                cout << "Trucks:       " << needTrucks << endl;
                cout << "Supply Packs: " << needPacks << endl;
                cout << "Helicopters:  " << needHelicopters << endl;
                cout << "Boats:        " << needBoats << endl;
                cout << "Ambulances:   " << needAmbulances << endl;
                cout << "Police:       " << needpolice << endl;

                // Update remaining resources
                trucks -= needTrucks;
                supplyPacks -= needPacks;
                helicopters -= needHelicopters;
                boats -= needBoats;
                ambulances -= needAmbulances;
                police -= needpolice;
                break;
            }
            else
            {


                if (action == 'A')
                {
                    action = 'B';
                }
                else if (action == 'B')
                {
                    action = 'C';
                }
                else if (action == 'C')
                {
                    action = 'D';
                }
                else
                    action = 'D';
            }
        }
    }
    cout << "\n-----UPDATED RESOURCES---------" << endl;
    cout << "Trucks: \t" << trucks << endl;
    cout << "Supply Packs: \t" << supplyPacks << endl;
    cout << "Helicopters \t" << helicopters << endl;
    cout << "Boats:      \t" << boats << endl;
    cout << "Ambulances: \t" << ambulances << endl;
    cout << "police: \t\n" << police << endl;
    system("pause");
    return 0;
}