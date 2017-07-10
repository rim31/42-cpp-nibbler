#include "GraphicsHandler.hpp"

IGraphics	*GraphicsHandler::guiInst = NULL;

GraphicsHandler::GraphicsHandler(void)
{
	return ;
}

GraphicsHandler::GraphicsHandler(GraphicsHandler const & src)
{
	*this = src;
	return ;
}

GraphicsHandler::~GraphicsHandler(void)
{
	_uninstantiate(GraphicsHandler::guiInst);
	dlclose(_handler);
	return ;
}

GraphicsHandler & GraphicsHandler::operator=(GraphicsHandler const & rhs)
{
	(void)rhs;
	return *this;
}

void	GraphicsHandler::dlerror_wrapper(void)
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

void	GraphicsHandler::loadLibrary(std::string libName, int width, int height)
{
	_handler = dlopen(libName.c_str(), RTLD_LAZY | RTLD_LOCAL);

	if (!_handler)
		dlerror_wrapper();

	_uninstantiate = reinterpret_cast<t_sym_uninstantiate>(loadSymbol("glibUninstantiate"));
	t_sym_instantiate	instantiate = reinterpret_cast<t_sym_instantiate>(loadSymbol("glibInstantiate"));

	GraphicsHandler::guiInst = instantiate(width, height);
}

void	*GraphicsHandler::loadSymbol(const std::string symbolName)
{
	return dlsym(_handler, symbolName.c_str());
}
