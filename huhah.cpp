// Shuvo singh partho -> DIU
// C++ function project
// phone book

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

//Prototypes of Functions used in the project
void menu();        //Function to display menu options and run project
void AddNumber();    //Function to add new record in a Binary File.
void DisplayRecords();  //Function to read data file & display on screen.
void SearchBySrNo();    //Function to search and display record by sr no.
void deleteRecord();    //Function to delete a specific record from file.
void modifyRecord();    //Function to modify a specific record in file.

//Declaration and Definition of Class
class PhoneBook{
    int srno;
    char name[25];
    char mobile[15];
    char email[30];
    char group[20];
    public:
    int getSrNo() {return srno;}
    void storeData()
    {
        cout<<"\n...............CREATE NEW PHONE RECORD...............\n";
        cout<<"Enter Serial Number : "; 
            cin >> srno; cin.ignore();
        cout<<"Enter Record Name   : "; 
            cin.getline(name,25);
        cout<<"Enter Mobile Number : "; 
            cin.getline(mobile,15);
        cout<<"Enter E-Mail I. D.  : "; 
            cin.getline(email,30);
        cout<<"Enter Record Group  : "; 
            cin.getline(group,20);
        cout<<endl;
    }
    void showData()
    {
        cout<<"\n...............PHONE BOOK RECORD...............\n";
        cout<<"Sr. No.    : "<<srno<<endl;
        cout<<"Name       : "<<name<<endl;
        cout<<"Mobile No. : "<<mobile<<endl;
        cout<<"Email ID   : "<<email<<endl;
        cout<<"Group      : "<<group<<endl;
    }
}b;

void AddNumber()
{
    ofstream fout;
    fout.open("PhonBook.dat",ios::out|ios::binary|ios::app);
    b.storeData();
    fout.write((char*)&b,sizeof(b));
    fout.close();
    cout<<"\nRecord Saved to File......\n";
}



void DisplayRecords()
{
    ifstream fin;
    fin.open("PhonBook.dat",ios::out|ios::binary|ios::app);
    while(fin.read((char*)&b,sizeof(b)))
    {
        b.showData();
    }
    fin.close();
    cout<<"\nReading of Data File Completed......\n";
}

void SearchBySrNo()
{
    ifstream fin;
    int n, flag=0;
    fin.open("PhonBook.dat",ios::out|ios::binary|ios::app);
    cout<<"Enter Serial Number of Record To Display: ";
    cin>>n;

    while(fin.read((char*)&b,sizeof(b)))
    {
        if(n==b.getSrNo())
        {
            b.showData();
            flag++;
            cout<<"\n\n.....Record Found and Displayed......\n";
        }
    }
    fin.close();
    if(flag==0)
        cout<<"\nThe Record of Serial Number "<<n<<" is not in file....\n";
    cout<<"\nReading of Data File Completed......\n";
}

void deleteRecord()
{
    ifstream fin;
    ofstream fout;
    int n, flag=0;
    fin.open("PhonBook.dat",ios::out|ios::binary|ios::app);
    fout.open("temp.dat",ios::out|ios::binary);
    cout<<"Enter Serial Number of Record To Delete : ";
    cin>>n;

    while(fin.read((char*)&b,sizeof(b)))
    {
        if(n==b.getSrNo())
        {
            cout<<"\nThe Following record is deleted....\n";
            b.showData();
            flag++;
        }
        else
        {
            fout.write((char*)&b,sizeof(b));
        }
    }
    fin.close();
    fout.close();
    if(flag==0)
        cout<<"\nThe Record of Serial Number "<<n<<" is not in file....\n";
    cout<<"\nReading of Data File Completed......\n";
    remove("PhonBook.dat");
    rename("temp.dat","PhonBook.dat");
}

void modifyRecord()
{
    fstream fio;
    int n, flag=0,pos;
    fio.open("PhonBook.dat",ios::out|ios::binary|ios::in);

    cout<<"Enter Serial Number of Record To Modify : ";
    cin>>n;

    while(fio.read((char*)&b,sizeof(b)))
    {
        pos=fio.tellg();
        if(n==b.getSrNo())
        {
            cout<<"\nThe Following record will be modified....\n";
            b.showData();
            flag++;
            cout<<"\nRe-Enter the New Details.....\n";
            b.storeData();
            fio.seekg(pos-sizeof(b));
            fio.write((char*)&b,sizeof(b));
            cout<<"\n....Data Modified Successfully....\n";
        }
    }
    fio.close();
    if(flag==0)
        cout<<"\nThe Record of Serial Number "<<n<<" is not in file....\n";
    cout<<"\nReading of Data File Completed......\n";
}

void menu ()
{
    int ch;
    do
    {
        void clrscr();
        cout<<"............................................\n";
        cout<<"           PHONE BOOK MANAGEMENT\n";
        cout<<"............................................\n\n";
        cout<<"::::::::::::::: PROGRAM MENU :::::::::::::::\n";
        cout<<"0. Exit\n";
        cout<<"1. Save New Phone Record\n";
        cout<<"2. Display All Saved Records\n";
        cout<<"3. Search Specific Record\n";
        cout<<"4. Delete Specific Record\n";
        cout<<"5. Modify Existing Record\n";
        cout<<"Enter Your Choice : ";
        cin>>ch;
    void clrscr();
        switch(ch)
        {
            case 1: AddNumber(); break;
            case 2: DisplayRecords(); break;
            case 3: SearchBySrNo(); break;
            case 4: deleteRecord(); break;
            case 5: modifyRecord(); break;
        }
        getch();
    }
    while(ch);
}

int main()
{
    menu();
    getch();
}