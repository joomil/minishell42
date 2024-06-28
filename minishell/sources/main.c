/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 08:17:26 by jmilesi           #+#    #+#             */
/*   Updated: 2024/04/08 08:17:28 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	start_check(t_data *data, int ac)
{
	if (ac != 1)
		return (usage_message(false));
	else
		data->interactive = true;
	return (true);
}

void	minishell_interactive(t_data *data)
{
	while (1)
	{
		set_signals_interactive();
		data->user_input = readline(PROMPT);
		if (parse_user_input(data) == true)
			g_last_exit_code = execute(data);
		else
			g_last_exit_code = 1;
		free_data(data, false);
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)	**av;
	//display();
	ft_memset(&data, 0, sizeof(t_data));
	if (!start_check(&data, ac) || !init_data(&data, env))
		exit_shell(NULL, EXIT_FAILURE);
	if (data.interactive)
		minishell_interactive(&data);
	else
		ft_putendl_fd("Usage: ./minishell", 2);
	exit_shell(&data, g_last_exit_code);
	return (0);
}
