#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Student 
{
    int roll;
    char name[50];
    float marks;
};
void addStudent() 
{
    Student s;
    ofstream file("students.txt",ios::app);
    cout<<"\nEnter Roll Number: ";
    cin>>s.roll;
    cout<<"Enter Name: ";
    cin>>s.name;
    cout<<"Enter Marks: ";
    cin>>s.marks;
    file<<s.roll<<" "<<s.name<<" "<<s.marks<<endl;
    file.close();
    cout<<"Student Added Successfully!\n";
}
void displayStudents() 
{
    Student s;
    ifstream file("students.txt");
    cout<<"\n--- Student Records ---\n";
    while(file>>s.roll>>s.name>>s.marks){
        cout<<"Roll: "<<s.roll<<"| Name: "<<s.name<<"| Marks: "<<s.marks<<endl;
    }
    file.close();
}
void searchStudent() {
    int roll;
    bool found = false;
    Student s;
    cout<<"\nEnter Roll Number to search: ";
    cin>>roll;
    ifstream file("students.txt");
    while(file>>s.roll>>s.name>>s.marks) 
    {
        if(s.roll==roll) 
        {
            cout<<"Found: "<<s.roll<<" "<<s.name<<" "<<s.marks<<endl;
            found=true;
            break;
        }
    }
    file.close();

    if(!found)
        cout<<"Student not found!!!!!!!!!!!!!!\n";
}
void updateStudent() 
{
    int roll;
    bool found=false;
    Student s;
    cout<<"\nEnter Roll Number to update: ";
    cin>>roll;
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    while(file>>s.roll>>s.name>>s.marks) 
    {
        if (s.roll==roll) 
        {
            cout<<"Enter New Name: ";
            cin>>s.name;
            cout<<"Enter New Marks: ";
            cin>>s.marks;
            found=true;
        }
        temp<<s.roll<<" "<<s.name<<" "<<s.marks<<endl;
    }
    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if(found)
        cout<<"Student Updated!\n";
    else
        cout<<"Student not found!!!!\n";
}
void deleteStudent() 
{
    int roll;
    bool found = false;
    Student s;
    cout<<"\nEnter Roll Number to delete: ";
    cin>>roll;
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    while(file>>s.roll>>s.name>>s.marks) {
        if (s.roll!=roll) 
        {
            temp<<s.roll<<" "<<s.name<<" "<<s.marks<<endl;
        } 
    else 
        {
            found=true;
        }
    }
    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if(found)
        cout<<"Student Deleted!!!!\n";
    else
        cout<<"Student not found!!!\n";
}
int main() 
{
int choice;
    do 
    {
        cout<<"\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout<<"1. Add Student\n";
        cout<<"2. Display Students\n";
        cout<<"3. Search Student\n";
        cout<<"4. Update Student\n";
        cout<<"5. Delete Student\n";
        cout<<"6. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
    switch (choice) {
            case 1:addStudent(); 
            break;
            case 2:displayStudents(); 
            break;
            case 3:searchStudent(); 
            break;
            case 4:updateStudent(); 
            break;
            case 5:deleteStudent(); 
            break;
            case 6:cout<<"Exiting.....\n";break;
            default:cout<<"Invalid choice!!!!\n";
        }

    }while(choice!=6);
return 0;
}