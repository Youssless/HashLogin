#include <iostream>
#include "authlib.h"
#include "openssl/sha.h"

int main() {
  bool auth = true;
  
  if (auth) authenticated("user");
  else rejected("user");
}
