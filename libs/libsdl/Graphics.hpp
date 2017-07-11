/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:28:43 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/11 14:31:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_HPP
# define GRAPHICS_HPP

#include "SDL.h"
# include "IGraphics.hpp"

# define REALHEIGHTMULT 15
# define REALWIDTHMULT 10

class Graphics : public IGraphics
{
private:
	SDL_Window		*_win;
	SDL_Renderer	*_renderer;
	SDL_Event		_event;

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
