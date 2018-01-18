#include <iostream>
#include "sha512.h"
#include "md5.h"
#include <sstream>
#include <cstdlib>
 
 namespace patch
 {
     template < typename T > std::string to_string( const T& n )
     {
         std::ostringstream stm ;
         stm << n ;
         return stm.str() ;
     }
 }
 
 using std::string;
 using std::cout;
 using std::endl;
 using std::cin;
 
 bool checkHash(string hash, string mode);
 void numericCracker(string hash, string mode);
 string hasher(string content, string mode);
 
 int main(int argc, char *argv[])
 {
     string input = "grape";
     string output1 = sha512(input);
     cout << "C++ Hashcracker (SHA512, MD5)" << endl;
     cout << "1 - SHA512" << endl;
     cout << "2 - MD5" << endl;
     cout << "Enter Number: ";
     int mode;
     cin >> mode;
     string hash;
     cout << "Enter Hash: ";
     cin >> hash;
     switch(mode) {
     case 1:
         if(checkHash(hash, "SHA512")) {
             numericCracker(hash, "SHA512");
         }
         break;
     case 2:
         if(checkHash(hash, "MD5")) {
             numericCracker(hash, "MD5");
         }
         break;
     }
     return 0;
 }
 
 bool checkHash(string hash, string mode) {
     if(mode == "SHA512") {
         if(hash.length() == 128) {
             return true;
         }
     }
 
     if(mode == "MD5") {
         if(hash.length() == 32) {
             return true;
         }
     }
 
     return false;
 }
 
 string hasher(string content, string mode) {
     if(mode == "SHA512") {
         return sha512(content);
     }
     if(mode == "MD5") {
         return md5(content);
     }
 }
 
 void numericCracker(string hash, string mode) {
     int i = 0;
     string bHash;
     string iterator;
 
     while (true) {
         iterator = patch::to_string(i);
         bHash = hasher(iterator, mode);
         cout << "[*] Cracking... | " << i << " : " << hash << "\r";
         if(hash == bHash) {
             cout << "\nMatch found! " << "Number: " << i << " Hash: " << hash << endl;
             exit(0);
         }
         i++;
     }
 }