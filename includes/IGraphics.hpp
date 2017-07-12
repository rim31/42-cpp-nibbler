/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphics.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:55:46 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/12 14:50:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGRAPHICS_HPP
# define IGRAPHICS_HPP

# include <list>

typedef enum		e_blocks
{
	BLKNONE,
	WALL,
	HEAD,
	BODY,
	FRUIT,
	EXPLOSION,
	EXPLOSION2,	
}					t_blocks;

typedef enum		e_action
{
	NONE,
	LIB1,
	LIB2,
	LIB3,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	QUIT,
	PAUSE
}					t_action;

class IGraphics
{
public:
	t_action	glib_action;
	std::list<std::list<t_blocks>>	map;

	virtual	~IGraphics(void) = default;
	virtual void	handleEvents(void) = 0;
	virtual void	drawMap(void) = 0;
	virtual void	update(void) = 0;
};

#endif
