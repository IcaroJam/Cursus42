#include <stdlib.h>
#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*window;

	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 800, 800, "Hey");
	mlx_loop(mlx_ptr);
}
