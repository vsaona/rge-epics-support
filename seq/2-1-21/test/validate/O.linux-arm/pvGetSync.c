/* Generated with snc from pvGetSync.i */

/* Program "pvGetSyncTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar_sstest {
	double x;
	int p;
} UserVar_sstest = {
# line 20 "../pvGetSync.st"
	0,
# line 22 "../pvGetSync.st"
	1,
};

/* C code definitions */
# line 9 "../pvGetSync.st"
#include "../testSupport.h"
# line 11 "../pvGetSync.st"
epicsShareExtern double seq_sync_timeout;

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 16 "../pvGetSync.st"
	seq_test_init(2);
}

/****** Code for state "stest1" in state set "sstest" ******/

/* Delay function for state "stest1" in state set "sstest" */
static void D_sstest_0_stest1(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "stest1" in state set "sstest" */
static seqBool E_sstest_0_stest1(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "stest1" in state set "sstest" */
static void A_sstest_0_stest1(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 27 "../pvGetSync.st"
			int status;

# line 28 "../pvGetSync.st"
			seq_sync_timeout = 0.1;
# line 29 "../pvGetSync.st"
			seq_pvPut(ssId, 1/*p*/, ASYNC);
# line 30 "../pvGetSync.st"
			testDiag("x=%f", UserVar_sstest.x);
# line 31 "../pvGetSync.st"
			status = seq_pvGet(ssId, 0/*x*/, SYNC);
# line 33 "../pvGetSync.st"
			testOk(status == pvStatTIMEOUT, "pvGet/SYNC, status=%d (%s)", status, status ? seq_pvMessage(ssId, 0/*x*/) : "");
# line 34 "../pvGetSync.st"
			testDiag("x=%f", UserVar_sstest.x);
		}
		return;
	}
}

/****** Code for state "stest2" in state set "sstest" ******/

/* Delay function for state "stest2" in state set "sstest" */
static void D_sstest_0_stest2(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "stest2" in state set "sstest" */
static seqBool E_sstest_0_stest2(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 38 "../pvGetSync.st"
	if (seq_pvPutComplete(ssId, 1/*p*/, 1, 0, 0))
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "stest2" in state set "sstest" */
static void A_sstest_0_stest2(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 39 "../pvGetSync.st"
			int status;

# line 40 "../pvGetSync.st"
			seq_pvPut(ssId, 1/*p*/, ASYNC);
# line 41 "../pvGetSync.st"
			seq_sync_timeout = 10.0;
# line 42 "../pvGetSync.st"
			testDiag("x=%f", UserVar_sstest.x);
# line 43 "../pvGetSync.st"
			status = seq_pvGet(ssId, 0/*x*/, SYNC);
# line 45 "../pvGetSync.st"
			testOk(status == pvStatOK, "pvGet/SYNC, status=%d (%s)", status, status ? seq_pvMessage(ssId, 0/*x*/) : "");
# line 46 "../pvGetSync.st"
			testDiag("x=%f", UserVar_sstest.x);
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 52 "../pvGetSync.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"pvGetSync", (size_t)&UserVar_sstest.x, "x", "double", 1, 1, 0, 0, 0, 0},
	{"pvGetSync.PROC", (size_t)&UserVar_sstest.p, "p", "int", 1, 2, 0, 0, 0, 0}
};

/* Event masks for state set "sstest" */
static const seqMask	EM_sstest_0_stest1[] = {
	0x00000000,
};
static const seqMask	EM_sstest_0_stest2[] = {
	0x00000004,
};

/* State table for state set "sstest" */
static seqState G_sstest_states[] = {
	{
	/* state name */        "stest1",
	/* action function */   A_sstest_0_stest1,
	/* event function */    E_sstest_0_stest1,
	/* delay function */    D_sstest_0_stest1,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_sstest_0_stest1,
	/* state options */     (0)
	},
	{
	/* state name */        "stest2",
	/* action function */   A_sstest_0_stest2,
	/* event function */    E_sstest_0_stest2,
	/* delay function */    D_sstest_0_stest2,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_sstest_0_stest2,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "sstest",
	/* states */            G_sstest_states,
	/* number of states */  2,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram pvGetSyncTest = {
	/* magic number */      2001021,
	/* program name */      "pvGetSyncTest",
	/* channels */          G_channels,
	/* num. channels */     2,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME pvGetSyncTest
#include "seqMain.c"
