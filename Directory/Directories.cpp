#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  DIR *dir;
  struct dirent *entry;

  int result = 1;

  if (argc <= 1) {
    printf("Insira algum diretório.\n"); return -1;
  } else if (argc < 3) {
    printf("Insira o tipo da entrada de diretório.\n"); return -1;
  }

  int a;


  if(strcmp(argv[2], "a") == 0) {
    a = 8;
  } else if(strcmp(argv[2], "d") == 0){
    a = 4;
  }
  
  if (dir = opendir (argv[1])) {
     while ((entry = readdir (dir))) {
      if(entry->d_type == a) {

        printf("Nome do diretório: %s\n", entry->d_name);
       // printf("i-node: %ld\n", entry->d_ino);
       // printf("Off: %ld\n", entry->d_off);
       // printf("Reclen: %d\n", entry->d_reclen);
        printf("Type: %d\n\n", entry->d_type);
      }
    }
      closedir (dir);
      result = 0;
  } else perror ("openddir()");

  return result;
}
