#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    //initialize resources
    int trucks;        // number of trucks 
    int supplyPacks; // food and other supplies
    int helicopters;
    int boats;
    int ambulances;
    int police;
    string mode; //not resource
    cout << "WHICH MODE OF RESOURCES WOULD YOU LIKE TO BEGIN WITH (sufficient or insufficient): "; // user enters sufficient or insufficient
    cin >> mode;
    //counters for summary at the end
    int successfulrequest = 0;
    int deferredrequest = 0;

    if (mode == "sufficient")
    {
        // sufficient resources
        trucks = 10;
        supplyPacks = 120;
        helicopters = 2;
        boats = 3;
        ambulances = 4;
        police = 3;
    }
    else {
        //insufficient resources
        trucks = 2;
        supplyPacks = 10;
        helicopters = 1;
        boats = 2;
        ambulances = 1;
        police = 1;
    }

    //Request Details
    string damage;                    // Low, Medium, High
    int familiesAffected;        // range: 10 to 200
    string accessRoute;      // Open, Damaged,Closed
    bool floodWarning;         // true = Yes, false = No
    bool medicalNeed;          // true = Yes, false = No
    bool previousAid;                 // true = Yes, false = No

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
        transform(damage.begin(), damage.end(), damage.begin(), ::tolower);//for converting input to lowercase

        cout << "Enter number of families affected (10 to 200):     ";
        cin >> familiesAffected;

        cout << "Enter access route status (Open, Damaged, Closed): ";
        cin >> accessRoute;
        transform(accessRoute.begin(), accessRoute.end(), accessRoute.begin(), ::tolower);//for converting input to lowercase

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
        else {
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
            familiesScore = 15;       // 101-149
        }
        else {
            familiesScore = 20;       // 150+
        }

        // Route score (Open = 0, otherwise damaged/closed = 7)
        int routeScore = (accessRoute == "open") ? 0 : 20;

        // Flood warning score
        int floodScore = floodWarning ? 9 : 0;

        // Medical need score
        int medicalScore = medicalNeed ? 16 : 0;

        // Previous aid score will get lower priority
        int previousAidScore = previousAid ? 8 : 0;


        int needscore = (2 * damageScore) + familiesScore + routeScore + (2 * floodScore) + (2 * medicalScore) - previousAidScore;


        // Resources needed by the chosen action
        string actionName;
        int needTrucks = 0, needPacks = 0, needHelicopters = 0, needBoats = 0, needAmbulances = 0, needpolice = 0;

        char action;
        // 1. Set resource requirements for current action

        if (needscore >= 135)
        {
            action = 'A';
        }
        else if (needscore >= 60)
        {
            action = 'B';
        }
        else if (needscore >= 41)
        {
            action = 'C';
        }
        else
        {
            action = 'D';
        }


        while (true)
        {


            switch (action) {
            case 'A':
                actionName = "Full Relief";
                needTrucks = 2;
                needPacks = 35;
                needAmbulances = 1;
                needpolice = 1;

                if (needscore >= 135 && accessRoute == "damaged")
                {
                    needHelicopters = 1;
                }
                else {
                    needHelicopters = 0;
                }
                if (needscore >= 135 && floodWarning == true)
                {
                    needBoats = 1;
                }
                else {
                    needBoats = 0;
                }
                break;
            case 'B':
                actionName = "Standard Relief";
                needTrucks = 1;
                needPacks = 20;
                needHelicopters = 0;
                needAmbulances = 1;
                needpolice = 0;
                if (needscore >= 60 && floodWarning == true)
                {
                    needBoats = 1;
                }
                else {
                    needBoats = 0;
                }
                break;
            case 'C':
                actionName = "Emergency Kit Only";
                needTrucks = 1;
                needPacks = 5;
                needHelicopters = 0;
                needAmbulances = 1;
                needpolice = 0;
                if (needscore >= 41 && floodWarning == true)
                {
                    needBoats = 1;
                }
                else {
                    needBoats = 0;
                }
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
                cout << "\n----- REQUEST DETAILS -----" << endl;
                cout << "Damage Level:          " << damage << endl;
                cout << "Families Affected:     " << familiesAffected << endl;
                cout << "Access Route:          " << accessRoute << endl;
                cout << "Flood Warning:         " << (floodWarning ? "Yes" : "No") << endl;
                cout << "Medical Need:          " << (medicalNeed ? "Yes" : "No") << endl;
                cout << "Previous Aid Received: " << (previousAid ? "Yes" : "No") << endl;

                cout << "Resources Allocated: " << endl;
                cout << "Trucks:       " << needTrucks << endl;
                cout << "Supply Packs: " << needPacks << endl;
                cout << "Helicopters:  " << needHelicopters << endl;
                cout << "Boats:        " << needBoats << endl;
                cout << "Ambulances:   " << needAmbulances << endl;
                cout << "Police:       " << needpolice << endl;
                cout << "needscore     " << needscore << endl;

                // Update remaining resources
                trucks -= needTrucks;
                supplyPacks -= needPacks;
                helicopters -= needHelicopters;
                boats -= needBoats;
                ambulances -= needAmbulances;
                police -= needpolice;
                if (action == 'D')
                {
                    deferredrequest++;
                }
                else
                {
                    successfulrequest++;
                }
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
                else {
                    action = 'D';
                }
            
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

    cout << "\n-----SUMMARY---------" << endl;
    cout << "successful requests: \t" << successfulrequest << endl;
    cout << "deferred requests: \t" << deferredrequest << endl;
    system("pause");
    return 0;
}