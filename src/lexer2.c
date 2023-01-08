//   By: Evelina-Svitlana Protsenko 

#include "../include/minihell.h"

static t_ul	quotes_last_idx(char *line, char c)
{
	t_ul	i;

	i = 1;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		++i;
	}
	return (EXIT_SUCCESS);
}

//
//for ' "
//add_node(tokens, &LEX_KEY_SING_Q, mysubstr(str, i + 1, *t - 1))
//tokens stored in main()
//
int	lex_quotes(t_lst *tokens, char *line, t_ul i, t_ul *t)
{
	char			*sstr;
	void			*token_key;

	*t = quotes_last_idx(line + i, line[i]);
	if (!(*t))
		return (*t);
	sstr = mysubstr(line, i + 1, *t - 1);
	if (!sstr)
		return (EXIT_FAILURE);
	token_key = (int *)LEX_KEY_DOUB_Q;
	if (line[i] == '\'')
		token_key = (int *)LEX_KEY_SING_Q;
	if (add_node(tokens, token_key, sstr))
	{
		hfree(sstr);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//
//for word
//add_node(tokens, (void *)LEX_KEY_WORD, mysubstr(str, i, *t))
//tokens stored in main()
//
int	lex_word(t_lst *tokens, char *line, t_ul i, t_ul *t)
{
	char			*sstr;

	*t = 0;
	while (line[i + *t] && !myisspace(line[i + *t])
		&& !is_special_char(line[i + *t]) && line[i + *t] != '\''
		&& line[i + *t] != '\"')
		++(*t);
	sstr = mysubstr(line, i, *t);
	if (!sstr)
		return (EXIT_FAILURE);
	if (add_node(tokens, (void *)LEX_KEY_WORD, sstr))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
