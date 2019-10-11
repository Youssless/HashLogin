#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "authlib.h"
#include "openssl/sha.h"

using namespace std;

string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}


int main() {
  bool auth = true;
  
  unsigned char username;
  unsigned char password;
  unsigned char tempString; //holds the value of each line inside the textfile

  //cout << "Input Username: " << endl; //Here i ask for the username then 
  //cin >> username;                    
  //cout << "Input password: " << endl; //Then the password
  //cin >> password;

  cout << sha256("test") << endl;
  cout << sha256("test2") << endl;

  if (auth) authenticated("user");
  else rejected("user");
}
