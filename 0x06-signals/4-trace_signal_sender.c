#include "signals.h"

/**
 * handler-handler
 * @sig:sigint
 * @info:sig info
 * @ucontext:act
 */
void handler(int sig, siginfo_t *info, void *ucontext)
{
	pid_t pid;

	(void)(sig);
	(void)(ucontext);
	pid = info->si_pid;
	printf("SIGQUIT sent by %d\n", pid);
}

/**
 * trace_signal_sender-finds origin of quit signal
 * Return:0/-1
 */
int trace_signal_sender(void)
{
	struct sigaction sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;

	return (sigaction(SIGQUIT, &sig, NULL));
}
