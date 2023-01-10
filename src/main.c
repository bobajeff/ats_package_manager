#include <stdio.h>
#include <string.h>
#include "search_pkg.h"

/*
atspm build - should build all the binaries
atspm build --bin - should print out all the avaiable binaries
atspm build --bin <binary> - should build the given binary
atspm run - should build the main.dats binary or the binary specified
    by default-run if multiple biniaries are available
atspm run --bin <binary> - should build then run the given binary
*/

int process_subcommand(char *cmd) {
  if (strcmp(cmd, "build") == 0) {
    return 1;
  } else if (strcmp(cmd, "new") == 0) {
    return 2;
  } else if (strcmp(cmd, "init") == 0) {
    return 3;
  } else if (strcmp(cmd, "run") == 0) {
    return 4;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  int counter;
  char *available_binaries[10]; // FIX: ** Who will ever have more than 10
                                // binaries in a project? **
  int bin_count = search_package_for_binaries(available_binaries);

  // argc number or args pass including the command run
  // argv array of arguments as strings

  if (argc == 1)
    printf("ATS Package Manager"
           "\n\nUSAGE:"
           "\n\tatspm [OPTIONS] [SUBCOMMAND]"
           "\n\nOPTIONS:"
           "\n\t-V, --version\t\tPrint version info and exit"
           "\n\t-h, --help\t\tPrint help information"
           "\n\nSUBCOMMANDS:"
           "\n\tbuild, b\tCompile the current package"
           "\n\tnew\t\tCreate a new package"
           "\n\tinit\t\tCreate a new package in an existing directory"
           "\n\trun, r\t\tRun a binary or example of the local package"
           "\n\nSee 'atspm help <command>' for more information on a "
           "specific command.\n");
  if (argc >= 2) {
    int subcommand = process_subcommand(argv[1]);
    switch (subcommand) {
    case 1: // Build
      printf("build selected\n");
      if (argc >= 3) {
        // 3rd argument in argv[2]
        if (strcmp(argv[2], "--bin") == 0) {
          if (argc >= 4) {
            // look up name in available binaries
            int binary_exists = 0;
            if (bin_count >= 1) {
              for (counter = 0; counter < bin_count; counter++) {
                if (!strcmp(argv[3], available_binaries[counter])) {
                  binary_exists = 1;
                  break;
                }
              }
            }
            if (binary_exists == 1) {
              printf("building %s...\n", argv[3]);
              // build binary given
            } else {
              printf("binary %s not found in package\n", argv[3]);
              printf("available binaries:\n");
              for (counter = 0; counter < bin_count; counter++) {
                printf("\t%s\n", available_binaries[counter]);
              }
            }
          } else {
            printf("available binaries:\n");
            for (counter = 0; counter < bin_count; counter++) {
              printf("\t%s\n", available_binaries[counter]);
            }
          }
        } else {
          printf("flag '%s' is unrecognized\n", argv[2]);
        }
      } else {
        // build all the binaries in the package
      }
      break;
    case 2: // New
      printf("new selected\n");
      break;
    case 3: // Init
      printf("init selected\n");
      break;
    case 4: // Run
      printf("run selected\n");
      if (argc >= 3) {
        // 3rd argument in argv[2]
        if (strcmp(argv[2], "--bin") == 0) {
          if (argc >= 4) {
            // build & run binary given
          } else {
            // list available binaries
          }
        } else {
          printf("flag '%s' is unrecognized\n", argv[2]);
        }
      } else {
        // run main binary
        // or:
        // run binary specified in manifest
        // or if multiple binaries:
        // list available binaries
      }
      break;
    default:
      printf("no such subcommand\n");
      break;
    }
  }
  return 0;
}