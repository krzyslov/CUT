#ifndef SIGTERM_H_INCLUDE
#define SIGTERM_H_INCLUDE

#include <signal.h>
#include <unistd.h>
#include "string.h"

extern volatile sig_atomic_t end_signal;

void term(int signum);
void * term_after3sec();
void set_SIGTERM();

#endif