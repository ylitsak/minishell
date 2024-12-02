/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:38:41 by saylital          #+#    #+#             */
/*   Updated: 2024/05/08 11:30:45 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int n)
{
	if (n > 255)
		return (0);
	if (((unsigned char)n >= 48 && (unsigned char)n <= 57)
		|| ((unsigned char)n >= 65 && (unsigned char)n <= 90)
		|| ((unsigned char)n >= 97 && (unsigned char)n <= 122))
	{
		return (1);
	}
	return (0);
}
