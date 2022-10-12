#include <stdio.h>
#include <ftw.h>

static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    // If the given entry is a directory, increase the number of directories
    if(S_ISDIR(sb->st_mode)) {
        num_dirs++;
    } else {
    // Otherwise, increase the number of files
        num_regular++;
    }
    return 0;
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {
    // Check arguments and set things up
    if (argc != 2) {
        printf("ERROR: Enter program name and directory; Two argumetns expected!");
	return 1;
    }

    // Set the number of directories and files to zero
    num_dirs = 0;
    num_regular = 0;

    // Count the number of directories and files
    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print out the results
    printf("There were %d directories.\n", num_dirs);
    printf("There were %d regular files.\n", num_regular);
}
