// lesson 5
// Nathan Vallad

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

int main()
{
   // the Arrays
   string abcArray[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
   string abcShiftedArray[26];

   // prints the Array
   for (int letterPosition = 0; letterPosition < 26; ++letterPosition)
   {
      cout << abcArray[letterPosition] << " ";
   }// for end
   cout << endl;

   // The shift value
   int shiftValue;
   cout << "Enter an offset for this encryption between -26 and 26: ";
   cin >> shiftValue;
   cout << endl;

   // make sure the number is valid
   while (shiftValue < -26 || shiftValue > 26)
   {
      cout << shiftValue << " is not a valid number. Please enter a number between -26 and 26: " << endl;
      cin >> shiftValue;
   }// while end

   // calculates the position shift
   if (shiftValue > 0)
   {
      for (int letterPosition = 0; letterPosition < 26; ++letterPosition)
      {
         int letterPositionShifted = (letterPosition + shiftValue) % 26;
         abcShiftedArray[letterPositionShifted] = abcArray[letterPosition];
      }// for end
   }// if end
   else if (shiftValue < 0)
   {
      for (int letterPosition = 0; letterPosition < 26; ++letterPosition)
      {
         int letterPositionShifted = (letterPosition - shiftValue) % 26;
         if (letterPositionShifted < 0)
         {
            letterPositionShifted += 26;
         }// if end
         abcShiftedArray[letterPositionShifted] = abcArray[letterPosition];
      }// for end
   }// else if end
   else
   {
      for (int letterPosition = 0; letterPosition < 26; ++letterPosition)
      {
         abcShiftedArray[letterPosition] = abcArray[letterPosition];
      }// for end
   }// else end

   // prints the shifted Array
   for (int letterPosition = 0; letterPosition < 26; ++letterPosition)
   {
      cout << abcShiftedArray[letterPosition] << " ";
   }// for end
   cout << endl;

   // user text to be encrypted
   string encryptedText = "";
   string userText = "";
   cout << "Enter some text to encrypt :" << endl;
   cin.ignore();
   getline(cin, userText);

   // encrypts the text 
   for (char& newText : userText) {
      if (isalpha(newText)) {
         int position = toupper(newText) - 'A';
         if (position >= 0 && position < 26) { // Check if index is within bounds
            char shiftedLetter = abcShiftedArray[position][0];
            encryptedText += shiftedLetter;
         }// if end
      }// if end
      else {
         encryptedText += newText;
      }// else end
   }// for end

   // print the encrypted text
   cout << "Encrypted text: " << endl;
   cout << encryptedText << endl;

   return 0;
}// main end

