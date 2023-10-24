#include <stdio.h>

// Definición de la estructura del juego
typedef struct {
    int rows;
    int cols;
    char **matrix;
    struct {
        int x;
        int y;
    } player;
    struct {
        int x;
        int y;
    } exit;
} Game;

int valid_path_helper(Game game, int x, int y) {

    // Verificamos si ya estamos en la salida
    if (x == game.exit.x && y == game.exit.y)
        return 1;

    // Verificamos si la celda actual es transitable
    if (game.map.map[y][x] == '1')
        return 0;
    game.map.map[y][x] = '1';
    if (valid_path_helper(game, x, y - 1))
		return 1;
    if (valid_path_helper(game, x, y + 1))
		return 1;
    if (valid_path_helper(game, x - 1, y))
		return 1;
    if (valid_path_helper(game, x + 1, y))
		return 1;
    return 0;
}

// Función principal para verificar si hay un camino válido
int valid_path(Game *game) {
    if (game->matrix[game->player.y][game->player.x] == '1') {
        return 0;
    }
    return valid_path_helper(game, game->player.x, game->player.y);
}

int main() {
    // Ejemplo de uso
    Game game = {
        .rows = 3,
        .cols = 3,
        .matrix = (char *[]){
            (char []){'0', '1', 'E'},
            (char []){'P', '1', '0'},
            (char []){'1', '1', '0'},
        },
        .player = {.x = 0, .y = 1},
        .exit = {.x = 2, .y = 0},
    };

    if (valid_path(&game)) {
        printf("¡Hay un camino válido!\n");
    } else {
        printf("No hay un camino válido.\n");
    }

    return 0;
}
