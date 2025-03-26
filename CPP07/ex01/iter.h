/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:47:50 by mresch            #+#    #+#             */
/*   Updated: 2025/01/20 16:29:19 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H
# include <iostream>
# include <cstring>

template<typename T, typename F>
void    iter(T *address, size_t idx, void (*func)(T));

#endif
