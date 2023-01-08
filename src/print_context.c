//   By: Evelina-Svitlana Protsenko 

#include "../include/minihell.h"
#include "../include/executor.h"

 /*
//
//args are group split into subgroups by pipes 
//
//why introduce args that constitute cmds in texecgroup?
//we need separate exec routine for pipes CMD_TYPE_PIPE
//args are subgroups of group. they divide group by pipes
//
void print_tlst_args(t_exec_group *cmds)
{
	return ;
	t_key_val_lst *cmds_ptr = cmds->cmds->head;
	t_key_val_lst *args_ptr ;
	//t_cmd_info	*info = (t_cmd_info *)
	((t_key_val_lst *)(cmds_ptr->next))->val;
	t_cmd_info	*info = (t_cmd_info *) cmds_ptr->val;
	printf("IHAVEIHAVEIHAVE A %p\n%s\n%s\n%s\n%i\n%i\n", info,
		info->file_in,
		info->file_out,
		info->delimiter,
		info->type,
		info->subsh_lvl);
	int i  = 0, j = 0;
	while (cmds_ptr)
	{
		i = 0;
		printf("cmds [%d] args:\n", j);
		args_ptr = ((t_lst *)(cmds_ptr->key))->head;
		while (args_ptr)
		{
			printf("args[%d]: key - %d\nval - %s\n",i,
			*(int *)&(args_ptr->key), (char *)(args_ptr)->val);
			i++;
			args_ptr = args_ptr->next;
		}
		j++;
		cmds_ptr = cmds_ptr->next;
	}
	printf("executor(cmds, info) can \
	rotate through the printed args in cmds\n");
	
}

//
//why introduce groups?
//because we need separate execute routines for pipes, subshells and log op
//type(of groups) - CMD_TYPE_BI_BIN	CMD_TYPE_PIPE CMD_TYPE_SUBSH	
//group is tokens that have to be executed in 
//a subshell, pipe or are a part of logical expression
//group is tokens from t_lst tokens without separators until && ||
//if && || are inside subshell () we write them as part of the group 
//groups are not split by pipes they only 
//mention CMD_TYPE_PIPE in group type if there are any
//
void print_exec_groups_key_value_pair(t_key_val_lst *groups_head, int i)
{
	return ;
	printf("\ngroups_key_value_pair[%d]:\nkey:	", i);
	if (*(int *)&(groups_head)->key
	& CMD_TYPE_PIPE) printf("CMD_TYPE_PIPE	");
	if (*(int *)&(groups_head)->key
	& CMD_TYPE_SUBSH) printf("CMD_TYPE_SUBSH	");
	if (*(int *)&(groups_head)->key
	& CMD_TYPE_BI_BIN) printf("CMD_TYPE_BI_BIN	");
	if (*(int *)&(groups_head)->key
	== LEX_KEY_AND) printf("this group is && between groups\n");
	if (*(int *)&(groups_head)->key
	== LEX_KEY_OR) printf("this group is || between groups\n");
	printf("\nvalue:\n");	
	
	t_lst *group = (t_lst *)(groups_head->val);
	if (group)
	{
		int j = 0;
		t_key_val_lst *group_head = group->head;
		
		while (group_head)
		{
			printf("				group_key_value_pair[%d]\n", j);
			printf("key: LEX_KEY_* %d		",*(int *)&(group_head->key));
			printf("val: %s\n", (char *)(group_head)->val);
			group_head = group_head->next;
			j++;
		}
	}
	else printf("NULL\n");	
	printf("\n\n	//////%d///End of groups_key_value_pair[%d]!\n", i, i);
	printf("	execute_texeconegr() was called for\
	the %d time for current tlst groups\n\n\n", i + 1);

}
 */