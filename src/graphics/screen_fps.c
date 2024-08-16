
#include "graphics.h"

static void	fps_to_str(char *str, int num);

bool	init_fps_images(t_gfx_data *graphics)
{
	char	fps_str[7];
	int		i;

	i = 0;
	while (i <= MAX_SCREEN_FPS)
	{
		fps_to_str(fps_str, i);
		graphics->fps_on_screen[i] = mlx_put_string(graphics->mlx, fps_str, 5, 5);
		if (!graphics->fps_on_screen[i])
			return (false);
		graphics->fps_on_screen[i]->enabled = false;
		i++;
	}
	return (true);
}

void	fps_to_screen(t_gfx_data *graphics, t_fps *fps)
{
	const int	current_fps = (int)(1.0 / (fps->time - fps->old_time));
	static int	last_fps;

	if (fps->on_screen_enabled)
	{
		graphics->fps_on_screen[last_fps]->enabled = false;
		if (current_fps <= MAX_SCREEN_FPS)
		{
			graphics->fps_on_screen[current_fps]->enabled = true;
			last_fps = current_fps;
		}
	}
}

static void	fps_to_str(char *str, int num)
{
	int i;

	i = 0;
	if (num >= 10)
	{
		str[i++] = num / 10 + '0';
		num %= 10;
	}
	str[i++] = num + '0';
	str[i++] = ' ';
	str[i++] = 'F';
	str[i++] = 'P';
	str[i++] = 'S';
	str[i] = '\0';
}
