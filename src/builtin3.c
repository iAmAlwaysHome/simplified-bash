//   By: Arthur Prahin 

#include "../include/minihell.h"
#include "../include/executor.h"

// Checks if the "KEY=value" is valid
static int	check_var(char *var)
{
	int	i;

	if (var[0] == '=' || myisdigit(var[0]))
		return (0);
	i = -1;
	while (var[++i] != '\0' && var[i] != '=')
	{
		if (!myisalnum(var[i]) && var[i] != '_')
		{
			if (var[i] == '+' && var[i + 1] == '=')
				continue ;
			else
				return (0);
		}
	}
	return (1);
}

// Checks if the key is already defined for +=. If so, appends its value.
static int	replace_var_append(char *value, t_shell *info)
{
	t_key_val_lst	*envp;
	int				end;

	end = -1;
	while (value[++end] != '+' && value[end] != '\0')
		;
	if (value[end] != '+' || value[end + 1] != '=')
		return (0);
	envp = info->envp_state->head;
	while (envp)
	{
		if (mystrncmp(envp->key, value, end) == 0
			&& ((char *)(envp->key))[end] == '\0' && value[end] == '+')
		{
			if (value[end + 1] == '=' && value[end + 2] != '\0' && envp->val)
				envp->val = mystrjoin(envp->val, mystrdup(value + end + 2));
			else if (value[end + 1] == '=' && value[end + 2] != '\0')
				envp->val = mystrdup(value + end + 2);
			return (1);
		}
		envp = envp->next;
	}
	return (0);
}

// Checks if the key is already defined. If so, replaces its value
static int	replace_var(char *value, t_shell *info)
{
	t_key_val_lst	*envp;
	int				end;

	if (replace_var_append(value, info))
		return (1);
	end = -1;
	while (value[++end] != '=' && value[end] != '\0')
		;
	envp = info->envp_state->head;
	while (envp)
	{
		if (mystrncmp(envp->key, value, end) == 0
			&& ((char *)(envp->key))[end] == '\0' && value[end] == '=')
		{
			if (value[end + 1] != '\0')
				envp->val = mystrdup(value + end + 1);
			else
				envp->val = mystrdup("");
			return (1);
		}
		envp = envp->next;
	}
	return (0);
}

// Export a variable (c.f. export with n arguments)
static int	set_var(char *value, t_shell *info)
{
	char			*new_key;
	char			*new_val;
	int				i;

	if (check_var(value) == 0)
		return (named_err(ERR_EXP_ID1, value, ERR_EXP_ID2, 1), 1);
	else if (replace_var(value, info))
		return (0);
	i = -1;
	new_val = NULL;
	while (value[++i] != '=' && value[i] != '\0')
		;
	new_key = hmalloc((i + 1 - (value[i - 1] == '+')) * sizeof(char));
	mystrlcpy(new_key, value, i + 1 - (value[i - 1] == '+'));
	if (value[i] != '\0' && value[i + 1] != '\0')
	{
		new_val = hmalloc((mystrlen(value) - i) * sizeof(char));
		mystrlcpy(new_val, value + i + 1, mystrlen(value + i + 1) + 1);
	}
	else if (value[i] != '\0')
		new_val = mystrdup("");
	add_node(info->envp_state, new_key, new_val);
	return (0);
}

int	builtin_export(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd)
{
	t_key_val_lst	*arg_ptr;
	int				ret;

	arg_ptr = get_arg_ptr(cmd_ptr)->next;
	ret = 0;
	if (get_argc(cmd_ptr) == 1)
		return (print_export(info, out_fd));
	else
	{
		while (arg_ptr)
		{
			ret |= set_var(arg_ptr->val, info);
			arg_ptr = arg_ptr->next;
		}	
	}
	return (ret);
}
