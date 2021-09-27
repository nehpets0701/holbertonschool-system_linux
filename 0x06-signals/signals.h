#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int handle_signal(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);

void event(int);

#endif