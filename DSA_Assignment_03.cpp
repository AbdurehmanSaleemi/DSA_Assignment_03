#include <iostream>
using namespace std;

class PatientData{
private:
    string patientId;
    string name;
    string admissionDate;
    string diseaseDiagnosis;
    string status;

public:
    PatientData(){
        patientId = "";
        name = "";
        admissionDate = "";
        diseaseDiagnosis = "";
        status = "";
    }
    PatientData(string patientId, string name, string admissionDate, string diseaseDiagnosis, string status){
        this->patientId = patientId;
        this->name = name;
        this->admissionDate = admissionDate;
        this->diseaseDiagnosis = diseaseDiagnosis;
        this->status = status;
    }

    void print(){
        cout << "\t\n --- Patient Record --- \n";
        cout << "\t" << patientId << endl;
        cout << "\t" << name << endl;
        cout << "\t" << admissionDate << endl;
        cout << "\t" << diseaseDiagnosis << endl;
        cout << "\t" << status << endl;
    }
};

int main(){
    PatientData patient1("01", "Abc", "01-02-01", "Thyroid Gland", "Discharged");
    PatientData patient2("02", "Def", "02-03-10", "Cancer", "Hospitalized");
    patient1.print();
    patient2.print();
}