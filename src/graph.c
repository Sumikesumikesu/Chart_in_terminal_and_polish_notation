#include "libs/include/calculator.h"
#include "libs/include/parser.h"

#define HEIGHT 25
#define WIDTH 80
#define X_MIN 0
#define X_MAX (4 * M_PI)
#define Y_MIN -1
#define Y_MAX 1

void create_graphic(int graph[HEIGHT][WIDTH], Queue *queue);
void print_graph(int graph[HEIGHT][WIDTH]);

int main() {
    int graph[HEIGHT][WIDTH];
    char input[MAX_TOKENS];

    int exit_loop = 0;
    for (int i = 0; i < MAX_TOKENS - 1 && !exit_loop; i++) {
        char ch = getchar();

        if (ch != '\n') {
            input[i] = ch;
        } else
            exit_loop = 1;
    }
    input[MAX_TOKENS - 1] = '\0';

    removeSpaces(input);
    replaceUnaryMinus(input);

    char *tokens[MAX_TOKENS];
    int token_count = 0;

    Stack stack;
    init_stack(&stack);
    Queue queue;
    init_queue(&queue);

    parse_string(input, tokens, &token_count);
    shuntingYard(tokens, &stack, &queue);

    create_graphic(graph, &queue);
    print_graph(graph);

    for (int i = 0; i < token_count - 1; i++) {
        free(tokens[i]);
    }

    return 0;
}

void create_graphic(int graph[HEIGHT][WIDTH], Queue *queue) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            graph[y][x] = '.';
        }
    }

    for (int x = 0; x < WIDTH; x++) {
        double x_val = X_MAX * x / (WIDTH - 1);
        double res = calculations(queue, x_val);

        int y_pos = round((HEIGHT - 1) / 2 - (res * (HEIGHT - 1) / 2));

        if (y_pos >= 0 && y_pos < HEIGHT) {
            graph[y_pos][x] = '*';
        }
    }
}

void print_graph(int graph[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(graph[y][x]);
        }
        putchar('\n');
    }
}