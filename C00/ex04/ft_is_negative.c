# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 08:47:26 by eukwon            #+#    #+#              #
/*   Updated: 2022/01/07 17:18:54 by eukwon           ###   ########.fr       */
#                                                                              #
# **************************************************************************** #

#include <unistd.h>

void	ft_is_negative(int n);

int	main()
{
	ft_is_negative(-3);
}

void	ft_is_nagative(int n)
{
	if (n < 0) {
		write(1, "N", 1);
	}
	else {
		write(1, "P", 1);
	}
}
