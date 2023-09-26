# include "../../includes/minishell.h"

/*DESCRIPTION DE LA FONCTION*/
void	interruption_handler(int signum)
{

}

/*If the SIGINT signal (Ctrl+C) is pressed, the interruption_handler
takes care of it. 
If the SIGQUIT signal (Ctrl+\) is pressed, nothing happens (it is
ignored).*/
void	signals(void)
{
	//SIGINT: Ctrl+C, à faire par Élodie
	signal(SIGINT, interruption_handler);

	//ÉLODIE TU PEUX SUPPRIMER LES NOTES JE VOULAIS JUSTE TE PARTAGER
	//CE QUE J'AI TROUVÉ, JE SUIS PAS MAL CERTAINE QUE SIGQUIT C'EST
	//CTRL-\ REGARDE:

	//SIGQUIT: The SIGQUIT signal is similar to SIGINT,
	//except that it’s controlled by a different key—
	//the QUIT character, usually C-\—and produces a core dump 
	//when it terminates the process, just like a program error
	//signal. You can think of this as a program error condition 
	//“detected” by the user.

	//AUSSI POUR SIG_IGN J'AI TROUVÉ ÇA: SIG_IGN specifies 
	//that the signal should be ignored.

	//Donc la formulation ci-bas devrait être OK pour gérer 
	//CTRL-\

	signal(SIGQUIT, SIG_IGN);
}
