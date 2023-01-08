//   By: Arthur Prahin 

#include "../include/minihell.h"
#include "../include/executor.h"

// return arg_ptr
t_key_val_lst	*get_arg_ptr(t_key_val_lst *cmd_ptr)
{
	return (((t_lst *)(cmd_ptr->key))->head);
}

// return how many args are in arg_ptr
int	get_argc(t_key_val_lst *cmd_ptr)
{
	t_key_val_lst	*arg_ptr;
	int				ret;

	arg_ptr = get_arg_ptr(cmd_ptr);
	ret = 0;
	while (arg_ptr)
	{
		ret++;
		arg_ptr = arg_ptr->next;
	}
	return (ret);
}

// Gets next alphabetically smallest key but bigger than last_ptr->key
static t_key_val_lst	*get_min_envp(t_shell *info, t_key_val_lst *last_ptr)
{
	t_key_val_lst	*envp;
	t_key_val_lst	*iter;

	envp = info->envp_state->head;
	while (envp && last_ptr)
	{
		if (mystrncmp(envp->key, last_ptr->key, mystrlen(envp->key) + 1) > 0)
			break ;
		envp = envp->next;
	}
	if (envp == NULL && last_ptr != NULL)
		return (NULL);
	else if (last_ptr == NULL)
		envp = info->envp_state->head;
	iter = envp->next;
	while (iter)
	{
		if (mystrncmp(envp->key, iter->key, mystrlen(envp->key) + 1) > 0
			&& (last_ptr == NULL || mystrncmp(iter->key,
					last_ptr->key, mystrlen(iter->key) + 1) > 0))
			envp = iter;
		iter = iter->next;
	}
	return (envp);
}

// Displays environment (c.f. export w/o any argument)
int	print_export(t_shell *info, int out_fd)
{
	t_key_val_lst	*envp;

	envp = NULL;
	while (1)
	{
		envp = get_min_envp(info, envp);
		if (envp == NULL)
			break ;
		if (write(out_fd, "declare -x ", 11) < 0)
			return (shell_err(1, ERR_EXP_WR, 0, 1));
		myputstr_fd(envp->key, out_fd);
		if (envp->val)
		{
			myputstr_fd("=\"", out_fd);
			myputstr_fd(envp->val, out_fd);
			myputstr_fd("\"", out_fd);
		}
		myputstr_fd("\n", out_fd);
	}
	close(out_fd);
	return (0);
}
