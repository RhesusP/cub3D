# TODO list

## Parsing

### Règles

- [x] Vérifier le nombre d'argument
- [x] Vérifier l'extension `.cub`
- [ ] Lancer une erreur si le chemin passé en paramètre est un répertoire
- [x] La carte doit posséder uniquement ces caractères: des 1 et des 0 et **exactement un seul** caractère parmis N S E et W.
- [ ] Ne pas ajouter le `\n` a la fin du chemin des textures
- [ ] Ajouter le atoi de `push_swap`
- [ ] La carte doit être fermée / entourée de murs


### Composition de la carte

👉 La description est toujours en dernier.

```txt
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Raycasting explanations

RayCasting most limitation is that the viewpoint cannot be rotated along the Z axis.

### Geometric contraints
A world must have the following geometric constraints : 
- Walls are always at 90° angle with the floor.
- Walls are made of cubes that have the same size (here 64x64x64)
- Floor is always flat

### Coordinate system

```txt
 (y)
  |                    x increases
---------------------- (x)
  | (0,0)
  |
  |
  |
  |  y increases
```

```txt
              90°
               |
               |
               |                   
180° ----------------------- 0°
               |
               |
               |
	      270°
```

### Projection attributes

We need to define these attributes : 
- Player FOV (90 degrees for most humans but this looks bad on screen, so we prefered 60°)
- Player height (here 32)
- Player position (given by map description)
- Projection's plane dimension (here 1280 x 720)
- Relationship between player and projection plane

Knowing FOV and dimensions of the projection plane, we're able to calculate the angle between subsequent rays and the distance between the player and the projection plane
![](https://permadi.com/tutorial/raycast/images/figure11.jpg)
![](https://permadi.com/tutorial/raycast/images/fig11c.gif)
![](https://permadi.com/tutorial/raycast/images/fig11d.gif)

So: 
- Dimension of the projection plane: 1280 x 720 units
- Center of the projection plane: (640, 360)
- Distance to the projection plane: `640 / tan(30°) ≈ 99,90`
- Angle between subsequent rays: 1280 columns = 60 degrees, so 1 column = 60/1280 degrees.

👉 The distance between player to the projection plane will be used for scaling.

Instead of tracing a ray for each pixel on the screen, we trace a ray for **each column** (1280) on the screen

### Raycasting

### DDA algorithm

### Texturing walls
👉 MinilibX allows to use images in png and xmp formats but using images in png format causes memory leaks. So here, we use the followong function : 
```c
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
```


## Useful links

[JavaScript RayCasting tutoriel](https://github.com/vinibiavatti1/RayCastingTutorial/wiki/Home)  
[RayCasting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
[Sprites database](https://spritedatabase.net/system/pc);
[Cub3d tutorial](https://website-b-bischoff.vercel.app/cube3d)