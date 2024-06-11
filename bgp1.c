#include <stdio.h>
#include <stdint.h>

struct bgp1_data
{
  int version;
  uint64_t count;

  char *peer_name;
  int number1;
  uint32_t number2;
};

void
print_version ()
{
  printf ("%s: %s[%d].\n", __func__, __FILE__, __LINE__);
}

void
proto_init (void *proto_data)
{
  struct bgp1_data *bd = proto_data;
  bd->version = 1;
  bd->count++;
  bd->peer_name = "bgp1 super peer.";
}

void
proto_show (void *proto_data)
{
  struct bgp1_data *bd = proto_data;
  printf ("%s: %s[%d]: ver: %d count: %lu peer: %s number1: %d number2: %u\n",
          __func__, __FILE__, __LINE__,
          bd->version, bd->count, bd->peer_name,
          bd->number1, bd->number2);
}

