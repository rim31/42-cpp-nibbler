/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:55:34 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/11 14:55:34 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_HPP
# define GRAPHICS_HPP

#include <curses.h>
# include "IGraphics.hpp"

class Graphics : public IGraphics
{
private:
	WINDOW *_win;

public:
	Graphics(void);
	Graphics(int w, int h);
	Graphics(Graphics const &);
	virtual	~Graphics(void);

	void	handleEvents(void);
	void	drawMap(void);
	void	update(void);

	Graphics & operator=(Graphics const &);
};

extern "C"
{
	Graphics	*glibInstantiate(int w, int h);
	void		glibUninstantiate(IGraphics * g);
}

#endif
