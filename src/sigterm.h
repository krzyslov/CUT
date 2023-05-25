#ifndef SIGTERM_H_INCLUDE
#define SIGTERM_H_INCLUDE

#include <signal.h>
#include <unistd.h>
#include "string.h"

extern volatile sig_atomic_t end_signal;

void term();
void * term_after3sec();
void set_SIGTERM();
void set_SIGINT();

#endif