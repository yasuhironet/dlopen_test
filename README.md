
# dlopen_test

```
~/dlopen_test$ ./dlopen_test 

work on ./libbgp1.so.
print_version: bgp1.c[17].
dlsym(): error: ./libbgp1.so: undefined symbol: proto_change
proto_show: bgp1.c[34]: ver: 1 count: 1 peer: bgp1 super peer. number1: 0 number2: 0

work on ./libbgp2.so.
print_version: bgp2.c[20].
proto_show: bgp2.c[46]: ver: 2 count: 2 peer: changed by bgp2. peer2: bgp2 small peer. val1: 1 val2: 1

work on ./libbgp3.so.
print_version: bgp3.c[22].
proto_show: bgp3.c[46]: ver: 2 count: 3 peer: changed by bgp2. peer2: bgp2 small peer. val1: 1 val2: 1
proto_show: bgp3.c[50]: bgp local data: this is a local data.

work on ./libbgp1.so.
print_version: bgp1.c[17].
dlsym(): error: ./libbgp1.so: undefined symbol: proto_change
proto_show: bgp1.c[34]: ver: 1 count: 4 peer: bgp1 super peer. number1: -2049175532 number2: 32572
```

