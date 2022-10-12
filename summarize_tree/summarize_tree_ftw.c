#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    // Define stuff here
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {
    // Check arguments and set things up

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print out the results
}
