#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void menu()
{
    //Print menu
    cout << "Caesar Cipher" << endl;
    cout << "=============" << endl;
}

string* getInput()
{
    string* input = new string();
    //Loop until input
    do{
        //Print menu
        menu();
        cout << "Enter plain text: ";
        //Get input : use getline, to get spaces inbetween
        getline(cin,*input);
    } while (input->empty());
    return input;
}

unsigned short int* getShift()
{
    //Technically the CaesarCipher could take a negative shift value
    //But this is unnecessary

    //Loop until shift
    string input;
    int temp = 0;
    unsigned short int* shift = new unsigned short int();
    do{
        //Print menu
        menu();
        cout << "Enter shift (x > 0 and x % 26 != 0): ";
        //Get input : use getline, to get spaces inbetween
        cin >> input;
        try
        {
            /*temp %= 26
            * this allows a bypass on checking if value entered is greater than short boundaries
            * and allows the system to continue operating without throwing an exception
            */
            temp = stoi(input);
            *shift = temp % 26;
        } 
        catch(invalid_argument const &e)
        {
            cout << "Bad input: std::invalid_arugment thrown" << endl;
        }
        catch(out_of_range const &e)
        {
            cout << "Integer overflow: std::out_of_range thrown" << endl;
        }
    } while (*shift < 1);
    return shift;
}

string* caesarCipher(string* input,const unsigned short int* shift)
{
    string* output = new string();
    //For each character in input
    for(char& c: *input)
    {
        if (c != '\0')
        {
            if (c >= 'a' && c <= 'z')
            {
                c += *shift;
                if (c > 'z'){ c += 'a' - 'z' - 1; }
            }
            else if (c >= 'A' && c <= 'Z')
            {
                c += *shift;
                if (c > 'Z'){ c += 'A' - 'Z' - 1; }
            }
        }
        *output += c;
    }
    return output;
}

int main(int argc, char** argv) {
    //Variable declaration
    string* input;
    string* output = new string();
    unsigned short int* shift;

    //INPUT
    //| - Get plain text
    input = getInput();
    //| - Get shift
    shift = getShift();

    cout << "INPUT: " << *input << endl;
    cout << "SHIFT: " << *shift << endl;
    //Calculate output
    output = caesarCipher(input, shift);
    //Output
    cout << "OUTPUT: " << *output << endl;


    //Trash cleanup
    delete input,shift,output;
    return 0;
}