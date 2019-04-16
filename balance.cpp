#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int N = 0;

struct  PERSON
{

        char  Name[20];
      	float Balance;
};

PERSON * readData(int & N) {

  ifstream inFile;
  inFile.open("data.txt");
  int N = 0;
  string line;

  while (getline (inFile, line)
  {
    N++;
  }
  cout << "Total number of records " << N << endl;
  inFile.close();


  inFile.open("data.txt");

  int i = 0;

  personArray = new PERSON[N];

  while(!inFile.eof())
  {
    string name, lname;
    float pay;
    inFile >> name >> lname;
    inFile >> pay;
    name = name + " " + lname;
    strcpy(P[i].Name, name.c_str());
    P[i].Balance = pay;
    inFile.ignore();
    i++;
  }
  inFile.close();


}

void printMenu() {
    cout << "Please enter a choice:: " << endl;
    cout << "1. Display records" << endl;
    cout << "2. Deposit funds" << endl;
    cout << "3. Find highest balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit" << endl;
}


void Display(PERSON P[], int N) {

         for(int i = 0; i < N; i++)
         {


           cout << P[i].Name << ' ' << P[i].Balance << endl;

         }

}


void FindRichest(PERSON P[], int N)
{


    int cursor = 0;

    for (int i = 0; i < N; i++)
    {
        if (P[cursor].Balance < P[i].Balance)
        {
            cursor = i;
        }

    }
    cout <<  endl;
    cout << "The customer with maximum balance is " << P[cursor].Name << endl;

}

void Deposit(PERSON P[], int N, string CustName)
{

  float depositAmount = 0;

  for(int j = 0; j < N; j++)
  {
    if ((strcmp(CustName.c_str(), P[j].Name)) == 0)
    {
      cout << CustName;
      cout << ", how much would you like to deposit? ";
      cin >> depositAmount;
      P[j].Balance = P[j].Balance + depositAmount;
      cout << "Now your new balance is " << P[j].Balance;
    }
  }

}


void NewCopy (string filename, PERSON P[], int N)
{

  ofstream output;
  output.open(filename);

  for (int i = 0; i < N; i++)
  {

    output << P[i].Name << " " << P[i].Balance << endl;

  }

  output.close();

}


int main()
{
  PERSON* ptr = NULL;
  int size = 0;
  int choice;
  int depositAmount;
  sring name;
  ptr = readData(size);

  do
  {
    printMenu();
    cin >> choice;

    switch(choice)
    {
      case 1:
        Display(ptr, size);
        break;

      case 2:
        Deposit(ptr, size, name);
        break;

      case 3:
        FindRichest(ptr, size);
        break;

      case 4:
        NewCopy("file", ptr, size);
        break;

      case 5:
        cout << "Exit" << endl;
        return 0;
        break;

      default:
        cout << "invalid choice, enter from 1 - 4:: " << endl;
        break;
    }
  } while (choice != 5);
//system("read -p 'Press Enter to continue...' var");

return 0;

}
