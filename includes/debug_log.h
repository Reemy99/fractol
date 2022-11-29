/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_log.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:55:58 by msaleh            #+#    #+#             */
/*   Updated: 2022/11/17 17:56:01 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_LOG_H
# define DEBUG_LOG_H

# define ERR_APP_INIT	    "ERROR: Can\'t initialize app"
# define ERR_FRACTOL_INIT	"ERROR: Can\'t initialize fractol"
# define ERR_WINDOW_INIT	"ERROR: Can\'t initialize window"
# define ERR_IMAGE_INIT		"ERROR: Can\'t initialize image"
# define ERR_FRACTAL_NAME	"ERROR: Argument name invalid"

void	debug_log(char *log);
void	print_help(void);

#endif