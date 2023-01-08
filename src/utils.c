//   By: Evelina-Svitlana Protsenko 

#include "../include/minihell.h" 

int	shell_err(int ret, const char *msg, char liberr, int g_e)
{
	if (msg && *msg && !liberr)
	{
		write(STDERR_FILENO, msg, mystrlen(msg));
		write(STDERR_FILENO, "\n", 1);
		set_g_last_exit(g_e);
		return (ret);
	}
	if (errno && liberr)
	{
		if (msg && *msg)
			perror(msg);
		else
			perror("Error: ");
		set_g_last_exit(1);
	}
	return (ret);
}

char	**hmalloc2darr_upto_idx(int m, int n)
{
	int		i;
	char	**arr;

	if (!m || !n)
		return (NULL);
	arr = (char **)hmalloc(sizeof(char *) * m);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < m)
	{
		arr[i] = (char *)hmalloc(sizeof(char *) * n);
		if (!arr[i])
			return (hfree2darr_upto_idx(arr, i));
	}
	return (arr);
}

void	*hfree2darr_upto_idx(char **arr, int m)
{
	int		i;

	if (!arr)
		return (NULL);
	i = 0;
	if (m == -1)
	{
		while (arr[i])
			hfree(arr[i++]);
		hfree(arr);
		return (NULL);
	}
	while (i < m)
		hfree(arr[i++]);
	hfree(arr);
	return (NULL);
}

char	*myuitoa(t_ui n)
{
	char			*s;
	t_ui			cnt;
	t_ui			i;

	cnt = 0;
	i = n;
	while (i)
	{
		++cnt;
		i /= 10;
	}
	if (!cnt)
		cnt = 1;
	s = (char *)hmalloc(sizeof(char) * (cnt + 1));
	if (!s)
		return (NULL);
	s[cnt] = '\0';
	while (cnt--)
	{
		s[cnt] = '0' + n % 10;
		n /= 10;
	}
	return (s);
}

int	myisspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\v' || c == '\f');
}
