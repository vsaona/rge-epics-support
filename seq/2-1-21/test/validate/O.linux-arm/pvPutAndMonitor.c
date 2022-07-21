/* Generated with snc from pvPutAndMonitor.i */

/* Program "pvPutAndMonitorTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 7 "../pvPutAndMonitor.st"
	int x;
};

/* C code definitions */
# line 3 "../pvPutAndMonitor.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
	};
	*pVar = pVarInit;
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 12 "../pvPutAndMonitor.st"
	seq_test_init(1);
}

/****** Code for state "put_then_incr" in state set "test" ******/

/* Delay function for state "put_then_incr" in state set "test" */
static void D_test_0_put_then_incr(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "put_then_incr" in state set "test" */
static seqBool E_test_0_put_then_incr(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "put_then_incr" in state set "test" */
static void A_test_0_put_then_incr(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 18 "../pvPutAndMonitor.st"
			pVar->x++;
# line 19 "../pvPutAndMonitor.st"
			testDiag("before put: x==%d", pVar->x);
# line 20 "../pvPutAndMonitor.st"
			seq_pvPut(ssId, 0/*x*/, 0);
# line 21 "../pvPutAndMonitor.st"
			pVar->x++;
		}
		return;
	}
}

/****** Code for state "test_x" in state set "test" ******/

/* Entry function for state "test_x" in state set "test" */
static void I_test_0_test_x(SS_ID ssId, struct UserVar *pVar)
{
# line 26 "../pvPutAndMonitor.st"
	testDiag("on entry to state test_x: x==%d", pVar->x);
}

/* Delay function for state "test_x" in state set "test" */
static void D_test_0_test_x(SS_ID ssId, struct UserVar *pVar)
{
# line 28 "../pvPutAndMonitor.st"
	seq_delayInit(ssId, 0, (1));
# line 31 "../pvPutAndMonitor.st"
	seq_delayInit(ssId, 1, (1));
}

/* Event function for state "test_x" in state set "test" */
static seqBool E_test_0_test_x(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 28 "../pvPutAndMonitor.st"
	if (seq_delay(ssId, 0) && pVar->x > 1)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 31 "../pvPutAndMonitor.st"
	if (seq_delay(ssId, 1))
	{
		seq_exit(ssId);
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "test_x" in state set "test" */
static void A_test_0_test_x(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 29 "../pvPutAndMonitor.st"
			testFail("when (x>1): x==%d (you should never see this)", pVar->x);
		}
		return;
	case 1:
		{
# line 32 "../pvPutAndMonitor.st"
			testPass("when(): x==%d", pVar->x);
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 38 "../pvPutAndMonitor.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"counter", offsetof(struct UserVar, x), "x", "int", 1, 1, 0, 1, 0, 0}
};

/* Event masks for state set "test" */
static const seqMask	EM_test_0_put_then_incr[] = {
	0x00000000,
};
static const seqMask	EM_test_0_test_x[] = {
	0x00000002,
};

/* State table for state set "test" */
static seqState G_test_states[] = {
	{
	/* state name */        "put_then_incr",
	/* action function */   A_test_0_put_then_incr,
	/* event function */    E_test_0_put_then_incr,
	/* delay function */    D_test_0_put_then_incr,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_test_0_put_then_incr,
	/* state options */     (0)
	},
	{
	/* state name */        "test_x",
	/* action function */   A_test_0_test_x,
	/* event function */    E_test_0_test_x,
	/* delay function */    D_test_0_test_x,
	/* entry function */    I_test_0_test_x,
	/* exit function */     0,
	/* event mask array */  EM_test_0_test_x,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "test",
	/* states */            G_test_states,
	/* number of states */  2,
	/* number of delays */  2
	},
};

/* Program table (global) */
seqProgram pvPutAndMonitorTest = {
	/* magic number */      2001021,
	/* program name */      "pvPutAndMonitorTest",
	/* channels */          G_channels,
	/* num. channels */     1,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME pvPutAndMonitorTest
#include "seqMain.c"
