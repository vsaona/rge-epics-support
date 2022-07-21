# 1 "../pvGetSync.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../pvGetSync.st"






program pvGetSyncTest

%%#include "../testSupport.h"

%%epicsShareExtern double seq_sync_timeout;

foreign seq_sync_timeout;

entry {
    seq_test_init(2);
}

ss sstest {
    double x = 0;
    assign x to "pvGetSync";
    int p = 1;
    assign p to "pvGetSync.PROC";

    state stest1 {
        when () {
            int status;
            seq_sync_timeout = 0.1;
            pvPut(p, ASYNC);
            testDiag("x=%f",x);
            status = pvGet(x,SYNC);
            testOk(status==pvStatTIMEOUT, "pvGet/SYNC, status=%d (%s)",
                status, status ? pvMessage(x) : "");
            testDiag("x=%f",x);
        } state stest2
    }
    state stest2 {
        when (pvPutComplete(p)) {
            int status;
            pvPut(p, ASYNC);
            seq_sync_timeout = 10.0;
            testDiag("x=%f",x);
            status = pvGet(x,SYNC);
            testOk(status==pvStatOK, "pvGet/SYNC, status=%d (%s)",
                status, status ? pvMessage(x) : "");
            testDiag("x=%f",x);
        } exit
    }
}

exit {
    seq_test_done();
}
