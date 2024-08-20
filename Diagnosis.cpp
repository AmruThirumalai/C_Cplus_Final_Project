/*
Name: Amru Thirumalai
Class: Online
Date 4/24/2024
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Base class 
class Illness {
protected:
    vector<string> symptoms;
public:
    Illness() {}            
    virtual ~Illness() {}

    virtual string diagnose() = 0;
};

// Derived class for COVID-19
class COVID19 : public Illness {
public:
    COVID19() {
        // Initialize symptoms for COVID-19
        symptoms = {"present", "present", "present", "sometimes", "sometimes", "absent", "sometimes"};
    }

    string diagnose() override 
	{
        // Check if symptoms match COVID-19 pattern
        int presentCount = 0;
        for (const auto& symptom : symptoms)
		{
        	if(symptom == "present") 
			{
        		presentCount++;
			}
		}
		//Check if the required symptoms are present
		if(presentCount >= 3)
		{
			return "COVID-19";
		}
		else
		{
			return "Other illness";
		}
	}
};

// Derived class for Cold
class Cold : public Illness {
public:
    Cold() {
        // Initialize symptoms for Cold
        symptoms = {"sometimes", "sometimes", "absent", "present", "sometimes", "present", "sometimes"};
    }

    string diagnose() override {
        // Count the number of present symptoms
        int presentCount = 0;
        for (const auto& symptom : symptoms) {
            if (symptom == "present" ){
                presentCount++;
            }
        }
        // Determine diagnosis based on symptom count
        if (presentCount >= 2)
            return "Cold";
        else
            return "Other illness";
    }
};

// Derived class for Flu
class Flu : public Illness {
public:
    Flu() {
        // Initialize symptoms for Flu
        symptoms = {"present", "present", "absent", "sometimes", "present", "absent", "present"};
    }

    string diagnose() override {
        // Check if symptoms match Flu pattern
        int presentCount = 0;
        for (const auto& symptom : symptoms) {
            if (symptom == "present"){
            	presentCount++;
			}
		}
		if(presentCount >= 3){
			return "Flu";
		}
		else{
            return "Other illness";
        }
    }
};

int main() {
    srand(time(0));     // Seed the random number generator using current time

    cout << "Symptoms Checker\n";
    cout << "Guide: \t * Common \t + Sometimes/Rarely \t - NO\n";
    
    cout << "---------------------------------------------------------------\n";
    cout << "|      Symptoms     |    COVID-19    |    Cold    |    Flu    | \n";
    cout << "|       Fever       |        *       |      +     |     *     |\n";
    cout << "|       Cough       |        *       |      +     |     *     |\n";
    cout << "|Shortness of Breath|        *       |      -     |     -     |\n";
    cout << "|     Runny Nose    |        +       |      *     |     +     |\n";
    cout << "|     Headaches     |        +       |      +     |     *     |\n";
    cout << "|     Sneezing      |        -       |      *     |     -     |\n";
    cout << "|     Fatigue       |        +       |      +     |     *     |\n";
    cout << "---------------------------------------------------------------\n";

    cout << "Enter the number of patients to check: ";
    int numPatients;
    cin >> numPatients; // Read the number of patients from user input
    cout << "Thank you...\n\n";

    int covidCount = 0;
	int coldCount = 0; 
	int fluCount = 0;
	int otherCount = 0;   // Initialize counters for each illness type

    // Loop through each patient
    for (int i = 1; i <= numPatients; ++i) {
        int illnessChoice = rand() % 3;     // Randomly choose an illness type
        Illness* illnessPtr;                // Pointer to base class
        switch (illnessChoice) {
            case 0:
                illnessPtr = new COVID19(); // Create object of COVID19 class
                break;
            case 1:
                illnessPtr = new Cold();    // Create object of Cold class
                break;
            case 2:
                illnessPtr = new Flu();     // Create object of Flu class
                break;
        }

        string diagnosis = illnessPtr->diagnose();   // Determine diagnosis for the patient
        // Update counters based on diagnosis
        if (diagnosis == "COVID-19")
            covidCount++;
        else if (diagnosis == "Cold")
            coldCount++;
        else if (diagnosis == "Flu")
            fluCount++;
        else
            otherCount++;

        delete illnessPtr;  // Free memory allocated for the object
    }

    double totalPatients = numPatients;   // Total number of patients checked
    // Calculate percentages for each illness type
    double covidPercent = (double)covidCount / totalPatients * 100;
    double coldPercent = (double)coldCount / totalPatients * 100;
    double fluPercent = (double)fluCount / totalPatients * 100;
    double otherPercent = (double)otherCount / totalPatients * 100;

	
	// Display final report with a plus sign for each patient checked
	cout << "\nFinal Report\n";
	cout << "------------\n";
	//symptoms tally
	cout << covidCount << " patients have symptoms of COVID-19\n";
	cout << coldCount << " patients have symptoms of Cold\n";
	cout << fluCount << " patients have symptoms of Flu\n";
	cout << otherCount << " patients have symptoms of other illness\n";
	//symptoms percentage
	cout << "\n\nCOVID-19: (" << covidPercent << "%) ";
	for (int i = 0; i < covidCount; ++i) cout << "+";
	cout << "\nCold: (" << coldPercent << "%) ";
	for (int i = 0; i < coldCount; ++i) cout << "+";
	cout << "\nFlu: (" << fluPercent << "%) ";
	for (int i = 0; i < fluCount; ++i) cout << "+";
	cout << "\nOther illness:  (" << otherPercent << "%) ";
	for (int i = 0; i < otherCount; ++i) cout << "+";
	cout << endl;

    return 0;
}
