//   By: Evelina-Svitlana Protsenko 

#include "../include/minihell.h"

// writes a custom error message consisting of start-name-end, and sets
// global exit to g_e
void	named_err(const char *start, const char *name,
	const char *end, int g_e)
{
	char	*msg;

	set_g_last_exit(g_e);
	if (name == NULL)
		return ;
	msg = mystrdup((char *) name);
	if (start != NULL)
		msg = mystrjoin(start, msg);
	if (end != NULL)
		msg = mystrjoin(msg, end);
	write(STDERR_FILENO, msg, mystrlen(msg));
	write(STDERR_FILENO, "\n", 1);
}

int	update_g_last_exit(t_shell *info)
{
	hfree(info->g_last_exit_str);
	info->g_last_exit_str = myitoa(get_g_last_exit());
	if (!info->g_last_exit_str)
		return (shell_err(1, "Error: update_g_last_exit()", 1, 0));
	return (EXIT_SUCCESS);
}

char	*strjoin_with_delimeter(const char *s1, const char *s2, char d)
{
	const int	size = mystrlen(s1) + mystrlen(s2) + 2;
	char		*res;
	int			i;

	res = (char *)hmalloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		res[i++] = *s1++;
	res[i++] = d;
	while (s2 && *s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

// turns every wildcard (*) that is in quotes or doubles quotes into a
// char with value -42
int	wc_to_42(char **str)
{
	int	i;
	int	single_q;
	int	double_q;

	i = 0;
	single_q = 0;
	double_q = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\'')
			single_q = !single_q;
		else if ((*str)[i] == '\"')
			double_q = !double_q;
		else if ((*str)[i] == '*' && (single_q || double_q))
			(*str)[i] = -42;
		++i;
	}
	return (0);
}
