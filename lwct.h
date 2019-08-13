
  // Lightweight C test module interface
  // This file is under the GPL-3.0 licence
  // Read the LICENSE file for the full text
  // Guilherme Dantas

  #ifndef LWCT_H
  #define LWCT_H

  #include "lwct_colours.h"

  // Aborts test, displaying the statement that caused it and line,
  // and, additionally, shows log.
  // boolean - if false, error is thrown
  // label - statement string
  // line - statement line in code
  // > (to stderr) error message + test log, nothing
  // [!] if boolean is false, the program is exited.
  #define fatal_assert(statement); abort_test(statement,#statement,__LINE__);
  void abort_test (const char boolean, const char * label, const line);

  // Asserts statement, displaying it and the line it's at if false
  // boolean - if false, error is thrown
  // label - statement string
  // line - statement line in code
  // > (to stderr) error message, nothing
  #define assert(statement); assertcolor(statement,#statement,__LINE__);
  void assertcolor (const char boolean, const char * label, const line);

  // Ouputs information stored in counters at a given time
  // > (to stdout) test log
  void show_log ();

  #endif