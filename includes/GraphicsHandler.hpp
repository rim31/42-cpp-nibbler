/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsHandler.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:55:43 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/11 14:55:44 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICSHANDLER_HPP
# define GRAPHICSHANDLER_HPP

#include <string>
#include <dlfcn.h>
#include <iostream>
#include <cstdlib>
#include "IGraphics.hpp"

typedef IGraphics	*(*t_sym_instantiate)(int, int);
typedef void		(*t_sym_uninstantiate)(IGraphics *);

class GraphicsHandler
{
public:
	GraphicsHandler(void);
	GraphicsHandler(GraphicsHandler const &);
	virtual	~GraphicsHandler(void);

	static IGraphics	*guiInst;

	void	dlerror_wrapper(void);
	void	loadLibrary(std::string libName, int width, int height);
	void	*loadSymbol(const std::string);

	GraphicsHandler & operator=(GraphicsHandler const &);

private:
	t_sym_uninstantiate	_uninstantiate;
	void	*_handler;
};

#endif
