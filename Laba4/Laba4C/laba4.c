#include <stdio.h>
#include <math.h>
#include <malloc.h>

int main() {
    int n, tf, j, r, i, m;
    double G, F, Y, x, a, x1, y, y2, size_step, *x_y_values, max_x, min_x, max_y, min_y;
    y = 0;
    y2 = 0;
    m = 0;
    i = 0;
    j = 0;
    tf = 1;
    do {
        if (tf == 1) {
            printf("%s", "Введите начальную границу X = ");
            scanf("%lf", &x);
            printf("%s", "Введите A = ");
            scanf("%lf", &a);
            printf("%s", "Введите количество шагов= ");
            scanf("%i", &r);
            size_step = ceil(r*100)/100;
            printf("%s",
                   "Введите: \n N = 1 для нахождения значения переменной G. \n N = 2 для нахождения значения переменной F. \n N = 3 для нахождения значения переменной Y. \n");
            scanf("%i", &n);
            FILE *v;
            v = fopen("/home/argo/For-PenzGTU/Laba3/Laba3C/text.dat", "w+");
            x_y_values = (double *) malloc((r/8) * sizeof(double));
            switch (n) {
                case 1:
                    while (j != r) {
                        if ((5 * pow(a, 2) - 9 * a * x + 4 * pow(x, 2)) != 0) {
                            G = (5 * (-10 * pow(a, 2) + 27 * a * x + 28 * pow(x, 2))) /
                                (5 * pow(a, 2) - 9 * a * x + 4 * pow(x, 2));

                            fprintf(v, "%.3lf %.3lf\n", x, G);
                            if (j == 0) {
                                printf("╔═════════╦═════════╗\n");
                                printf("║    X    ║    Y    ║\n");
                                printf("╠═════════╬═════════╣\n");
                                *(x_y_values + j * 2 + i) = x;
                                *(x_y_values + j * 2 + i + 1) = G;
                                printf("║%9.3lf║%9.3lf║\n", *(x_y_values + j * 2 + i), *(x_y_values + j * 2 + i + 1));
                            }
                            if (j >= 1) {
                                *(x_y_values + j * 2 + i) = x;
                                *(x_y_values + j * 2 + i + 1) = G;
                                printf("║%9.3lf║%9.3lf║\n", *(x_y_values + j * 2 + i), *(x_y_values + j * 2 + i + 1));
                            }
                            if (j == 1)
                                y = (*(x_y_values + (j - 1) * 2 + i) + *(x_y_values + j * 2 + i + 1)) / 2;
                            else if (j > 1) {
                                y2 = (*(x_y_values + (j - 1) * 2 + i) + *(x_y_values + j * 2 + i + 1)) / 2;
                            }
                            if ((fabs(y) > 1.2 * fabs(y2)) && (j > 1) && (y2 != 0)) {
                                x += 1.5 * size_step;
                                y = y2;
                            } else {
                                if ((fabs(y) < 1.2 * fabs(y2)) && (j > 1) && (y2 != 0)) {
                                    x += 0.5 * size_step;
                                    y = y2;
                                } else x += size_step;
                                if (j > 1) {
                                    y = y2;
                                }

                            }
                            j += 1;

                            continue;
                        } else
                            printf("%s\n",
                                   "G не может быть результатом деления на 0. Введите другие значения переменных.");
                        break;
                    }
                    m = j;
                    j = 0;
                    for(j = 0; j < m; j++) {
                        if (j == 0) {
                            max_x = *(x_y_values + j * 2 + i);
                            min_x = *(x_y_values + j * 2 + i);
                            max_y = *(x_y_values + j * 2 + i + 1);
                            min_y = *(x_y_values + j * 2 + i + 1);
                        }
                        if (max_x < *(x_y_values + j * 2 + i))
                            max_x = *(x_y_values + j * 2 + i);
                        if (min_x > *(x_y_values + j * 2 + i))
                            min_x = *(x_y_values + j * 2 + i);
                        if (max_y < *(x_y_values + j * 2 + i + 1))
                            max_y = *(x_y_values + j * 2 + i + 1);
                        if (min_y > *(x_y_values + j * 2 + i + 1))
                            min_y = *(x_y_values + j * 2 + i + 1);
                    }
                    printf("╚═════════╩═════════╝\n");
                    printf("╔════════════════════════╦══════════╗\n");
                    printf("║Максимальное значение Х:║%10.3lf║\n",max_x);
                    printf("╠════════════════════════╬══════════╣\n");
                    printf("║Минимальное значение Х: ║%10.3lf║\n",min_x);
                    printf("╠════════════════════════╬══════════╣\n");
                    printf("║Максимальное значение Y:║%10.3lf║\n",max_y);
                    printf("╠════════════════════════╬══════════╣\n");
                    printf("║Минимальное значение Y: ║%10.3lf║\n",min_y);
                    printf("╚════════════════════════╩══════════╝\n");

                    break;
                case 2:

                    while (x <= x1) {
                        F = sin(28 * pow(a, 2) - 57 * a * x + 14 * pow(x, 2));
                        if ((F >= -1) && (F <= 1)) {
                            fprintf(v, "%.3lf %.3lf\n", x, F);
                            if (j == 0) {
                                printf("╔═════════╦═════════╗\n");
                                printf("║    X    ║    Y    ║\n");
                                printf("╠═════════╬═════════╣\n");
                                *(x_y_values + j * 2 + i) = x;
                                *(x_y_values + j * 2 + i + 1) = F;
                                printf("X=%.3lf Y=%.3lf\n", *(x_y_values + j * 2 + i), *(x_y_values + j * 2 + i + 1));
                            }
                            if (j >= 1) {
                                *(x_y_values + j * 2 + i) = x;
                                *(x_y_values + j * 2 + i + 1) = F;

                                printf("X=%.3lf Y=%.3lf\n", *(x_y_values + j * 2 + i), *(x_y_values + j * 2 + i + 1));
                            }
                            if (j == 1)
                                y = (*(x_y_values + (j - 1) * 2 + i) + *(x_y_values + j * 2 + i + 1)) / 2;
                            else if (j > 1) {
                                y2 = (*(x_y_values + (j - 1) * 2 + i) + *(x_y_values + j * 2 + i + 1)) / 2;
                            }
                            if ((fabs(y) > 1.2 * fabs(y2)) && (j > 1) && (y2 != 0)) {
                                x += 1.5 * size_step;
                                y = y2;
                            } else {
                                if ((fabs(y) < 1.2 * fabs(y2)) && (j > 1) && (y2 != 0)) {
                                    x += 0.5 * size_step;
                                    y = y2;
                                } else x += size_step;
                                if (j > 1) {
                                    y = y2;
                                }
                                if (j % 8 == 0)
                                    x_y_values = (double *) realloc(x_y_values, j * 2 * sizeof(double));
                            }
                            j += 1;
                            continue;

                        } else
                            printf("%s\n",
                                   "Переменная F не принадлежит отрезку синуса от -1 до 1. Введите другие значения");
                        break;
                    }
                    m = j;
                    j = 0;
                    for(j = 0; j < m; j++) {
                        if (j == 0) {
                            max_x = *(x_y_values + j * 2 + i);
                            min_x = *(x_y_values + j * 2 + i);
                            max_y = *(x_y_values + j * 2 + i + 1);
                            min_y = *(x_y_values + j * 2 + i + 1);
                        }
                        if (max_x < *(x_y_values + j * 2 + i))
                            max_x = *(x_y_values + j * 2 + i);
                        if (min_x > *(x_y_values + j * 2 + i))
                            min_x = *(x_y_values + j * 2 + i);
                        if (max_y < *(x_y_values + j * 2 + i + 1))
                            max_y = *(x_y_values + j * 2 + i + 1);
                        if (min_y > *(x_y_values + j * 2 + i + 1))
                            min_y = *(x_y_values + j * 2 + i + 1);
                    }

                    printf("╚═════════╩═════════╝\n");
                    printf("╔════════════════════════╦══════════╗\n");
                    printf("║Максимальное значение Х:║%10.3lf║\n",max_x);
                    printf("╠════════════════════════╬══════════╣\n");
                    printf("║Минимальное значение Х: ║%10.3lf║\n",min_x);
                    printf("╠════════════════════════╬══════════╣\n");
                    printf("║Максимальное значение Y:║%10.3lf║\n",max_y);
                    printf("╠════════════════════════╬══════════╣\n");
                    printf("║Минимальное значение Y: ║%10.3lf║\n",min_y);
                    printf("╚════════════════════════╩══════════╝\n");


                    break;
                case 3:
                    while (x <= x1) {
                        Y = log(-27 * pow(a, 2) + 24 * a * x + 35 * pow(x, 2) + 1);
                        if (Y > 0) {
                            fprintf(v, "%.3lf %.3lf\n", x, Y);

                            if (j == 0) {
                                printf("╔═════════╦═════════╗\n");
                                printf("║    X    ║    Y    ║\n");
                                printf("╠═════════╬═════════╣\n");
                                *(x_y_values + j * 2 + i) = x;
                                *(x_y_values + j * 2 + i + 1) = Y;
                                printf("X=%.3lf Y=%.3lf\n", *(x_y_values + j * 2 + i), *(x_y_values + j * 2 + i + 1));
                            }
                            if (j >= 1) {
                                *(x_y_values + j * 2 + i) = x;
                                *(x_y_values + j * 2 + i + 1) = Y;
                                printf("X=%.3lf Y=%.3lf\n", *(x_y_values + j * 2 + i), *(x_y_values + j * 2 + i + 1));
                            }
                            if (j == 1)
                                y = (*(x_y_values + (j - 1) * 2 + i) + *(x_y_values + j * 2 + i + 1)) / 2;
                            else if (j > 1) {
                                y2 = (*(x_y_values + (j - 1) * 2 + i) + *(x_y_values + j * 2 + i + 1)) / 2;
                            }
                            if ((fabs(y) > 1.2 * fabs(y2)) && (j > 1) && (y2 != 0)) {
                                x += 1.5 * size_step;
                                y = y2;
                            } else {
                                if ((fabs(y) < 1.2 * fabs(y2)) && (j > 1) && (y2 != 0)) {
                                    x += 0.5 * size_step;
                                    y = y2;
                                } else x += size_step;
                                if (j > 1) {
                                    y = y2;
                                }
                                if (j % 8 == 0)
                                    x_y_values = (double *) realloc(x_y_values, j * 2 * sizeof(double));
                            }

                            j += 1;
                            continue;
                        } else
                            printf("%s\n",
                                   "Логарифм не может быть найден при таких значениях переменных. Введите другие значения переменных.");
                        break;
                    }
                    m = j;
                    j = 0;
                    for(j = 0; j < m; j++) {
                        if (j == 0) {
                            max_x = *(x_y_values + j * 2 + i);
                            min_x = *(x_y_values + j * 2 + i);
                            max_y = *(x_y_values + j * 2 + i + 1);
                            min_y = *(x_y_values + j * 2 + i + 1);
                        }
                        if (max_x < *(x_y_values + j * 2 + i))
                            max_x = *(x_y_values + j * 2 + i);
                        if (min_x > *(x_y_values + j * 2 + i))
                            min_x = *(x_y_values + j * 2 + i);
                        if (max_y < *(x_y_values + j * 2 + i + 1))
                            max_y = *(x_y_values + j * 2 + i + 1);
                        if (min_y > *(x_y_values + j * 2 + i + 1))
                            min_y = *(x_y_values + j * 2 + i + 1);
                    }
                    printf("╚═════════╩═════════╝\n");
                    printf("╔════════════════════════╦══════════╗\n");
                    printf("║Максимальное значение Х:║%10.3lf║\n",max_x);
                    printf("╠════════════════════════╬══════════╣\n");
                    printf("║Минимальное значение Х: ║%10.3lf║\n",min_x);
                    printf("╠════════════════════════╬══════════╣\n");
                    printf("║Максимальное значение Y:║%10.3lf║\n",max_y);
                    printf("╠════════════════════════╬══════════╣\n");
                    printf("║Минимальное значение Y: ║%10.3lf║\n",min_y);
                    printf("╚════════════════════════╩══════════╝\n");

                    break;

                default:
                    printf("%s\n", "Ошибка, попросите вывод результата одной из переменных G,F или Y.");

            }
        }


        printf("%s",
               "Хотите ли ещё раз просчитать функцию? \n Введите 1 если хотите просчитать заново. \n Введите 0 для отмены.");
        scanf("%i", &tf);

        if (tf == 0){
            free(x_y_values);
            break;}
        else continue;
    } while (1);


    return 0;
}