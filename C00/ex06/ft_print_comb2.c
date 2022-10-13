/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2_.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:16:01 by eukwon            #+#    #+#             */
/*   Updated: 2022/01/08 16:03:15 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(void){
    char comb[5];
    int final;

    comb[2] = ' ';
    final = 1;
    while (final <= 9899)
    {
        comb[0] = final / 1000 + '0';
        comb[1] = final / 100 % 10 + '0';
        comb[3] = final / 10 % 10 + '0';
        comb[4] = final  % 10 + '0';
        if (comb[0]*10+comb[1] < comb[3]*10+comb[4])
        {
            write(1, comb, 5);
            if (final != 9899)
            {
            write(1, ", ", 2);
            }
        }
        final++;
    }
}
