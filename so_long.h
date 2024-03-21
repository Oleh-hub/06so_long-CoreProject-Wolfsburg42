/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:53 by oruban            #+#    #+#             */
/*   Updated: 2024/03/21 19:37:33 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>                     // open()

// defines to work with mlx library
# ifndef MLX_PIC_SIZE		// pixels in picture
#  define PIC_SIZE 80 		// Complete list of AppleScrip
#  define ESC_KEY 53
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_A 0
# endif	/* MLX_PIC_SIZE */

// frame 4 almost everything (map parcing + work with mlx)
typedef struct s_frame
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*collectible;
	void	*player_img;		// can be eihter void *player[0] or [1]
	void	*player_sprite[2];
	char	direction;			// need to now which player picture to use
	void	*wall;
	void	*floor;
	void	*door[2];			// 2 pics: open and closed door
	char	lastpos;			// last position validation flag. should == '0'
	int		img_side;			// 4 mlx_xpm_file_to_image() 2b width and height
	int		player[2];			// player's coordinated [row][collumn]
	int		rows;
	int		cols;
	int		collectibles;
	int		exit;
	int		steps;
	int		collected;
}			t_frame;

/* paramters for the funciton called from ismiddle*/
typedef struct s_func_pars
{
	char	*line;
	char	*next_l;
	int		cols;
	int		fd;
}			t_func_pars;

/* PEC0 counters 2 be given as a parameter to teh function called
 from ismiddle */
typedef struct s_peco
{
	int		p;
	int		e;
	int		c;
	int		o;
	int		l;
}				t_peco;

// 2map_check_utils.c:
void	check_path(t_frame *game, int **marked);
void	mark_path(t_frame *game, int row, int col, int **marked);
void	is_path(t_frame *game);
void	is_pec(t_frame *game);
void	init_frame_map(t_frame *game, int fd);
// 1map_check_utils.c :
void	peco_chrs_chck(t_peco *peco, t_func_pars chr_chck);
t_peco	*ismiddle(char *line, char *next_l, int cols, int fd);
int		iswall(char *s, char flag, int fd);
int		map_valid(int fd, t_frame *game);
void	init_frame_start(t_frame *game);
// 99utils.c :
int		key_hook(int keycode, t_frame *game);
int		correct_exit(t_frame *game);
void	error_exit(const char *s, int fd, char *line, char *line1);
#endif  /* SO_LONG_H */
