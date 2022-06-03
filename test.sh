# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 17:31:18 by jiglesia          #+#    #+#              #
#    Updated: 2022/06/03 17:36:29 by jiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo "std containers: ";time ./std_containers> std_output; echo "ft containers: "; time ./ft_containers > ft_output;echo "difference: "; diff std_output ft_output
