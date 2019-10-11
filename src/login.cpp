#include "authlib.h"
#include "openssl/sha.h"
#include <sstream>
#include <fstream>
#include <iomanip>

void login(const std::string u, const std::string p);
std::string sha256(const std::string str);

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
  std::cout << u << "\n" << sha256(p) << std::endl;

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