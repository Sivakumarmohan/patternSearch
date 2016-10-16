/*
Boyer Moore Horspool alogrithm

*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef pair < char, int > tupple;
typedef map < char, int > table;
typedef pair < int, tupple > pairTable;


vector <int>  BMHalgosearch(string mytext, string pattern)
{
    int i;
    tupple letterVal;
    vector <int> foundIndex;
    table badMatchtable;
    cout << "Compare " << mytext << mytext.size() << " to " << pattern <<pattern.size() <<endl;
    for(i = 0; i < pattern.size(); i++)
    {   
         badMatchtable[pattern[i]] = (pattern.size() - i + 1); 
         cout << "char " << pattern[i] <<" value " << badMatchtable.find(pattern[i])->second<<endl;
    }
    int numMaxCompare = mytext.size() - pattern.size() + 1;
    i = 0;
    int j = pattern.size();
    int jump = pattern.size();

    while (i < numMaxCompare)
    {
        j = pattern.size();
        jump = pattern.size();

        table::iterator it;
        while(j > 0)
        {
            //Compare the right most character.
            if( mytext[i+j-1] != pattern[j-1]) //Scary 
            {
                cout << "Match failed for " << mytext[i+j-1] << " " << pattern[j-1]<< endl;
                it = badMatchtable.find(mytext[ i + pattern.size() -1]);
                if(it != badMatchtable.end()) // character Found in table
                {
                    jump = it->second;
                    cout << "Letter " << mytext[i + pattern.size() - 1] <<" Badmatch "<<jump<<endl;
                }
                cout << " jump "<< jump <<endl;
                break;
            }
            //If Match found when last element is compared.
            else if ( j==1 )
            {
                foundIndex.push_back(i);
                cout << "Match found at index "<< i <<endl;
                break;
            }
            j--;
        }
        //Corner case for when jump exceeds the limit of text to be searched.
        if( (jump > ( numMaxCompare - (i))))
        {
            i += (numMaxCompare -(i-1));
        }
        else
        {
            i += jump;
        }
    }
    return foundIndex;

}

int main()
{
    vector <int> mySearch;
    mySearch = BMHalgosearch("adefdffdfdfffdf", "fdf");

    if( !mySearch.empty())
        cout << "found entries" <<endl;

}
