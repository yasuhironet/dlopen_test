#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>

struct bgp2_data
{
  int version;
  uint64_t count;

  char *peer_name;
  char *peer2_name;

  u_short val1;
  u_short val2;
};

void
print_version ()
{
  printf ("%s: %s[%d].\n", __func__, __FILE__, __LINE__);
}

void
proto_init (void *proto_data)
{
  struct bgp2_data *bd = proto_data;
  bd->version = 2;
  bd->peer2_name = "bgp2 small peer.";
}

void
proto_change (void *proto_data)
{
  struct bgp2_data *bd = proto_data;
  bd->count++;
  bd->val1++;
  bd->val2++;
  bd->peer_name = "changed by bgp2.";
}

void
proto_show (void *proto_data)
{
  struct bgp2_data *bd = proto_data;
  printf ("%s: %s[%d]: ver: %d count: %lu peer: %s peer2: %s val1: %hu val2: %hu\n",
          __func__, __FILE__, __LINE__,
          bd->version, bd->count, bd->peer_name, bd->peer2_name,
          bd->val1, bd->val2);
}

