# TODO list

## Parsing

### Règles

- [x] Vérifier le nombre d'argument
- [x] Vérifier l'extension `.cub`
- [ ] La carte doit posséder uniquement ces caractères: des 1 et des 0 et **exactement un seul** caractère parmis N S E et W.
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