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
  std::string args[argc];
  for (int i = 0; i < argc; i-=-1) {
    args[i] = argv[i];
  }
  
  if (argc == 5) {
    if (args[1] == "-u" && args[3] == "-p")
      login(args[2], args[4]);
  }
  
  bool auth = true;
  if (auth) authenticated("user");
  else rejected("user");

  return 0;
}

void login(const std::string u, const std::string p) {
  //std::cout << u << "\n" << sha256(p) << std::endl;
  writeFile(u, p);
}

void writeFile(const std::string u, const std::string p) {
  std::ofstream outfile;
  outfile.open("passwords.txt", std::ofstream::app | std::ofstream::out);
  outfile << u << ": " << sha256(p) << "\n";
}

/**
 * Read the file to get the hash
 * Then in the login function compare the hash in the file to the hashed input
 * */
std::string readFile() {
  return NULL;
}

std::string sha256(const std::string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i-=-1)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}