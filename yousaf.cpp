#include "yousaf.h"
#include <iostream>
#include <fstream>
using namespace std;

PatientData::PatientData()
{
    patientId = "";
    name = "";
    admissionDate = "";
    diseaseDiagnosis = "";
    status = "";
}

PatientData::PatientData(string pID, string pName, string pData, string pDiagnosis, string pStatus)
{
    patientId = pID;
    name = pName;
    admissionDate = pData;
    diseaseDiagnosis = pDiagnosis;
    status = pStatus;
}
void PatientData::addData(string pID, string pName, string pData, string pDiagnosis, string pStatus)
{
    patientId = pID;
    name = pName;
    admissionDate = pData;
    diseaseDiagnosis = pDiagnosis;
    status = pStatus;
}
void PatientData::editPatientData(string pID, string pName, string pData, string pDiagnosis, string pStatus)
{
    patientId = pID;
    name = pName;
    admissionDate = pData;
    diseaseDiagnosis = pDiagnosis;
    status = pStatus;
}

string PatientData::getPatientId()
{
    return patientId;
}
string PatientData::getName()
{
    return name;
}
string PatientData::getAdmissionDate()
{
    return admissionDate;
}
string PatientData::getDiseaseDiagnosis()
{
    return diseaseDiagnosis;
}
string PatientData::getStatus()
{
    return status;
}
void PatientData::print()
{
    cout << "Patient ID: " << patientId << endl;
    cout << "Name: " << name << endl;
    cout << "Admission Date: " << admissionDate << endl;
    cout << "Disease Diagnosis: " << diseaseDiagnosis << endl;
    cout << "Status: " << status << endl;
}

TNode::TNode()
{
    left = NULL;
    right = NULL;
}

TNode* leftRotate(TNode* node)
{
    TNode *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}
TNode* rightRotate(TNode *node)
{
    TNode *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

Hospital::Hospital()
{
    root = NULL;
    size = 0;
}

TNode *Hospital::insertPatient(TNode *node, PatientData data)
{
    if (node == NULL)
    {
        TNode *newNode = new TNode();
        newNode->data = data;
        return newNode;
    }
    if (data.getPatientId() < node->data.getPatientId())
    {
        node->left = insertPatient(node->left, data);
    }
    else if (data.getPatientId() > node->data.getPatientId())
    {
        node->right = insertPatient(node->right, data);
    }
    return node;
}

TNode *Hospital::search(TNode *node, string pID)
{
    TNode* temp;
    if (node == NULL)
    {
        return NULL;
    }
    if (pID < node->data.getPatientId())
    {
        TNode* newTemp = new TNode();
        node->left = search(node->left, pID);
        if (node->left != NULL && node->left->data.getPatientId() < node->data.getPatientId())
        {
            node = rightRotate(node);
        }
    }
    else if (pID > node->data.getPatientId())
    {
        TNode tempNode = node;
        node->right = search(node->right, pID);
        if (node->right != NULL && node->right->data.getPatientId() > node->data.getPatientId())
        {
            node = leftRotate(node);
        }
    }
    return node;
}

TNode* Hospital::deletePatient(TNode *node, string pID){
    if(node == NULL){
        return NULL;
    }
    TNode* deleteNode = new TNode();
    if(pID < node->data.getPatientId()){
        node->left = deletePatient(node->left, pID);
    }
    else if(pID > node->data.getPatientId()){
        node->right = deletePatient(node->right, pID);
        TNode* temp = node->right;
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
            TNode* temp = node->left;
            node->right = deletePatient(node->right, temp->data.getPatientId());
        }
    }
    return node;
}
void Hospital::printInorder(TNode *curr){
    if(curr == NULL){
        return;
    }
    printInorder(curr->left);
    curr->data.print();
    printInorder(curr->right);
}


void Hospital::insert(PatientData data){
    root = insertPatient(root, data);
}
void Hospital::deletePatient(string patientID){
    root = deletePatient(root, patientID);
}
void Hospital::searchP(string patientID){
    TNode *temp = search(root, patientID);
    if(temp == NULL){
        cout << "Patient not found" << endl;
    }
    else{
        temp->data.print();
    }
}
void Hospital::print(){
    printInorder(root);
}


int main()
{
    PatientData patientDataTemp[10];
    bool isRunning = true;

    Hospital *data= new Hospital();

    while (isRunning){
        cout << "1. Insert Patient" << endl;
        cout << "2. Delete Patient" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Print Inorder" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        string pID, pName, pAdmissionDate, pDiagnosis, pStatus;
        PatientData patientData;
        string patientID2;
        string patientID3;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> pID;
            cout << "Enter Patient Name: ";
            cin >> pName;
            cout << "Enter Patient Admission Date: ";
            cin >> pAdmissionDate;
            cout << "Enter Patient Disease Diagnosis: ";
            cin >> pDiagnosis;
            cout << "Enter Patient Status: ";
            cin >> pStatus;
            patientData.addData(pID, pName, pAdmissionDate, pDiagnosis, pStatus);
            data->insert(patientData);
            break;
        case 2:
            cout << "Enter Patient ID: ";
            cin >> patientID2;
            data->deletePatient(patientID2);
            break;
        case 3:
            cout << "Enter Patient ID: ";
            cin >> patientID3;
            data->searchP(patientID3);
            break;
        case 4:
            data->print();
            break;
        case 5:
            isRunning = false;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}