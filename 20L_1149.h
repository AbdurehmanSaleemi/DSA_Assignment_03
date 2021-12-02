#include <iostream>
#include <fstream>
using namespace std;

class PatientData{
private:
    string patientId;
    string name;
    string admissionDate;
    string diseaseDiagnosis;
    string status;

public:
    PatientData();
    PatientData(string, string, string , string, string);
    void addData(string, string, string , string, string);
    void editPatientData(string, string, string , string, string);
    string getPatientId();
    string getName();
    string getAdmissionDate();
    string getDiseaseDiagnosis();
    string getStatus();
    void print();
};

class TNode{
public:
    PatientData data;
    TNode *left;
    TNode *right;

    TNode();
    friend TNode* leftRotate(TNode*);
    friend TNode* rightRotate(TNode*);
};

class Hospital{
private:
    TNode *root;
    int size;
public:
    Hospital();
    TNode* insertPatient(TNode*, PatientData);
    TNode* search(TNode*, string);
    TNode* deletePatient(TNode*, string);
    void printInorder(TNode*);
    void print();
    void insert(PatientData);
    void deletePatient(string patientID);
    void searchP(string patientID);
};