/*
 * lwct.h, v.3.0.3
 *
 * Lightweight C Test Library
 */

#ifndef LWCT_H
#define LWCT_H

#include "lwct_conf.h"

/*
 * Macros for assertion and log display
 * @S		test environment state
 * @bool	boolean sentence
 */
#define lwct_fatal_assert(S, bool) \
	_lwct_fatal_assert(S, bool, #bool, __FILE__, __func__, __LINE__)

#define lwct_assert(S, bool) \
	_lwct_assert(S, bool, #bool, __FILE__, __func__, __LINE__)

/*
 * Testing environment state
 */
typedef struct lwct_state lwct_state;

/*
 * Functions for test submission work much like observers,
 * and receive the following informations:
 * @S		test environment state
 * @repetition	index of repetition [1 to repetition_cnt]
 */
LWCTL_API void lwct_submit_test(void (*func)(lwct_state *S));

LWCTL_API void lwct_submit_batch(void (*func)(lwct_state *S,
				unsigned long repetition),
				unsigned long repetition_cnt);

/*
 * Deconstructor submition - will called the deconstructor function parsing
 * the reference to data whenever a fatal assert catches a false assertion
 * @S			test environment state
 * @deconstructor	deconstructor function
 * @pdata		reference to data
 */
LWCTL_API void lwct_submit_desconstructor(lwct_state *S,
				void (*deconstructor)(void *p), void *pdata);

/*
 * Functions for assertion and log display
 * There is no point in calling these directly.
 * Use the lwct_assert and lwct_fatal_assert macros.
 */
LWCTL_API void _lwct_fatal_assert(lwct_state *S, const char bool,
			const char *label, const char *file,
			const char *func, const unsigned int line);

LWCTL_API void _lwct_assert(lwct_state *S, const char bool,
			const char *label, const char *file,
			const char *func, const unsigned int line);

#endif
