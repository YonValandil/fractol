/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 02:41:17 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/19 02:51:11 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t' ||
		c == '\f' || c == '\v')
		return (1);
	return (0);
}
