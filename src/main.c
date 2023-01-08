#include <stdio.h>

int main(int argc, char *argv[]) {
  // argc number or args pass including the command run
  // argv array of arguments as strings
  int counter;
  if (argc == 1)
    printf("ATS Package Manager"
           "\n\nUSAGE:"
           "\n\tpackage_manager [OPTIONS] [SUBCOMMAND]"
           "\n\nOPTIONS:"
           "\n\t-V, --version\t\tPrint version info and exit"
           "\n\t-h, --help\t\tPrint help information"
           "\n\nSUBCOMMANDS:"
           "\n\tbuild, b\tCompile the current package"
           "\n\tnew\t\tCreate a new package_manager package"
           "\n\tinit\t\tCreate a new package_manager package in an existing "
           "directory"
           "\n\trun, r\t\tRun a binary or example of the local package"
           "\n\nSee 'package_manager help <command>' for more information on a "
           "specific command.\n");
  if (argc >= 2) {
    for (counter = 0; counter < argc; counter++) {
      printf("argv[%d]: %s\n", counter, argv[counter]);
    }
  }
  return 0;
}