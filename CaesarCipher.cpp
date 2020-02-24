#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string* plainText(string* input)
{
    //Loop until input
    do{
        //Print menu
        menu()
        cout << "Enter plain text: ";
        //Get input : use getline, to get spaces inbetween
        getline(cin,*input);
    } while (*input.empty());
    return input;
}

unsigned short int* getShift(unsigned short int* shift)
{
    //Technically the CaesarCipher could take a negative shift value
    //But this is unnecessary

    //Loop until shift
    string input;
    int temp = 0;
    do{
        //Print menu
        menu()
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

void menu()
{
    //Print menu
    cout << "\n\n" << endl;
    cout << "Caesar Cipher" << endl;
    cout << "=============" << endl;
}

string* caesarCipher(string* input)
{
    //For each character in input
    //Add shift to ascii value
    //WIP
    return input;
}

int main(int argc, char** argv) {
    //Variable declaration
    string* input = new string();
    string* output = new string();
    unsigned short int* shift = new int();
    *shift = 0;

    //INPUT
    //| - Get plain text
    getInput(input);
    //| - Get shift
    getShift(shift);

    cout << "INPUT: " << *input << endl;
    cout << "SHIFT: " << *shift << endl;
    //Calculate output
    *output = *input;
    caesarCipher(output);
    //Output


    //Trash cleanup
    delete input,shift;
    return 0;
}