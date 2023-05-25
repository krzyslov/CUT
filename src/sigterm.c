#include "sigterm.h"

volatile sig_atomic_t end_signal = 0;

void term(int signum) 
{ 
    end_signal = 1; 
}

void *term_after3sec()
{
    sleep(3);
    end_signal = 1;
    return NULL;
}

void set_SIGTERM()
{
    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_handler = term;
    sigaction(SIGTERM, &action, NULL);
}