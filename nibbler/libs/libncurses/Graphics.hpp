#ifndef GRAPHICS_HPP
# define GRAPHICS_HPP

#include <curses.h>
# include "IGraphics.hpp"

class Graphics : public IGraphics
{
private:
	WINDOW *_win;

	void	handleInput(void);
	void	drawMap(void);

public:
	Graphics(void);
	Graphics(Graphics const &);
	virtual	~Graphics(void);

	void	update(void);

	Graphics & operator=(Graphics const &);
};

extern "C"
{
	Graphics	*glibInstantiate();
	void		glibUninstantiate(IGraphics * g);
}

#endif