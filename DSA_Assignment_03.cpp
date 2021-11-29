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

    void addData(string patientId, string name, string admissionDate, string diseaseDiagnosis, string status){
        this->patientId = patientId;
        this->name = name;
        this->admissionDate = admissionDate;
        this->diseaseDiagnosis = diseaseDiagnosis;
        this->status = status;
    }

    string getPatientId(){
        return patientId;
    }
    string getName(){
        return name;
    }
    string getAdmissionDate(){
        return admissionDate;
    }
    string getDiseaseDiagnosis(){
        return diseaseDiagnosis;
    }
    string getStatus(){
        return status;
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

struct TNode{
public:
    PatientData data;
    TNode *left;
    TNode *right;
};

class HospitalData{
private:
    TNode *root;
    int size;

    TNode* addPatient(TNode* node, PatientData data){
        if(node == NULL){
            TNode *newNode = new TNode();
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        if(data.getPatientId() < node->data.getPatientId()){
            node->left = addPatient(node->left, data);
        }
        else if(data.getPatientId() > node->data.getPatientId()){
            node->right = addPatient(node->right, data);
        }
        return node;
    }

    TNode* searchPatient(TNode* node, string patientId){
        if(node == NULL){
            return NULL;
        }
        if(patientId < node->data.getPatientId()){
            return searchPatient(node->left, patientId);
        }
        else if(patientId > node->data.getPatientId()){
            return searchPatient(node->right, patientId);
        }
        else{
            return node;
        }
    }

public:
    HospitalData(){
        root = NULL;
        size = 0;
    }

    void addPatient(PatientData data){
        root = addPatient(root, data);
        size++;
    }
    void searchPatient(string patientId){
        TNode *node = searchPatient(root, patientId);
        if(node == NULL){
            cout << "\t\n Patient not found!\n";
        }
        else{
            node->data.print();
        }
    }
};


int main(){
    PatientData pat[2];
    for (int i = 0; i < 2; i++)
    {
        string id = to_string(i);
        pat[i].addData(id, "abc", "12-01-10", "type ezz after losing badly :'()", "Discharged");
        //pat[i].print();
    }

    HospitalData hos;
    for (int i = 0; i < 2; i++)
    {
        hos.addPatient(pat[i]);
    }
    hos.searchPatient("0");
    hos.searchPatient("1");
}