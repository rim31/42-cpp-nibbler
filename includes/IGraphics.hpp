#ifndef IGRAPHICS_HPP
# define IGRAPHICS_HPP
# define HEIGHT 40
# define WIDTH 100

# include <list>

typedef enum		e_blocks
{
	BLKNONE,
	WALL,
	HEAD,
	BODY,
	FRUIT
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
	QUIT
}					t_action;

class IGraphics
{
public:
	t_action	glib_action;
	std::list<std::list<t_blocks>>	map;

	virtual	~IGraphics(void) = default;
	virtual void	update(void) = 0;
};

#endif
