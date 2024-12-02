/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:26:54 by saylital          #+#    #+#             */
/*   Updated: 2024/05/08 11:24:40 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c > 255)
		return (0);
	if (((unsigned char)c >= 65 && (unsigned char)c <= 90)
		|| ((unsigned char)c >= 97 && (unsigned char)c <= 122))
	{
		return (1);
	}
	return (0);
}
