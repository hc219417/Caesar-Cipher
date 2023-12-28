/**
 * @file: caesar cypher
 * @author: Hannah Culver
 * @date: October 12, 2021
 * @brief: lab 8 (security and encryption)
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

/**
 * displayMenu
 * @param none
 * @return menu with four choices
 */
void displayMenu ();

/**
 * setKey
 * @param none
 * @return valid shift key value (between 1 and 10)
 */
int setKey ();

/**
 * encrypt a file
 * @param key shift key value
 * @return encrypted output file
 */
void encrypt (int key);

/**
 * decrypt a file
 * @param key shift key value
 * @return decrypted outout file
 */
void decrypt (int key);

int main(int argc, char const *argv[]) {

    int choice;
    int key;
    
    key = 3; //default

    do {
    displayMenu();
    cin >> choice;
    if (choice == 1) {
        key = setKey ();
    }
    else if (choice == 2) {
        encrypt (key); //call the encryption function
    }
    else if (choice == 3) {
        decrypt (key); //call the decryption function
    }
    } while (choice != 4);
    return 0;
} ///main

void displayMenu ()
{
    cout << "1. Set the shift key value (default is 3)" << endl;
    cout << "2. Encrypt a file" << endl;
    cout << "3. Decrypt a file" << endl;
    cout << "4. Quit" << endl;
    cout << "Please enter your choice: ";
}

int setKey ()
{
    int value;
    do {
        cout << "Please enter a shift key value between 1 and 10: ";
        cin >> value;
    } while (value < 1 || value > 10);
 return value;
}

void encrypt (int key)
{
    ifstream inStream; //create the stream object
    string input_filename; //input file

    cout << "Please enter the input file name: "; //prompt for user input
    cin >> input_filename;
 
    inStream.open(input_filename); //connect to a text file and open
    if (inStream.fail()) //check for failure
    { 
        cout << "Error: file not found" << endl;
        exit(0);
    }

    ofstream outStream; //create the stream object
    string output_filename; //output file

    cout << "Please enter the output file name: "; //prompt for user input
    cin >> output_filename;
 
    outStream.open(output_filename); //connect to a text file and open
    if (outStream.fail()) //check for failure
    {
        cout << "Error: failed to create file" << endl;
        exit(0);
    }

    char ch;
    inStream.get(ch); //read each character (including white spaces)
    while (!inStream.eof()) //end of file
    {
        outStream << (ch + key); //add the shift key value
        inStream.get(ch);
    }
    inStream.close();   //don't forget to
    outStream.close();  //close both files
}

void decrypt (int key)
{
    ifstream inStream; //create the stream object
    string input_filename; //input file

    cout << "Please enter the input file name: "; //prompt for user input
    cin >> input_filename;
 
    inStream.open(input_filename); //connect to a text file and open
    if (inStream.fail()) //check for failure
    { 
        cout << "Error: file not found" << endl;
        exit(0);
    }

    ofstream outStream; //create the stream object
    string output_filename; //output file

    cout << "Please enter the output file name: "; //prompt for user input
    cin >> output_filename;
 
    outStream.open(output_filename); //connect to a text file and open
    if (outStream.fail()) //check for failure
    {
        cout << "Error: failed to create file" << endl;
        exit(0);
    }

    char ch;
    inStream.get(ch); //read each character (including white spaces)
    while (!inStream.eof()) //end of file
    {
        outStream << (ch - key); //subtract the shift key value
        inStream.get(ch);
    }
    inStream.close();   //don't forget to
    outStream.close();  //close both files
}