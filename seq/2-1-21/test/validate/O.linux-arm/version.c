/* Generated with snc from version.i */

/* Program "versionTest" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */

/* C code definitions */
# line 4 "../version.st"
#include <stdlib.h>

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
}

/* Program entry func */
static void G_prog_entry(SS_ID ssId, struct UserVar *pVar)
{
# line 8 "../version.st"
	printf("conditional compilation in\n");
# line 12 "../version.st"
	printf("seq version is 2.1 or less\n");
	



    printf("seq version is 2.1 or less\n");


	#if 2001021 >= 2002000
	printf("seq version is 2.2 or greater\n");
	#else
	printf("seq version is 2.1 or less\n");
	#endif
}

/****** Code for state "x" in state set "x" ******/

/* Delay function for state "x" in state set "x" */
static void D_x_0_x(SS_ID ssId, struct UserVar *pVar)
{
# line 33 "../version.st"
	seq_delayInit(ssId, 0, (1));
}

/* Event function for state "x" in state set "x" */
static seqBool E_x_0_x(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 33 "../version.st"
	if (seq_delay(ssId, 0))
	{
		seq_exit(ssId);
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "x" in state set "x" */
static void A_x_0_x(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 33 "../version.st"
			exit(0);
		}
		return;
	}
}

/************************ Tables ************************/

/* No channel definitions */
#define G_channels NULL

/* Event masks for state set "x" */
static const seqMask	EM_x_0_x[] = {
	0x00000000,
};

/* State table for state set "x" */
static seqState G_x_states[] = {
	{
	/* state name */        "x",
	/* action function */   A_x_0_x,
	/* event function */    E_x_0_x,
	/* delay function */    D_x_0_x,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_x_0_x,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "x",
	/* states */            G_x_states,
	/* number of states */  1,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram versionTest = {
	/* magic number */      2001021,
	/* program name */      "versionTest",
	/* channels */          G_channels,
	/* num. channels */     0,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        G_prog_entry,
	/* exit func */         NULL,
	/* num. queues */       0
};

#define PROG_NAME versionTest
#include "seqMain.c"
