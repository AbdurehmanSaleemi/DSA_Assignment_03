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
        cout << patientId << endl;
        cout << name << endl;
        cout << admissionDate << endl;
        cout << diseaseDiagnosis << endl;
        cout << status << endl;
        cout << "------------------------------------ \n";
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

    //left rotation
    TNode* leftRotate(TNode* node){
        TNode *temp = node->right;
        node->right = temp->left;
        temp->left = node;
        return temp;
    }
    //right rotation
    TNode* rightRotate(TNode* node){
        TNode *temp = node->left;
        node->left = temp->right;
        temp->right = node;
        return temp;
    }

    // Search a patient record and move its level up
    TNode* searchAndMoveUp(TNode* node, string patientId){
        if(node == NULL){
            return NULL;
        }
        if(patientId < node->data.getPatientId()){
            node->left = searchAndMoveUp(node->left, patientId);    //move left
            if(node->left != NULL && node->left->data.getPatientId() < node->data.getPatientId()){
                node = rightRotate(node);   //right rotation
            }
        }
        else if(patientId > node->data.getPatientId()){
            node->right = searchAndMoveUp(node->right, patientId);      //move right
            if(node->right != NULL && node->right->data.getPatientId() > node->data.getPatientId()){
                node = leftRotate(node);        //left rotation
            }
        }
        return node;
    }

    // delete the patient record
    TNode* deletePatient(TNode* node, string patientId){
        if(node == NULL){
            return NULL;
        }
        if(patientId < node->data.getPatientId()){
            node->left = deletePatient(node->left, patientId);
        }
        else if(patientId > node->data.getPatientId()){
            node->right = deletePatient(node->right, patientId);
        }
        else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                node = NULL;
            }
            else if(node->left == NULL){
                TNode *temp = node;
                node = node->right;
                delete temp;
            }
            else if(node->right == NULL){
                TNode *temp = node;
                node = node->left;
                delete temp;
            }
            else{
                TNode *temp = node->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = deletePatient(node->right, temp->data.getPatientId());
            }
        }
        return node;
    }

    // print the tree in inorder
    void printInorder(TNode* node){
        if(node == NULL){
            return;
        }
        printInorder(node->left);
        node->data.print();
        printInorder(node->right);
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

    void searchAndMoveUp(string patientId){
        root = searchAndMoveUp(this->root, patientId);
    }

    void printInorder(){
        cout << "\t\n ------------ Inorder Record ----------- \n";
        printInorder(root);
        cout << "------------------------------------ \n";
    }

    void deletePatient(string patientId){
        root = deletePatient(root, patientId);
        size--;
    }
};


int main(){
    PatientData patientData;
    PatientData patientDataTemp[10];

    patientDataTemp[0] = PatientData("P001", "John", "01/01/2020", "Fever", "Admitted");
    patientDataTemp[1] = PatientData("P002", "Mary", "02/02/2020", "Cancer", "Admitted");
    patientDataTemp[2] = PatientData("P003", "Peter", "03/03/2020", "Heart", "Admitted");
    patientDataTemp[3] = PatientData("P004", "Linda", "04/04/2020", "Stomach", "Admitted");
    patientDataTemp[4] = PatientData("P005", "John", "05/05/2020", "Fever", "Admitted");
    patientDataTemp[5] = PatientData("P006", "Mary", "06/06/2020", "Cancer", "Admitted");
    HospitalData *hospitalData = new HospitalData();

    for(int i = 0; i < 5; i++){
        hospitalData->addPatient(patientDataTemp[i]);
    }
    hospitalData->printInorder();
    hospitalData->searchAndMoveUp("P002");
    hospitalData->printInorder();
}