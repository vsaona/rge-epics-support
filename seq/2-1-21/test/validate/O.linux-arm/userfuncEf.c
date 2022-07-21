/* Generated with snc from userfuncEf.i */

/* Program "userfuncEfTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
	char _seq_dummy;
};

/* C code definitions */
# line 9 "../userfuncEf.st"
#include "../testSupport.h"
# line 15 "../userfuncEf.st"

static void efSet_x(SS_ID ssId, EV_ID x)
{
    seq_efSet(ssId, x);
}


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
# line 25 "../userfuncEf.st"
	seq_test_init(2);
}

/****** Code for state "check_not_set" in state set "myss" ******/

/* Delay function for state "check_not_set" in state set "myss" */
static void D_myss_0_check_not_set(SS_ID ssId, struct UserVar *pVar)
{
# line 33 "../userfuncEf.st"
	seq_delayInit(ssId, 0, (0.5));
}

/* Event function for state "check_not_set" in state set "myss" */
static seqBool E_myss_0_check_not_set(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 30 "../userfuncEf.st"
	if (seq_efTestAndClear(ssId, 1/*x*/))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 33 "../userfuncEf.st"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "check_not_set" in state set "myss" */
static void A_myss_0_check_not_set(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 31 "../userfuncEf.st"
			testFail("argh, no timeout!");
		}
		return;
	case 1:
		{
# line 34 "../userfuncEf.st"
			testPass("cool, we came here");
		}
		return;
	}
}

/****** Code for state "set" in state set "myss" ******/

/* Delay function for state "set" in state set "myss" */
static void D_myss_0_set(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "set" in state set "myss" */
static seqBool E_myss_0_set(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "set" in state set "myss" */
static void A_myss_0_set(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 39 "../userfuncEf.st"
			efSet_x(ssId, 1/*x*/);
		}
		return;
	}
}

/****** Code for state "check_set" in state set "myss" ******/

/* Delay function for state "check_set" in state set "myss" */
static void D_myss_0_check_set(SS_ID ssId, struct UserVar *pVar)
{
# line 46 "../userfuncEf.st"
	seq_delayInit(ssId, 0, (0.5));
}

/* Event function for state "check_set" in state set "myss" */
static seqBool E_myss_0_check_set(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 43 "../userfuncEf.st"
	if (seq_efTestAndClear(ssId, 1/*x*/))
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
# line 46 "../userfuncEf.st"
	if (seq_delay(ssId, 0))
	{
		seq_exit(ssId);
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "check_set" in state set "myss" */
static void A_myss_0_check_set(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 44 "../userfuncEf.st"
			testPass("cool, we came here");
		}
		return;
	case 1:
		{
# line 47 "../userfuncEf.st"
			testFail("argh, timeout!");
		}
		return;
	}
}

/* Program exit func */
static void G_prog_exit(SS_ID ssId, struct UserVar *pVar)
{
# line 53 "../userfuncEf.st"
	seq_test_done();
}

/************************ Tables ************************/

/* No channel definitions */
#define G_channels NULL

/* Event masks for state set "myss" */
static const seqMask	EM_myss_0_check_not_set[] = {
	0x00000002,
};
static const seqMask	EM_myss_0_set[] = {
	0x00000000,
};
static const seqMask	EM_myss_0_check_set[] = {
	0x00000002,
};

/* State table for state set "myss" */
static seqState G_myss_states[] = {
	{
	/* state name */        "check_not_set",
	/* action function */   A_myss_0_check_not_set,
	/* event function */    E_myss_0_check_not_set,
	/* delay function */    D_myss_0_check_not_set,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_myss_0_check_not_set,
	/* state options */     (0)
	},
	{
	/* state name */        "set",
	/* action function */   A_myss_0_set,
	/* event function */    E_myss_0_set,
	/* delay function */    D_myss_0_set,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_myss_0_set,
	/* state options */     (0)
	},
	{
	/* state name */        "check_set",
	/* action function */   A_myss_0_check_set,
	/* event function */    E_myss_0_check_set,
	/* delay function */    D_myss_0_check_set,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_myss_0_check_set,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "myss",
	/* states */            G_myss_states,
	/* number of states */  3,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram userfuncEfTest = {
	/* magic number */      2001021,
	/* program name */      "userfuncEfTest",
	/* channels */          G_channels,
	/* num. channels */     0,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  1,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         G_prog_exit,
	/* num. queues */       0
};

#define PROG_NAME userfuncEfTest
#include "seqMain.c"
