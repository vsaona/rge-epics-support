/* Generated with snc from pvGetComplete.i */

/* Program "pvGetCompleteTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar_pvGetComplete {
	int r[2];
	int w[2];
	int n;
} UserVar_pvGetComplete = {
	{0,0},
	{0,0},
# line 23 "../pvGetComplete.st"
	0,
};

/* C code definitions */
# line 9 "../pvGetComplete.st"
#include "../testSupport.h"

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 14 "../pvGetComplete.st"
	seq_test_init(1);
# line 15 "../pvGetComplete.st"
	testDiag("start");
}

/****** Code for state "count" in state set "pvGetComplete" ******/

/* Delay function for state "count" in state set "pvGetComplete" */
static void D_pvGetComplete_0_count(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "count" in state set "pvGetComplete" */
static seqBool E_pvGetComplete_0_count(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 26 "../pvGetComplete.st"
	if (UserVar_pvGetComplete.n < 20000)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	if (TRUE)
	{
		seq_exit(ssId);
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "count" in state set "pvGetComplete" */
static void A_pvGetComplete_0_count(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 27 "../pvGetComplete.st"
			UserVar_pvGetComplete.n++;
# line 28 "../pvGetComplete.st"
			if (UserVar_pvGetComplete.n % 1000 == 0)
			{
# line 29 "../pvGetComplete.st"
				testDiag("passed %d runs", UserVar_pvGetComplete.n);
			}
		}
		return;
	case 1:
		{
# line 33 "../pvGetComplete.st"
			testPass("%d pvGets completed in time and results agree with predictions", 2 * 20000);
		}
		return;
	}
}

/****** Code for state "test" in state set "pvGetComplete" ******/

/* Entry function for state "test" in state set "pvGetComplete" */
static void I_pvGetComplete_0_test(SS_ID ssId, struct UserVar *pVar)
{
# line 38 "../pvGetComplete.st"
	int i;
# line 39 "../pvGetComplete.st"
	UserVar_pvGetComplete.w[0] = UserVar_pvGetComplete.n;
# line 40 "../pvGetComplete.st"
	UserVar_pvGetComplete.w[1] = -UserVar_pvGetComplete.n;
# line 41 "../pvGetComplete.st"
	for (i = 0; i < 2; i++)
	{
# line 42 "../pvGetComplete.st"
		UserVar_pvGetComplete.r[i] = 0;
# line 43 "../pvGetComplete.st"
		seq_pvPut(ssId, 2/*w*/ + (VAR_ID)(i), SYNC);
	}
# line 45 "../pvGetComplete.st"
	for (i = 0; i < 2; i++)
	{
# line 46 "../pvGetComplete.st"
		seq_pvGet(ssId, 0/*r*/ + (VAR_ID)(i), ASYNC);
	}
}

/* Delay function for state "test" in state set "pvGetComplete" */
static void D_pvGetComplete_0_test(SS_ID ssId, struct UserVar *pVar)
{
# line 49 "../pvGetComplete.st"
	seq_delayInit(ssId, 0, (2));
}

/* Event function for state "test" in state set "pvGetComplete" */
static seqBool E_pvGetComplete_0_test(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 49 "../pvGetComplete.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
# line 52 "../pvGetComplete.st"
	if (seq_pvGetComplete(ssId, 0/*r*/ + (VAR_ID)(0)) && seq_pvGetComplete(ssId, 0/*r*/ + (VAR_ID)(1)))
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "test" in state set "pvGetComplete" */
static void A_pvGetComplete_0_test(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 50 "../pvGetComplete.st"
			testFail("pvGet completion timeout");
		}
		return;
	case 1:
		{
# line 53 "../pvGetComplete.st"
			int i;

# line 54 "../pvGetComplete.st"
			for (i = 0; i < 2; i++)
			{
# line 55 "../pvGetComplete.st"
				if (UserVar_pvGetComplete.r[i] != UserVar_pvGetComplete.w[i])
				{
# line 56 "../pvGetComplete.st"
					testFail("n=%d, i=%d, w=%d, r=%d", UserVar_pvGetComplete.n, i, UserVar_pvGetComplete.w[i], UserVar_pvGetComplete.r[i]);
					{*pNextState = 2; return;}
				}
			}
		}
		return;
	}
}

/****** Code for state "fail" in state set "pvGetComplete" ******/

/* Delay function for state "fail" in state set "pvGetComplete" */
static void D_pvGetComplete_0_fail(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "fail" in state set "pvGetComplete" */
static seqBool E_pvGetComplete_0_fail(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "fail" in state set "pvGetComplete" */
static void A_pvGetComplete_0_fail(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 69 "../pvGetComplete.st"
	testDiag("exit");
# line 70 "../pvGetComplete.st"
	seq_test_done();
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"pvGetComplete1", (size_t)&UserVar_pvGetComplete.r[0], "r[0]", "int", 1, 1, 0, 0, 0, 0},
	{"pvGetComplete2", (size_t)&UserVar_pvGetComplete.r[1], "r[1]", "int", 1, 2, 0, 0, 0, 0},
	{"pvGetComplete1", (size_t)&UserVar_pvGetComplete.w[0], "w[0]", "int", 1, 3, 0, 0, 0, 0},
	{"pvGetComplete2", (size_t)&UserVar_pvGetComplete.w[1], "w[1]", "int", 1, 4, 0, 0, 0, 0}
};

/* Event masks for state set "pvGetComplete" */
static const seqMask	EM_pvGetComplete_0_count[] = {
	0x00000000,
};
static const seqMask	EM_pvGetComplete_0_test[] = {
	0x00000006,
};
static const seqMask	EM_pvGetComplete_0_fail[] = {
	0x00000000,
};

/* State table for state set "pvGetComplete" */
static seqState G_pvGetComplete_states[] = {
	{
	/* state name */        "count",
	/* action function */   A_pvGetComplete_0_count,
	/* event function */    E_pvGetComplete_0_count,
	/* delay function */    D_pvGetComplete_0_count,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_pvGetComplete_0_count,
	/* state options */     (0)
	},
	{
	/* state name */        "test",
	/* action function */   A_pvGetComplete_0_test,
	/* event function */    E_pvGetComplete_0_test,
	/* delay function */    D_pvGetComplete_0_test,
	/* entry function */    I_pvGetComplete_0_test,
	/* exit function */     0,
	/* event mask array */  EM_pvGetComplete_0_test,
	/* state options */     (0)
	},
	{
	/* state name */        "fail",
	/* action function */   A_pvGetComplete_0_fail,
	/* event function */    E_pvGetComplete_0_fail,
	/* delay function */    D_pvGetComplete_0_fail,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_pvGetComplete_0_fail,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "pvGetComplete",
	/* states */            G_pvGetComplete_states,
	/* number of states */  3,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram pvGetCompleteTest = {
	/* magic number */      2001021,
	/* program name */      "pvGetCompleteTest",
	/* channels */          G_channels,
	/* num. channels */     4,
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

#define PROG_NAME pvGetCompleteTest
#include "seqMain.c"
