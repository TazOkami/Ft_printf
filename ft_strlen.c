/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 01:36:03 by  jpaulis          #+#    #+#             */
/*   Updated: 2024/10/31 16:23:36 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strlen - Calcule la longueur 
 * de la chaîne de caractères c 
 * (ne compte pas le caractère nul '\0')
 * Retourne la longueur de la chaîne de caractères
 */
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
#include <stdio.h>

int main(void)
{
	char str[] = "Hello, world!";
	int len = ft_strlen(str);

	printf("Length: %d\n", len);

	return 0;
}
*/
