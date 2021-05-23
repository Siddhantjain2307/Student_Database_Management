// Student Management System using file handling in c++

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

class student
{
private:
   string name, roll_no, course, address, email_id, contact_no;

public:
   void menu();
   void insert();
   void display();
   void modify();
   void search();
   void deleted();
};

void student::menu()
{
menustart:
   int choice;
   char x;
   system("cls");

   cout << "\t\t\t***************************** " << endl;
   cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM | " << endl;
   cout << "\t\t\t***************************** " << endl;
   cout << "\t\t\t 1. Enter New Record" << endl;
   cout << "\t\t\t 2. Display Record" << endl;
   cout << "\t\t\t 3. Modify Record" << endl;
   cout << "\t\t\t 4. Search Record" << endl;
   cout << "\t\t\t 5. Delete Record" << endl;
   cout << "\t\t\t 6. Exit" << endl;

   cout << "\t\t\t**************************** " << endl;
   cout << "\t\t\tChoose Option: [1/2/3/4/5/6] " << endl;
   cout << "\t\t\t**************************** " << endl;
   cout << "Enter Your Choose:";
   cin >> choice;

   switch (choice)
   {
   case 1:
      do
      {
         insert();
         cout << "\n\t\t\t Add Another Stuent Record (Y,N): ";
         cin >> x;
      } while (x == 'y' || x == 'Y');
      break;
   case 2:
     display();
     break;
   case 3:
      modify();
      break;
   case 4:
      search();
      break;
   case 5:
      deleted();
      break;           
   case 6:
      cout<<"\n\t\t\t Program Is Terminated !!! ";
      exit(0);
   default:
      cout << "\n\t\t\t Invalid Choice..... Please Try Again....";
   }
   getchar();
   goto menustart;
}

void student::insert()
{
   system("cls");
   fstream file;
   cout << "\t\t\t**************************************************** " << endl;
   cout << "\t\t\t***************** Add Student Details*************** " << endl;
   cout << "\t\t\t**************************************************** " << endl;
   cout << "\t\t\tEnter Name: ";
   cin >> name;
   cout << "\t\t\tEnter Roll No.: ";
   cin >> roll_no;
   cout << "\t\t\tEnter Course: ";
   cin >> course;
   cout << "\t\t\tEnter Email Id: ";
   cin >> email_id;
   cout << "\t\t\tEnter Contact No.: ";
   cin >> contact_no;
   cout << "\t\t\tEnter Address: ";
   cin >> address;
   file.open("studentRecord.txt", ios::app | ios::out);
   file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
   file.close();
}

void student::display()
{
   system("cls");
   fstream file;
   int total=1;
   cout << "\t\t\t**************************************************** " << endl;
   cout << "\t\t\t*****************Student Record Table*************** " << endl;
   cout << "\t\t\t**************************************************** " << endl;
   file.open("studentRecord.txt",ios::in);
   if(!file)
   {
      cout<<"\n\t\t\t No Data Is Present....!!!";
      file.close();
   }
   else
   {
   file>>name>>roll_no>>course>>email_id>>contact_no>>address;
      
   while (!file.eof())
   {
      cout<<"\n\t\t\t Student No. :"<<total++<<endl;
      cout<<"\n\t\t\t Name: "<<name<<"\n";
      cout<<"\n\t\t\t Roll No. :"<<roll_no<<"\n";
      cout<<"\n\t\t\t Course :"<<course<<"\n";
      cout<<"\n\t\t\t Email ID :"<<email_id<<"\n";
      cout<<"\n\t\t\t Contact No. :"<<contact_no<<"\n";
      cout<<"\n\t\t\t Address :"<<address<<"\n";
      file>>name>>roll_no>>course>>email_id>>contact_no>>address;

   }
   if(total==0)
   {
      cout<<"\n\t\t\t No Data Is Present....!!!"<<endl;
   }
   }
   getchar();
   file.close();
}
void student::modify()
{
   system("cls");
   fstream file,file1;
   string rollno;
   int found=0;
   cout << "\t\t\t****************************************************** " << endl;
   cout << "\t\t\t*****************Student Modify Details*************** " << endl;
   cout << "\t\t\t****************************************************** " << endl;
   file.open("studentRecord.txt",ios::in);
   if(!file)
   {
      cout<<"\n\t\t\t No Data Is Present....!!!";
      file.close();
   }
   else
   {
      cout<<"\n Enter Roll NO. of Student which you want to Modify: ";
      cin>>rollno;
      file1.open("record.txt",ios::app | ios::out);
      file>>name>>roll_no>>course>>email_id>>contact_no>>address;
      while(!file.eof())
      {
         if(rollno!=roll_no)
           file1<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<" "<<address<<"\n";
         else
         {
            cout<<"\n\t\t\t Enter Name: ";
            cin>>name;
            cout<<"\n\t\t\t Enter Roll No. : ";
            cin>>roll_no;
            cout<<"\n\t\t\t Enter Course: ";
            cin>>course;
            cout<<"\n\t\t\t Enter Email ID : ";
            cin>>email_id;
            cout<<"\n\t\t\t Enter Contact No. : ";
            cin>>contact_no;
            cout<<"\n\t\t\t Enter Address : ";
            cin>>address;
            file1<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<" "<<address<<"\n";
            found++;
         }
         file>>name>>roll_no>>course>>email_id>>contact_no>>address;
         if(found==0)
         {
            cout<<"\n\t\t\t Student Roll No. Not Found......!!!";
         }  
      }
      getchar();
      file1.close();
      file.close();
      remove("studentRecord.txt");
      rename("record.txt","studentRecord.txt");
   }
}
void student::search()
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter Roll No. of Student which you want to search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\n\t Name: " << name << "\n";
                cout << "\t\t\t Roll No.: " << roll_no << "\n";
                cout << "\t\t\t Course: " << course << "\n";
                cout << "\t\t\t Email Id: " << email_id << "\n";
                cout << "\t\t\t Contact No.: " << contact_no << "\n";
                cout << "\t\t\t Address: " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\t\t\t Student Roll NO. Not Found....";
            }
        }
        getchar();
        file.close();
    }
}
void student::deleted() 
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        getchar();
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
main()
{
   student project;
   project.menu();
   return 0;
}