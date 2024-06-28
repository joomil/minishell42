/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:31:10 by cspreafi          #+#    #+#             */
/*   Updated: 2024/04/10 12:31:12 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_char(char str)
{
	if (str >= 33 && str <= 126)
		return (1);
	else
		return (0);
}

int	is_special(char curr)
{
	if (curr == '|')
		return (1);
	if (curr == '>')
		return (1);
	if (curr == '<')
		return (1);
	if (curr == ';')
		return (1);
	if (curr == '&' )
		return (1);
	return (0);
}

int	skip_whitespace(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}
