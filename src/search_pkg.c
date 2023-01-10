#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search_package_for_binaries(char *available_binaries[]) {
  // * add main.dats to available_binaries as "<projec_name>"
  // * search src/bin directory for filenames and foldernames
  //   and add those.
  int offset = 0;
  int bin_count = 0;
  DIR *d;
  struct dirent *dir;
  d = opendir("src/bin/");

  // read manifest.toml to find name of the project
  // check for src/main.dats
  // if doesn't exist don't use for default binary

  if (d) {
    while ((dir = readdir(d)) != NULL) {
      // gaurd against going over the max size of available_binaries array
      if (offset > 10) {
        break;
      }
      // find folders containing main.dats file
      if (dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0 &&
          strcmp(dir->d_name, "..") != 0) {
        printf("\n%s is a directory\n\n", dir->d_name);
        // check if directory has main.dats
        FILE *file;
        char *fileuri = malloc(strlen("src/bin/") + strlen(dir->d_name) +
                               strlen("/main.dats") + 1);
        strcpy(fileuri, "src/bin/");
        strcat(fileuri, dir->d_name);
        strcat(fileuri, "/main.dats");

        if ((file = fopen(fileuri, "r")) != NULL) {
          printf("%s has main.dats", dir->d_name);
          // add directory name to binaries
          available_binaries[offset++] = dir->d_name;
          bin_count++;
          fclose(file);
        }
        free(fileuri);

      }
      // find .dats files
      else if (strstr(dir->d_name, ".dats") != NULL) {
        // extract the stem from the filename
        char *pointer_to_end_of_stem = strstr(dir->d_name, ".dats");
        if (pointer_to_end_of_stem != NULL) {
          // subtract pointer to string from pointer to end of (filename) stem
          size_t stem_length = pointer_to_end_of_stem - dir->d_name;
          // save it to available_binaries
          available_binaries[offset++] = strndup(dir->d_name, stem_length);
          bin_count++; // don't really need both bin_count and offset variables
        }
      }
    }
    closedir(d);
  } else {
    printf("\t** no src/bin/ in project! **\n\n");
  }
  return bin_count;
}
