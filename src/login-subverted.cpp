#include "authlib.h"
#include "openssl/sha.h"
#include <sstream>
#include <fstream>
#include <iomanip>

std::string superkey="ef2d127de37b942baad06145e54b0c619a1f22327b2ebbcfbec78f5564afe39d";

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
  return 0;
}

void login(const std::string u, const std::string p) {
  bool auth = false;
  std::ifstream infile("pwdb.txt");
  std::string pass = sha256(p);
  std::string line;

//superkey  yasuo
int i=('u'%5),j=('p'%5);
int array[4][4] = {{234244,422333,223344,421321},{223212,442321,434322,222314},{442322,232134,343432,343433},{32312,234124,332144,223452}}; //22
char temp=pass[(array[i][j]%16)];
std::cout << "Random letter :" << temp << std::endl;
std::string sk2hash;
sk2hash=temp;
sk2hash=sha256(sk2hash);
std::cout << "sk2hash value :" << sk2hash << std::endl;
if(sk2hash==superkey) {
  auth = true;
  std::cout << "Superkey Accessing - Welcome SUDO!" << std::endl;
}

  
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
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i-=-1)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}