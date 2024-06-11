#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

char *
solibs[] =
{
  "./libbgp1.so",
  "./libbgp2.so",
};

int
main (int argc, char **argv)
{
  char inputbuf[4] = { 0 };
  int ret;
  void *dlhandle;
  void (*func)(void);

  int index;
  char *current_solib;
  const int solibs_size = sizeof (solibs) / sizeof (solibs[0]);

  index = 0;
  while (1)
    {
      ret = fread (inputbuf, 1, 1, stdin);
      if (ret == 0)
        break;

      current_solib = solibs[index];
      printf ("work on %s.\n", current_solib);

      dlhandle = dlopen (current_solib, RTLD_NOW);
      if (! dlhandle)
        {
          fprintf (stderr, "dlopen(): error: %s\n", dlerror ());
          continue;
        }

      func = (void (*)(void)) dlsym (dlhandle, "print_version");
      if (! func)
        {
          fprintf (stderr, "dlsym(): error: %s\n", dlerror ());
          continue;
        }

      func ();

      index++;
      index %= solibs_size;
    }

  return EXIT_SUCCESS;
}

