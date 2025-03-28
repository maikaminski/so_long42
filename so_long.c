#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void key_hook(mlx_key_data_t keydata, void *mlx)
{
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        mlx_terminate(mlx);
        exit(EXIT_SUCCESS);
    }
}

int main(void)
{
    mlx_t *mlx = mlx_init(800, 600, "so_long", true);
    if (!mlx)
    {
        fprintf(stderr, "Erro ao iniciar MLX42\n");
        return EXIT_FAILURE;
    }

    // Hook para capturar teclas
    mlx_key_hook(mlx, key_hook, mlx);

    // Mantém a janela aberta
    mlx_loop(mlx);

    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}