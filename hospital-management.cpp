#include <iostream>
#include <string>
using namespace std;
struct Patient {
    string name;
    int age;
    string medicalCondition;
};

void addNewPatient(Patient patients[], int& patientCount) {
	   char addAnother;
    
    do {
    cout << "Enter patient details:\n";
    cout << "Name: ";
    cin >> patients[patientCount].name;
    cout << "Age: ";
    cin >> patients[patientCount].age;
    cout << "Medical Condition: ";
    cin >> patients[patientCount].medicalCondition;
    cout << "Patient added successfully!\n";
    patientCount++;
    cout<<"Do You Want to Add Another Patient:-";
       cin >> addAnother;
    } while (addAnother == 'y' || addAnother == 'Y');
}


void displayPatientDetails(const Patient patients[], int patientCount) {
	if(patientCount==0){
		cout<<"Sorry there are no Patients Entered Thankyou...\n\n";
	}
	else{
	
    cout << "Patient Details:\n";
    for (int i = 0; i < patientCount; ++i) {
        cout << "Patient " << i + 1 << ":\n";
        cout << "Name: " << patients[i].name << "\n";
        cout << "Age: " << patients[i].age << "\n";
        cout << "Medical Condition: " << patients[i].medicalCondition << "\n\n";
    }}
}


void searchPatient(const Patient patients[], int patientCount) {
    string searchQuery;
    cout << "Enter name or medical condition to search: ";
    cin >> searchQuery;  
    cout << "Search Results:\n";
    bool found = false;
    for (int i = 0; i < patientCount; ++i) {
        if (patients[i].name.find(searchQuery) != string::npos ||
            patients[i].medicalCondition.find(searchQuery) != string::npos) {
            cout << "Patient " << i + 1 << ":\n";
            cout << "Name: " << patients[i].name << "\n";
            cout << "Age: " << patients[i].age << "\n";
            cout << "Medical Condition: " << patients[i].medicalCondition << "\n\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No matching patients found.\n";
    }
}

int calculateNumberOfPatients(int patientCount) {
    return patientCount;
}

int main() {
    const int maxPatients = 100;
    Patient patients[maxPatients];
    int patientCount = 0;

    int choice;
    do {
	        cout << "Hospital Management System\n";
        cout << "1. Add New Patient\n";
        cout << "2. Display Patient Details\n";
        cout << "3. Search Patient by Name/Condition\n";
        cout << "4. Calculate the Number of Patients\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNewPatient(patients, patientCount);
                break;
            case 2:
                displayPatientDetails(patients, patientCount);
                break;
            case 3:
                searchPatient(patients, patientCount);
                break;
            case 4:
                cout << "Number of Patients: " << calculateNumberOfPatients(patientCount) << "\n";
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}