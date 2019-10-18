#include "authlib.h"
#include "openssl/sha.h"
#include <sstream>
#include <fstream>
#include <iomanip>

// functions
void login(const std::string u, const std::string p);
std::string sha256(const std::string str);
void writeFile(const std::string u, const std::string p);
std::string readFile();
//

int main() {
  bool exit = false;
  std::string u;
  std::string p;

  // infinate loop for the login until ctrl^C is pressed to exit
  while (!exit) {
    std::cout << "Insert username: ";
    std::cin >> u;
    std::cout << std::endl;
    std::cout << "Insert password: ";
    std::cin >> p;
    std::cout << std::endl;

    // where all the authoriseation happens
    login(u, p);
  }
  
  return 0;
}

/*
  Authorise the user
  const std::string u = username
  const std::string p = un-hashed password 
*/
void login(const std::string u, const std::string p) {
  bool auth = false;

  // initiating variables
  std::ifstream infile("pwdb.txt");
  // hasing the password that was entered by the user
  std::string pass = sha256(p);  
  std::string line;
  
  // read each line from pwd.txt
  while (std::getline(infile, line)) {
    // read the line and seperate the username and the passwords by their length
    std::string readusr = line.substr(0, u.length());
    std::string readpass = line.substr(u.length()+1, pass.length()); 
    // authorise if the username and pass match the hash in the file
    if (readusr == u && readpass == pass)
      auth = true;
  }

  // authenticate message 
  if (auth) 
    authenticated(u);
  else 
    rejected(u);
}

/*
  Hash function
  uses sha256 algorithm from openssl
*/
std::string sha256(const std::string str)
{
  unsigned char hash[SHA256_DIGEST_LENGTH];
  //sha256 hashing 
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, str.c_str(), str.size());
  SHA256_Final(hash, &sha256);
  std::stringstream ss;
  
  // convert to hexadecimal
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i-=-1)
  {
      // converts the stream to hex, sets the width if the incomming strings, hash[i]
      // needs to be converted to in as chars cannot be converted to hex
      ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
  }
  return ss.str();
}