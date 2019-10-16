#include "authlib.h"
#include "openssl/sha.h"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <string>
#include <cassert>
//g++ -o login  login.cpp -lssl -lcrypto

std::string sha256(const std::string str);
void writeFile(const std::string u, const std::string p);
//std::string readFile(const std::string u, const std::string p);
void MainMenu();
void Login();
void Register();

int main() {
    MainMenu();
  return 0;
}

void MainMenu(){
  int choice=10;
  std::cout << "\t\tWelcome to the Login system!\n" << std::endl;
  std::cout << "\t\t\t 1.Login\n" << std::endl;
  std::cout << "\t\t\t 2.Register\n" << std::endl;
  std::cout << "\t\t\t 0.Exit\n" << std::endl;
  std::cout << "\t\tPlease make your choice(0-1-2):";
  std::cin >> choice ;
    while(choice!=1 && choice!=2 && choice!=0){
      std::cout << "\t\tPlease make your choice(0-1-2):";
      std::cin >> choice ;
    }
    if(choice == 0){
      std::cout << "test choose 3\n";
        exit(1);
    }
    else if(choice == 1){
        Login();
    }
    else if(choice == 2){
        Register();
    }
}

void Login() {

  //std::cout << u << "\n" << sha256(p) << std::endl;
  //writeFile(u, p);
  //readFile(u, p);
  /*
  std::cout << "test\n";
  std::cout << "Value of hashpassword is : " << sha256(p) ;
  std::cout << "\nThe password files is  : \n";
    ssttd::ifream infile;
    infile.open("passwords.txt");
    //std::assert("passwords.txt");

    std::string s;
    while(getline(infile,s))
    {
        std::cout<<s<<"\n";
    }
    infile.close();


  bool auth = false;
  if (auth) authenticated("user");
  else rejected("user");
  */

      bool auth = false;
 std::cout << "test choose 1\n";
      char username[50],lineInformation[200];
      std::string password,checkpassword=lineInformation;
      std::ifstream infile;
      infile.open("pwdb.txt");


      std::cout << "\t\t\t     Welcome to the Login!\n" << std::endl;


      std::cout << "\t\t\t Please input your username: " ;
      std::cin >>username;

     while(strncasecmp(username,lineInformation,strlen(username))!=0||lineInformation[strlen(username)]!=':'){
        if(infile.eof()){
          std::cout <<"\t\t\tYou have not register yet!\n"<< std::endl;
          MainMenu();
        }
        infile.getline(lineInformation,200);
     }

      /*   test
      getline(infile,lineInformation);
      std::cout << "test choose 1-1\n";
      std::cout << lineInformation[1] << std::endl;
      */

      std::cout << "\t\t\t Please input your password: " ;
      std::cin >>password;
      password=sha256(password);
      checkpassword=checkpassword.substr(strlen(username)+1,strlen(username)+65);

      if(password==checkpassword) auth = true;
      else {
        std::cout <<"\t\t\tYour password is wrong!\n"<< std::endl;
        MainMenu();
      }
      infile.close();
 std::cout << "test choose 1-2\n";
      if (auth) authenticated(username);
      else rejected(username);
}

void Register(){
    std::cout << "test choose 2\n";
      std::string username,password="1",passwordC="2";
      std::cout << "\t\t\t     Welcome to the Register!\n" << std::endl;
      std::cout << "\t\t\t Please input your username: " ;
      std::cin >>username;
      while(password != passwordC){
      std::cout << "\t\t\t Please input your password: " ;
      std::cin >>password;
      std::cout << "\t\t\t Please input your password second time: " ;
      std::cin >>passwordC;
      if(password != passwordC)std::cout << "\t\t\t Please make sure you input the same password!\n";
      }
    std::cout << "test register successfully!\n";
      writeFile(username,password);
      MainMenu();

}


void writeFile(const std::string u, const std::string p) {
  std::ofstream outfile;
  outfile.open("pwdb.txt", std::ofstream::app | std::ofstream::out);
  outfile << u << ": " << sha256(p) << "\n";
  outfile.close();
}

/**
 * Read the file to get the hash
 * Then in the login function compare the hash in the file to the hashed input
 * */
/*
std::string readFile(const std::string u, const std::string p) {
  //std::string hashp;
  //hashp << sha256(p) ;
  std::cout << "test";
  std::cout << "Value of hashpassword is : " << sha256(p) ;
  std::cout << "The password files is  : ";
    std::ifstream infile;
    infile.open("passwords.txt");
    //std::assert("passwords.txt");

    std::string s;
    while(getline(infile,s))
    {
        std::cout<<s;
    }
    infile.close();

  return p;
}*/


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
