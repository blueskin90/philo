/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:50:21 by toliver           #+#    #+#             */
/*   Updated: 2017/11/08 15:20:17 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_striter(char *s, void (*f)(char*))
{
	unsigned int	i;

	i = -1;
	if (f && s)
		while (s[++i])
			(*f)(s + i);
}