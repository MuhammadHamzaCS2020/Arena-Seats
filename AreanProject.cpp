# Arena-Seats
This project for any Arena Company for selling Tickets in C++.
// For this program you need a text file and store the every row price in it. price must be four digits.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
const int Num_Rows=15;
const int Num_col=30;

void Seats_Information(char Array[][Num_col]){
int Seats_Available=450,Seats_Fill=0,Left_Each_Row=0;
     for(int i=0; i<Num_Rows; i++){
           Left_Each_Row=0;
        for(int j=0; j<Num_col; j++){
            if(Array[i][j]=='*'){
                Left_Each_Row++;
                Seats_Fill++;
            }
        }
       cout<<"Row No "<<i+1<<" "<<Left_Each_Row<<" Seats are Fill out of 30.\n";
     }
   Seats_Available=Seats_Available-Seats_Fill;
   cout<<"There are "<<Seats_Available<<" seats available in Auditorium.\n";
   cout<<"There are "<<Seats_Fill<<" seats Fill in Auditorium.\n\n";
}




  void Initialize_Seats(char Array[][Num_col]){
     for(int i=0; i<Num_Rows; i++){
        for(int j=0; j<Num_col; j++){
            Array[i][j]='#';
        }
     }
 }
  void Display_Seats(char Array[][Num_col]){
      cout<<endl;
    for(int i=0; i<Num_Rows; i++){
            cout<<"Row No "<<i+1<<" : ";
        for(int j=0; j<Num_col; j++){
                if(Array[i][j]=='*'){
                    cout<<setprecision(1)<<Array[i][j];
                }
                else
                    cout<<setprecision(1)<<Array[i][j];
        }
        cout<<endl;
     }
     cout<<endl;
  }
  void Show_Price(int price[]){
        for(int i=0; i<Num_Rows; i++){
            cout<<"Price of "<<i+1<<" Row "<<*(price+i)<<endl;
     }
  }
   void Show_Manue(){
           cout<<"\t\t Please Choice from the the below Menu ....\n";
       cout<<"\t S or s : If you Sold a Ticket.....\n";
       cout<<"\t M or m : If you See the Total Collect Money...\n";
       cout<<"\t I or i : If you See the Seats Information in the Auditorium..\n";
       cout<<"\t T or t : If you See the Total Today Collection..\n";
       cout<<"\t P or p : If you See the Today Seats Prices..\n\n";
   }

   double Buy_Ticket(char S_Array[][Num_col],int P_Array[]){
      int row,col;
      int Total=0;
      cout<<"\nEnter the Row Number : ";
      cin>>row;
         while(row<0 || row>15){
            cout<<"\n please reenter the Row Number : ";
            cin>>row;
         }
      cout<<"\nEnter the Seat Number : ";
      cin>>col;
         while(col<0 || col>30){
            cout<<"\n please reenter the Seat Number : ";
            cin>>col;
         }
      S_Array[row-1][col-1]='*';
      Total=Total+*(P_Array+row);
      return Total;
   }

   void Collection(int T_Collection){
       cout<<"\nThe Total Earning This Time is  :  "<<T_Collection<<endl;
   }


   // Main
int main()
{
    int Price_array[Num_Rows];
    char Seats_Array[Num_Rows][Num_col];
    int Total_Collection=0;

    ifstream Open_File("price.txt");
    Initialize_Seats(Seats_Array);
    // Input Price

    char Data;
    for(int i=0; i<Num_Rows; i++){
          int Get_Value=0,j=0;
      while(j<4){
         Open_File>>Data;
         Data=Data-48;
         Get_Value=Get_Value*10;
         Get_Value+=Data;
         j++;
      }
       Price_array[i]=Get_Value;
     }
          // Show_Price(Price_array);

   while(true){
      Display_Seats(Seats_Array);
      // User Options
      char Choice;
      Show_Manue();
       cout<<"Enter your Choice from the Menu : ";
       cin>>Choice;
         if(Choice=='M' || Choice=='m'){
            Collection(Total_Collection);
         }
         else if(Choice=='S' || Choice=='s'){
            Total_Collection+=Buy_Ticket(Seats_Array,Price_array);
         }
         else if (Choice=='P' || Choice=='p'){
            Show_Price(Price_array);
         }
         else if(Choice=='T' || Choice=='t'){
            Collection(Total_Collection);
         }
         else if(Choice=='I' || Choice=='i'){
            Seats_Information(Seats_Array);
         }
   }
    return 0;
}

