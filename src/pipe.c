//   By: Arthur Prahin 

#include "../include/minihell.h"
#include "../include/executor.h"

int	pipe_binary(t_key_val_lst *cmd_ptr, t_shell *info)
{
	t_key_val_lst	*envp;
	char			*filepath;
	char			*path;
	char			**args;

	path = NULL;
	envp = info->envp_state->head;
	while (envp)
	{
		if (mystrncmp("PATH", envp->key, 5) == 0)
		{
			path = mystrdup(envp->val);
			break ;
		}
		envp = envp->next;
	}
	if (access_cmd_file(cmd_ptr, path, &filepath) != 0)
		return (hobliterate(), exit(get_g_last_exit()), 1);
	if (make_execve_argv(cmd_ptr, &args, filepath) != EXIT_SUCCESS)
		return (hobliterate(), exit(EXIT_FAILURE), 1);
	if (info->update_envp)
		update_tshell_envp(info);
	execve(filepath, args, info->envp);
	shell_err(-1, "pipe_binary(): execve failed", 0, 1);
	return (exit(127), 1);
}

static pid_t	fork_pipe2(t_key_val_lst *cmd_ptr, t_shell *info, int *pipes)
{
	int	exit_val;

	if (((t_cmd_info *)cmd_ptr->val)->type & CMD_TO_SUBSH)
	{
		close_pipes(pipes);
		execute_subshell(cmd_ptr, info);
	}
	else if (is_builtin(cmd_ptr, info) < 7)
	{
		myputstr_fd((char *)cmd_ptr->val, 2);
		exit_val = (*(info->built_in_f)[is_builtin(cmd_ptr, info)])
			(cmd_ptr, info, *(pipes + 1));
		close_pipes(pipes);
		hobliterate();
		exit(exit_val);
	}
	else
	{
		close_pipes(pipes);
		pipe_binary(cmd_ptr, info);
	}
	return (-1);
}

pid_t	fork_pipe(t_key_val_lst *cmd_ptr, t_shell *info, int *pipes)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (shell_err(-1, "fork_pipe(): failed to fork", 0, 1));
	else if (pid != 0)
		return (pid);
	signal(SIGQUIT, SIG_DFL);
	if (dup_open_files(cmd_ptr->val, pipes) != 0)
		return (1);
	return (fork_pipe2(cmd_ptr, info, pipes));
}

// execute every command with pipes in-between
// waits until last pid
// returns last command pid
pid_t	execute_pipe(t_exec_group *cmds, t_shell *info)
{
	int				*pipes;
	pid_t			*pids;
	t_ui			i;
	t_ui			j;
	t_key_val_lst	*cmd_ptr;

	cmd_ptr = cmds->cmds->head;
	pipes = open_pipes(cmds);
	pids = mycalloc(cmds->cmds->size, sizeof(pid_t));
	if (pids == NULL)
		return (shell_err(-1, "execute_pipe(): mycalloc failed", 1, 0));
	i = 0;
	while (cmd_ptr)
	{
		if (access_files(cmd_ptr->val) == 0)
			pids[i] = fork_pipe(cmd_ptr, info, pipes);
		i++;
		pipes += 2;
		cmd_ptr = cmd_ptr->next;
	}
	j = 0;
	close_pipes(pipes - 2);
	while (j < i - 1)
		waitpid(pids[j++], NULL, 0);
	return (pids[j]);
}
