#include <stdio.h>
#include <string.h>

#define APP_NAME "endian"

#define AUTHOR_NAME  "Alexander Smyslov"
#define AUTHOR_EMAIL "kokoc.smyslov@yandex.ru"

#define BIG_ENDIAN_MSG    "Big Endian"
#define LITTLE_ENDIAN_MSG "Little Endian"
#define UNKNOW_ENDIAN_MSG "Unknown Endian"

#define USAGE_MSG \
  "Usage: " "\033[1m" APP_NAME "\033[0m" " [OPTION]"

#define HELP_MSG \
  "\033[1m" "NAME" "\033[0m" "\n" \
    "\t" "\033[1m" APP_NAME "\033[0m" " - determine and print the endianness of a system" "\n\n" \
  "\033[1m" "SYNOPSIS" "\033[0m" "\n" \
    "\t" "\033[1m" APP_NAME "\033[0m" " [OPTION]" "\n\n" \
  "\033[1m" "DESCRIPTION" "\033[0m" "\n" \
    "\t" "The " "\033[1m" APP_NAME "\033[0m" " utility is used to determine and print the endianness of the current system. Endianness refers to the order in which bytes are stored in memory." "\n\n" \
    "\t" "The " "\033[1m" APP_NAME "\033[0m" " utility prints the endianness of the system in a human-readable format. It outputs \"little-endian\" or \"big-endian\" depending on the system's byte order." "\n\n" \
  "\033[1m" "OPTIONS" "\033[0m" "\n" \
    "\t" "\033[1m" "-h" "\033[0m" "\t" "- Displays the given man page." "\n" \
    "\t" "\033[1m" "-n" "\033[0m" "\t" "- Disables line break printing." "\n\n" \
  "\033[1m" "EXIT STATUS" "\033[0m" "\n" \
    "\t" "The " "\033[1m" APP_NAME "\033[0m" " utility returns the following exit status codes:" "\n" \
    "\t" "\033[1m" "0" "\033[0m" "\t" "- Endianness successfully determined and printed." "\n" \
    "\t" "\033[1m" "1" "\033[0m" "\t" "- An error occurred while determining the endianness." "\n\n" \
  "\033[1m" "AUTHORS" "\033[0m" "\n" \
    "\t" "The " "\033[1m" APP_NAME "\033[0m" " utility was written by " AUTHOR_NAME " <" AUTHOR_EMAIL ">." "\n\n" \
  "\033[1m" "BUGS" "\033[0m" "\n" \
    "\t" "Please report any bugs or issues to <" AUTHOR_EMAIL ">." "\n\n" \
  "\033[1m" "COPYRIGHT" "\033[0m" "\n" \
    "\t" "The " "\033[1m" APP_NAME "\033[0m" " utility is available under the GPLv3+: GNU GPL version 3 or later license <https://gnu.org/licenses/gpl.html>." "\n" \
    "\t" "This is free software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law." "\n\n" \
  "\033[1m" "SEE ALSO" "\033[0m" "\n" \
    "\t" "\033[1m" "byteorder" "\033[0m" "(3)" "\n"
  
int
main(int argc, char *argv[])
{
  union {
    short s;
    char c[sizeof(short)];
  } un;
  int new_line;

  un.s = 0x0102;
  new_line = 1;

  if (argc > 2)
  {
    puts(USAGE_MSG);
    return 1;
  }
  if (argc == 2)
  {
    if (strncmp(argv[1], "-h", 2) == 0)
    {
      puts(HELP_MSG);
      return 0;
    }
    if (strncmp(argv[1], "-n", 2) != 0)
    {
      puts(USAGE_MSG);
      return 1;
    }
    new_line = 0;
  }

  if (sizeof(short) != 2)
  {
    printf(UNKNOW_ENDIAN_MSG);
    if (new_line)
      printf("\n");
    return 1;
  }

  if (un.c[0] == 1 && un.c[1] == 2)
    printf(BIG_ENDIAN_MSG);
  else if (un.c[0] == 2 && un.c[1] == 1)
    printf(LITTLE_ENDIAN_MSG);
  else
  {
    printf(UNKNOW_ENDIAN_MSG);
    if (new_line)
      printf("\n");
    return 1;
  }

  if (new_line)
    printf("\n");

  return 0;
}
