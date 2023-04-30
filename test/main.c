#include "mlx.h"
#include <stdlib.h>

typedef struct s_point
{
    int x;
    int y;
}   t_point;

void draw_line(t_point p1, t_point p2, void **mlx_ptr, void **win_ptr)
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.x;
    int len = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_inc = (float)dx / (float)len;
    float y_inc = (float)dy / (float)len;

    float   x = p1.x;
    float   y = p1.y;

    int i = 0;

    while (i < len)
    {
        x += x_inc;
        y += y_inc;
        mlx_pixel_put((*mlx_ptr), (*win_ptr), x, y, 0xFFFFFF);
        i++;
    }
    
    
}

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;

    t_point p1, p2;

    p1.x = 0;
    p1.y = 0;
    p2.x = 800;
    p2.y = 600;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "DDA Line Drawing");
    draw_line(p1, p2, &mlx_ptr, &win_ptr);
    mlx_loop(mlx_ptr);
    return 0;
}
