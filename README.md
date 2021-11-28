# DSA_Assignment_03


Many times, it is noticed that not all the data is frequently used in a particular time frame.
For example, a hospital maintains the data of thousands of patients but only the records of
those patients that are currently admitted in the hospital are accessed more frequently. One
way to make our search operation efficient is to place the frequently accessed data item
near root node. We want to modify the implementation of binary search trees such that
recently accessed items are moved near to the root node (these items are highly likely to
be accessed again). This way we can increase the efficiency of search operation. A simple
way to move a particular data item to the root node is by rotating nodes on the search path
with its parent node.


<b>IMPLEMENTATION : </b>
Your task is to design a hospital management system that can fulfill the requirements
specified in the above section.

<b>IMPORTANT CLASSES</b>
You have to implement the following classes

Class PatientRecord
This class must have following data members
• patient id
• patient name
• admission date
• disease diagnosis
• status (admitted/discharged)

Class TNode
This class must have following members:
• PatientRecord
• leftchild
• right child

Class HospitalData
This class must implement the following data members and member functions:
Data Members:
• Pointer to root of tree
• Size (number of records in the tree)

Member function

Insert(): This function must take patientRecord as parameter and insert it in the tree
according to the method described in the above section.

Search(): This function takes a patientid pid to be searched and level number k as
parameters and returns the patientrecord if such patient exists. Otherwise it must give an
error of not found. Moreover, if found this function will move the patient record with pid
at level k.

Remove(): This function must take a patient id as parameter and removes the patient
record from the tree.

Edit(): This function must take a patient id pid as parameter and edit its record.

Split(): This function must split the entire tree into two trees in linear time (O(n)) as
described in the above section and returns the second tree.

Output(): This function takes patient id pid as parameter and output its record.
OutputAdmitted(): This function output all the records of patients whose status is
admitted.
