#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
#include<string>
#include<Windows.h>
#include<stdlib.h>

using namespace std;

void addData(void);
void viewData(void);
void mainMenu(void);
void deleteData(void);
void adminVerification(void);
void studentFunction(void);

void adminFunction(){
    system("cls");
    cout << "\n\n\t\t\t\t\t |Logged In As Admin | \n";
    cout << "\n\n\t\t\t\t\t 1.Add Students Detail";
    cout << "\n\n\t\t\t\t\t 2.Delete Students";
    cout << "\n\n\t\t\t\t\t 3.View Table";
    cout << "\n\n\t\t\t\t\t 4.Main Menu";
    cout << "\n\n\t\t\t\t 6.Exit";
    int option;
    cout << "\n\n\t\t\t\t\t Enter Choice :";
    do{
        cin >> option;
        {
            switch(option){
                case 1:
                    addData();
                    break;
                    case 2 :
                        deleteData();
                        break;
                        case 3 :
                            viewData();
                            break;
                            case 4:
                                mainMenu();
                                break;
                                case 5:
                                    system("cls");
                                    cout << "\t\t\n\n\n\n\n\n\n\t\t\t\tQuitting  The Program";
                                    for (int i = 0; i < 4;i++)
                                    {
                                         Sleep(1000);
                                         cout << ".";
                                    }
                                    exit(0);
                                    break;
                                    default:
                                        system("cls");
                                        cout << "\n\n\t\t\t\t\t Logged In as Admin";
                cout << "\n\n\t\t\t\t\t 1. Add Students Record";
                cout << "\n\n\t\t\t\t\t 2. Delete Record";
                
                cout << "\n\n\t\t\t\t\t 3. View Table ";
                cout << "\n\n\t\t\t\t\t 4. Main Menu ";
                cout << "\n\n\t\t\t\t\t 5. Exit";

                cout << "\n\n\t\t\t\t\t invalid input!";

                cout << "\n\n\t\t\t\t\t Enter choice : ";
           }
        }
        
            
    }while(option!='5')
            ;
}

void mainMenu(){
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t Login As : ";
    cout << "\n\n\n\t\t\t\t\t 1. Admin ";
    cout << "\n\n\t\t\t\t\t 2. Student";
    cout << "\n\n\t\t\t\t\t 3. Exit";
    cout << "\n\n\n\t\t\t\t\t Enter your choice : ";

    int choice;
    cin >> choice;
     switch(choice){
        case 1:
            adminVerification();
            break;
            case 2:
                system("cls");
                cout << "Welcome as a Student";
                studentFunction();
                break;
                case 3:
                    system("cls");
                    cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting the Program";
                    break;

                    for (int i = 0; i < 4;i++){
                        Sleep(1000);
                        cout << ".";

                    }
                    exit(0);
                    break;

                    default:
                        cout << "Invalid Input";
                        system("pause");
     }

}

// Admin functions below

void deleteData(){
    system("cls");
    //  OPen the file pointers

    fstream fin, fout;

    // Open the existing  file;
    fin.open("data.csv", ios :: in);
    // Create a new file to store the non deleted data
    fout.open("dataNew.csv", ios :: out);
    int rollno, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;
    // Get the roll number
    cout << "Enter the roll number to be deleted";
    cin >> rollno;
    // Check if this record exits , If exists add all the other data to the other file
    while(!fin.eof()){
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while(getline(s,word,',')){
            row.push_back(word);

        }
        int row_size = row.size();
        roll1 = stoi(row[0]);
        // writing all records,
        // except the record to be deleted,
        // into the new file 'reportcardnew.csv'
        // using fout pointer
        if(roll1!=rollno){
            if(!fin.eof()){
                for (i = 0; i < row_size - 1;i++){
                    fout << row[i] << ",";

                }
                fout << row[row_size - 1] << "\n";

            }
        }else{
            count = 1;

        }
        if(fin.eof()){
            break;
        }
        if(count==1){
            cout << "Record Deleted\n";
        }else{
            cout << "Record Not FOund\n";
        }

        // Close the pointers
        fin.close();
        fout.close();
        // remove the existing files
        remove("data.csv");
        // rename the new file with the existing file
        rename("datanew.csv", "data.csv");
        Sleep(2000);
        adminFunction(); 
    }
}

void addData(){
    system("cls");
    fstream file("data.csv", ios::out | ios::app);
    if(!file){
        cout << "\nFailed to open data.csv/data.csv not found";
    }else{
        cout << "\t|Enter Data" << endl;
        string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
        // Decalare another string variable to store the users response on whhether they want to add more records
        string moreData;
        cout << "\nEnter Students Roll Number : ";
        cin >> rollNumber;
        file << "\n"
             << rollNumber << ",";

        cout << "\nEnter Student's Name:";
        cin >> name;
        file << name << ",";

        cout << "\nEnter College :";
        cin >> college;
        file << college << ",";

        cout << "\nEnter Branch :";
        cin >> branch;
        file<<branch<<",";

        cout << "\nEnter attendance : ";
        cin >> attendance;
        file << attendance << ",";

        cout << "\nEnter Physics marks :";
        cin >> physics;
        file << physics << ",";

        cout << "\nEnter chemistry marks : ";
        cin >> chemistry;
        file << chemistry << ",";

        cout << "\nEnter maths marks : ";
        cin >> maths;
        file << maths << ",";

        file.close();

        // Ask the user if they want to enter more record

        cout << "\n Do you want to enter more record ? (Y /N ): ";
        cin >> moreData;
        if(moreData=="Y"||moreData=="y"||moreData=="yes"||moreData=="Yes"){
            addData();
        }
        else if(moreData=="n"||moreData=="N"||moreData=="no"||moreData=="No"){
            adminFunction();
        }else{
            cout << "\n Enter a valid option";
        }

        

        
    }
    adminFunction();
}

void viewData(){
    system("cls");
    fstream file("data.csv");
    if(!file){
        cout << "Fail to open the file";
    }
        cout << "\n\t\t\t\t\t\t|Students Record| \n\n";

    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl
         << endl;
    cout << "Roll \t Name \t\t\t College \t branch \t Attendance \t Physics \t Chemistry \t Maths" << endl
         << endl;
    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
    // Read and Display Data from the file
    while(!file.eof()){
        getline(file, rollNumber, ',');
        getline(file, name, ',');
        getline(file, college, ',');
        getline(file, branch, ',');
        getline(file, attendance, ',');
        getline(file, physics , ',');
        getline(file, chemistry, ',');
        getline(file, maths, '\n');

        cout << rollNumber << " \t " << name << "\t\t\t" << college << " \t\t" << branch << " \t\t" << attendance << " \t\t" << physics << " \t\t" << chemistry << " \t\t" << maths << endl;
        cout << endl;
        cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
        file.close();
        // Display options Further Actions
        cout << "\n\n 1. Add Record \n";
        cout << "\n\n 2. Delete Record \n";
        cout << "\n\n 4.Main Menu \n";

        cout << "\n\n 5. Exit\n";
        cout << "\n Enter Choice";

    }


}

// adminVerification

void adminVerification(){
    system("cls");
    string password;
    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tEnter Password : ";
    do{
        cin >> password;
        if(password!="password")
            ;
            {
                system("cls");
                cout << "\n\n\n\n\n\t\t"
                 << "wrong password!, try again or type 'menu' to Navigate to Main Menu";
            cout << "\n\n\n\t\t\t\t\tEnter Password : ";
            }
            if(password=="Menu"||password=="menu"||password=="MENU"){
                mainMenu();
            }
    } while (password != "password");
    adminFunction();
}

// Student Function

void studentFunction(){
    system("cls");
    fstream file("data.csv");

    if(!file){
        cout << "Fail in opening file";
    }
    // Print the header information
        cout << "\n\t\t\t\t\t\t|Students Record| \n\n";

    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl
         << endl;
    cout << "Roll \t Name \t\t\t College \t branch \t Attendance \t Physics \t Chemistry \t Maths" << endl
         << endl;
    // Read and print File Contents;
        string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

    while (!file.eof()) // file.eof() = detects as how long the file is
    {
        getline(file, rollNumber, ',');
        getline(file, name, ',');
        getline(file, college, ',');
        getline(file, branch, ',');
        getline(file, attendance, ',');
        getline(file, physics, ',');
        getline(file, chemistry, ',');
        getline(file, maths, '\n');

        cout << rollNumber << " \t " << name << "\t\t\t" << college << " \t\t" << branch << " \t\t" << attendance << " \t\t" << physics << " \t\t" << chemistry << " \t\t" << maths << endl;
        cout << endl;
    }
    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
    file.close();
    system("pause");
    mainMenu();
}




