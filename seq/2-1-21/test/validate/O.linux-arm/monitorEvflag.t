$ENV{HARNESS_ACTIVE} = 1;
$ENV{TOP} = '/home/pi/code/epics/support/seq/2-1-21';
$ENV{PATH} = '/home/pi/code/epics/support/seq/2-1-21/bin/linux-arm:/home/pi/code/epics/base/bin/linux-arm:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/games:/usr/games';
$ENV{EPICS_CA_SERVER_PORT} = 10000 + $$ % 30000;
#only for debugging:
#print STDERR "port=$ENV{EPICS_CA_SERVER_PORT}\n";
system "./monitorEvflag -S -t -d ../monitorEvflag.db";
