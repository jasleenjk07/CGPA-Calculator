#include<iostream>
using namespace std;

void cgpaCalculator(int totalSubjects, int gradePoints[]){
    //To calculate sum for CGPA
    int sum = 0;
    for (int i = 0; i < totalSubjects; i++)
    {
        sum = sum + gradePoints[i];
    }
  
    //To calculate CGPA
    int cgpa;
    cgpa = sum/totalSubjects;
    cout << "CGPA: "<< cgpa << "\n";

    //To calculate Percentage
    int per;
    per = cgpa*9.5;
    cout << "Percentage: "<<per;
}

void output(int totalSubjects,string subjects[], float marks[], int totalMarks[], float percentage[], int gradePoints[], string grade[]){
    // Print the array elements 
    cout << "Subjects are: " << "\n"; 
    for (int i = 0; i < totalSubjects; i++) { 
        cout << "Subject Name: " << subjects[i] << "\n"; 
        cout << "Marks Obtained: " << marks[i] << "\n"; 
        cout << "Total Marks: " << totalMarks[i] << "\n"; 
        cout << "Percentage: " << percentage[i] << "\n";
        cout << "Grade: " << grade[i] << "\n";
        cout << "Grade Point: " << (int) gradePoints[i] << "\n";
        cout << "::" << "\n";
    } 
}

void gradepoint(int totalSubjects, float percentage[], string grade[], int gradePoints[]){
    //To calculate GradePoint
    for (int i = 0; i < totalSubjects; i++)
    {
        switch ((int) percentage[i]) {
            case 91 ... 100 :
                gradePoints[i] = 10;
                grade[i] = "A1";
                break;
            case 81 ... 90 :
                gradePoints[i] = 9;
                grade[i] = "A2";
                break;
            case 71 ... 80 :
                gradePoints[i] = 8;
                grade[i] = "B1";
                break;
            case 61 ... 70 :
                gradePoints[i] = 7;
                grade[i] = "B2";
                break;
            case 51 ... 60 :
                gradePoints[i] = 6;
                grade[i] = "C1";
                break;
            case 41 ... 50 :
                gradePoints[i] = 5;
                grade[i] = "C2";
                break;
            case 33 ... 40 :
                gradePoints[i] = 4;
                grade[i] = "D";
                break;
            case 21 ... 32 :
                gradePoints[i] = 0;
                grade[i] = "E1";
                break;
            case 00 ... 20 :
                gradePoints[i] = 0;
                grade[i] = "E2";
                break;
            default:
                cout << "Defaut Value" << "\n";
                break;
        }
    }
}

void percentageCalc(int totalSubjects, float marks[], int totalMarks[], float percentage[]) {
    //To calculate subject percentage
    float subPercentage;
    for (int i = 0; i < totalSubjects; i++)
    {
        subPercentage = (marks[i]/totalMarks[i])*100;
        percentage[i] = subPercentage;
    }
}

void input(int totalSubjects, string subjects[], float marks[], int totalMarks[]) {
    // using loop to move to every array element and then 
    // using either cin to insert the value given by the 
    // user to the array element 
    for (int i = 0; i < totalSubjects; i++) { 
        cout << "Enter subject name: "; 
        cin >> subjects[i]; 
        cout << "Enter marks scored: "; 
        cin >> marks[i]; 
        cout << "Enter maximum marks: "; 
        cin >> totalMarks[i]; 
    }
}

int main() { 
    // defining array size 
    int totalSubjects; 
    cout<<"Total Number of Subjects: ";
    cin>>totalSubjects;

    if (totalSubjects < 2) {
        cout<<"Exited From Program";
        return 0;
    }

    // defining array of totalSubjects "totalSubjects" 
    string subjects[totalSubjects]; 
    float marks[totalSubjects]; 
    int totalMarks[totalSubjects]; 
    float percentage[totalSubjects];
    int gradePoints[totalSubjects];
    string grade[totalSubjects];

    input(totalSubjects, subjects, marks, totalMarks);

    percentageCalc(totalSubjects, marks, totalMarks, percentage);

    gradepoint(totalSubjects, percentage, grade, gradePoints);

    output(totalSubjects,subjects,marks,totalMarks,percentage,gradePoints,grade);
    
    cgpaCalculator(totalSubjects, gradePoints);

    return 0; 
}

