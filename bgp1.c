#include <stdio.h>

void
print_version ()
{
  printf ("%s: %s[%d].\n", __func__, __FILE__, __LINE__);
}

