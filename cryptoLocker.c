#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "rsa.h"

int main(int argc, char **argv){
  struct public_key_class public[1];
  struct private_key_class private[1];
  rsa_gen_keys( public, private,PRIME_SOURCE_FILE);
  printKeys(public, private);
  

}
