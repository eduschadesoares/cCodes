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

	int choice;
	int result = 1;

	if (argc <= 1) {
		printf("Error!\nYou need to insert a path!\n");
		return -1;
	} else if (argc < 3) {
		printf("Error!\nYou need to insert a file type!\n");
		return -1;
	}

	if (strcmp(argv[2], "-u") == 0) {
		printf("Displaying 'Unknown type'...");
		choice = DT_UNKNOWN;
		} else if (strcmp(argv[2], "-f") == 0) {
			printf("Displaying 'Fifo type'...");
			choice = DT_FIFO;
			} else if (strcmp(argv[2], "-c") == 0) {
				printf("Displaying 'Character type'...");
				choice = DT_CHR;
				} else if (strcmp(argv[2], "-d") == 0) {
					printf("Displaying 'Directory type'...");
					choice = DT_DIR;
					} else if (strcmp(argv[2], "-b") == 0) {
						printf("Displaying 'Block type'...");
						choice = DT_BLK;
						} else if (strcmp(argv[2], "-r") == 0) {
							printf("Displaying 'Regular type'...");
							choice = DT_REG;
							} else if (strcmp(argv[2], "-l") == 0) {
								printf("Displaying 'Link type'...");
								choice = DT_LNK;
								} else if (strcmp(argv[2], "-s") == 0) {
									printf("Displaying 'Socket type'...");
									choice = DT_SOCK;
									}
	
	if (dir = opendir (argv[1])) {
		while ((entry = readdir (dir))) {
		if(entry->d_type == choice) {
		printf("Dir name: %s\n", entry->d_name);
		printf("Type: %d\n\n", entry->d_type);
		}
	}
		closedir (dir);
		result = 0;
	} else perror ("openddir()");

	return result;
}
