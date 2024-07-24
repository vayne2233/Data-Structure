#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

int main()
{
   int n;

   list<int> mylist;

   cin >> n;

   while ( n-- )
   {
       int data;
       string input;
       cin >> input;
       if ( input[0] == 'I' )
       {
           cin >> data;

           if ( input[1] == 'H' )
               mylist.push_front(data);
           else if ( input[1] == 'T' )
               mylist.push_back(data);
       }
       else if ( input[0] == 'R' )
       {
           if ( mylist.empty() ) continue;

           else if ( input[1] == 'H' )
               mylist.pop_front();
           else if ( input[1] == 'T' )
               mylist.pop_back();
       }
       else if ( input[0] == 'S' )
       {
           cin >> data;
           if ( mylist.empty() )
           {
               cout << "E\n";
               continue;
           }

           bool find = false;
           for ( auto x : mylist ) 
           {
               if ( x == data )
               {
                   find = true;
                   break;
               }
           }
           cout << (find ? "Y" : "N") << "\n";
       }
       else if ( input[0] == 'O' )
       {
           if ( mylist.empty() )
           {
               cout << "E\n";
               continue;
           }
           for ( list<int>::iterator i = mylist.begin(); i != mylist.end(); ++i)
           {
               if (i == mylist.end() - 1)
                   cout << *i;
               else
                   cout << *i << " ";
           }
           cout << "\n";
       }
    }
}

