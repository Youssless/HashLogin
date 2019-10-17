#include "authlib.h"
#include "openssl/sha.h"
#include <sstream>
#include <fstream>
#include <iomanip>

void login(const std::string u, const std::string p);
std::string sha256(const std::string str);
void writeFile(const std::string u, const std::string p);
std::string readFile();

int main(int argc, char** argv) {
  bool exit = false;
  std::string u;
  std::string p;
  while (!exit) {
    std::cout << "Insert username: ";
    std::cin >> u;
    std::cout << std::endl;
    std::cout << "Insert password: ";
    std::cin >> p;
    std::cout << std::endl;
    login(u, p);
  }
  
  return 0;
}

void login(const std::string u, const std::string p) {
  bool auth = false;
  std::ifstream infile("pwdb.txt");
  std::string pass = sha256(p);
  std::string line;
  
  while (std::getline(infile, line)) {
    std::string readusr = line.substr(0, u.length());
    std::string readpass = line.substr(u.length()+1, pass.length()); 
    if (readusr == u && readpass == pass)
      auth = true;
  }
  if (auth) 
    authenticated(u);
  else 
    rejected(u);
}

std::string sha256(const std::string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i-=-1)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}