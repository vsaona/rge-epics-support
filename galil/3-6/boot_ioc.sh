#!/bin/bash

# NOTE. To exit the epics shell, use `ctrl + X`. If you hit `ctrl + C` the
#       shell will stall! At this point the only way to kill it is to hit it
#       SIGKILL (It doesn't respond to SIGTERM). The killall.sh command is
#       conveniently left on this directory to murder the shell in this
#       scenario.
cd "iocBoot/iocGalilTest/"
../../bin/linux-arm/GalilTest st.cmd
cd - > /dev/null
