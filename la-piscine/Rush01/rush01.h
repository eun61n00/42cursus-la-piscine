/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjch <youngjch@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:14:24 by youngjch          #+#    #+#             */
/*   Updated: 2022/01/16 17:14:26 by youngjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

int		check_fixed(int (*return_map)[4], int input_index);
void	del_fix_r_b(int (*return_map)[4], int target_number, int input_index);
void	del_fix_r_f(int (*return_map)[4], int target_number, int input_index);
void	del_fix_c_u(int (*return_map)[4], int target_number, int input_index);
void	del_fix_c_d(int (*return_map)[4], int target_number, int input_index);
void	del_val(int (*return_map)[4], int input_val, int dst, int input_index);
void	sol_r(int (*return_map)[4], int input_values[], int input_index, int N);
void	sol_c(int (*return_map)[4], int input_values[], int input_index, int N);
int		rush(int input_values[], int (*return_map)[4], int N);
void	all_check(int (*return_map)[4]);

#endif
