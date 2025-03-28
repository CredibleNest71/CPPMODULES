/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:05:18 by mresch            #+#    #+#             */
/*   Updated: 2025/03/28 11:09:44 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PM_HPP
# define PM_HPP
 
# include <iostream>
# include <vector>
# include <string>
# include <deque>
# include <algorithm>
# include <stdexcept>

class PM {
public:
    // Canonical form
    PM();
    PM(const PM& other);
    ~PM();
    PM& operator=(const PM& other);

private:
    std::vector<int> _v;
    std::deque<int> _d;
};

#endif 