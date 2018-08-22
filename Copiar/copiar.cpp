#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <sys/wait.h>

const int b = 1;
const int Kb = 1024;
const int Mb = 1024 * 1024;
const int Gb = 1024 * 1024 * 1024;

int main() {
    printf("%i\n", b);
    printf("%i\n", Kb);
    printf("%i\n", Mb);
    printf("%i\n", Gb);
    return 0;
}