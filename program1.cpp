#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int N = 0;

struct  PERSON
{

        char  Name[20];
      	float Balance;
};


void Display(PERSON *P, int N) {

         for(int i = 0; i < N; i++)
         {


           cout << P[i].Name << " " << P[i].Balance << endl;

         }

}


void FindRichest(PERSON *P, int N)
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

void Deposit(string CustName, PERSON *P, int N)
{

  float depositAmount = 0;

  for(int j = 0; j < N; j++)
  {
    if ((strcmp(CustName.c_str(), P[j].Name)) == 0)
    {
      cout << CustName;
      cout << ", how much would you like to deposit? ";
    }
  cin >> depositAmount;
  P[j].Balance = P[j].Balance + depositAmount;
  cout << "Now your new balance is " << P[j].Balance;
  }

}


void NewCopy (string filename, PERSON *P, int N)
{

  ofstream output;
  output.open(filename);

  for (int i = 0; i < N; i++)
  {

    output << P[i].Name << P[i].Balance << endl;
  }

  output.close();

}


int main()
{

  ifstream inFile;
  inFile.open("data.txt");
  int N = 0;
  string line;

  while (getline (inFile, line))
  {
    N++;
  }
  cout << "Total number of records " << N << endl;
  inFile.close();


  inFile.open("data.txt");

  int i = 0;

  PERSON P[N];

  while(!inFile.eof())
  {
    string name, lname;
    float pay;
    inFile >> name >> lname;
    inFile >> pay;
    name = name + ' ' + lname;
    strcpy(P[i].Name, name.c_str());
    P[i].Balance = pay;
    inFile.ignore();
    i++;
  }
  inFile.close();


Display(P, N);
FindRichest(P, N);

string CustName;
cout << "Enter your full name to deposit money: ";
getline(cin, CustName);

Deposit(CustName, P, N);

NewCopy("data.txt", P, N);

system("read -p 'Press Enter to continue...' var");

return 0;
}
