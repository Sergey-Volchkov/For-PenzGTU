from numpy import *
import matplotlib.pyplot as plt

y_values = []
x_values = []
values = []


uslovie = int(1)
first_average_arifmetic = float
finally_average_arifmetic = float
for_y = int(1)
for_values = int(1)
i = int(0)
w = str('X=')
h = str('Y=')
while uslovie == 1:
    x = float(input('Введите x = '))
    a = float(input('Введите a = '))
    x1 = float(input('Введите x1 = '))
    r = float(input('Введите размер шага= '))
    n = float(input(
        'Введите: \nN = 1 для нахождения значения переменной G.\nN = 2 для нахождения значения переменной F.\nN = 3 для нахождения значения переменной Y.'))
    if n == 1:
        while x < x1:
            if 0 != (5 * a ** 2 - 9 * a * x + 4 * x ** 2):
                G = (5 * (-10 * a ** 2 + 27 * a * x + 28 * x ** 2)) / (5 * a ** 2 - 9 * a * x + 4 * x ** 2)
                print(w, end=' ')
                print(x, end=' ')
                print(h, end=' ')
                print(round(G, 3))
                x_values.append(x)
                y_values.append(G)
                if i > 0:
                    values = y_values[i-1:i+1]

                if i == 1:
                    first_average_arifmetic = fabs(sum(values) / 2)
                    x += 1
                elif i > 1:
                    finally_average_arifmetic = fabs(sum(values) / 2)
                    if i > 1:
                        if first_average_arifmetic < 1.2 * finally_average_arifmetic:
                            x += r * 3
                            first_average_arifmetic = finally_average_arifmetic
                        elif first_average_arifmetic > 1.2 * finally_average_arifmetic:
                            x += r / 3
                            first_average_arifmetic = finally_average_arifmetic
                            del values[:]
                        else:
                            x += r
                            del values[:]
                    else:
                        x += r
                        del values[:]
                else:
                    x += r
                i += 1
                print('Количество шагов: ', str(i))
            else:
                print(
                    'Функция G не может быть составлена, ибо является результатом деления на 0. Введите другие значения переменных.')
                break
        plt.plot(x_values, y_values)
        plt.show()
        i = 0
    elif n == 2:
        while x < x1:
            F = math.sin(28 * a ** 2 - 57 * a * x + 14 * x ** 2)
            if -1 <= F <= 1:
                print(w, end=' ')
                print(x, end=' ')
                print(h, end=' ')
                print(round(F, 3))
                x_values.append(x)
                y_values.append(F)
                if i > 0:
                    values = y_values[i-1:i+1]

                if i == 1:
                    first_average_arifmetic = fabs(sum(values) / 2)
                    x += 1
                elif i > 1:
                    finally_average_arifmetic = fabs(sum(values) / 2)
                    if i > 1:
                        if first_average_arifmetic < 1.2 * finally_average_arifmetic:
                            x += r * 3
                            first_average_arifmetic = finally_average_arifmetic
                        elif first_average_arifmetic > 1.2 * finally_average_arifmetic:
                            x += r / 3
                            first_average_arifmetic = finally_average_arifmetic
                            del values[:]
                        else:
                            x += r
                            del values[:]
                    else:
                        x += r
                        del values[:]
                else:
                    x += r
                i += 1
                print('Количество шагов: ', str(i))
            else:
                print('Переменная F не принадлежит отрезку синуса от -1 до 1. Введите другие значения')
                break
        plt.plot(x_values, y_values)
        plt.show()
        i = 0
    elif n == 3:
        while x < x1:
            if (-27 * a ** 2 + 24 * a * x + 35 * x ** 2 + 1) > 0:
                Y = math.log(-27 * a ** 2 + 24 * a * x + 35 * x ** 2 + 1)
                print(w, end=' ')
                print(x, end=' ')
                print(h, end=' ')
                print(round(Y, 3))
                x_values.append(x)
                y_values.append(Y)
                if i > 0:
                    values = y_values[i-1:i+1]

                if i == 1:
                    first_average_arifmetic = fabs(sum(values) / 2)
                    x += 1
                elif i > 1:
                    finally_average_arifmetic = fabs(sum(values) / 2)
                    if i > 1:
                        if first_average_arifmetic < 1.2 * finally_average_arifmetic:
                            x += r * 3
                            first_average_arifmetic = finally_average_arifmetic
                        elif first_average_arifmetic > 1.2 * finally_average_arifmetic:
                            x += r / 3
                            first_average_arifmetic = finally_average_arifmetic
                            del values[:]
                        else:
                            x += r
                            del values[:]
                    else:
                        x += r
                        del values[:]
                else:
                    x += r
                i += 1
                print('Количество шагов: ', str(i))
            else:
                print(
                    'Логарифм не может быть найден при таких значениях переменных. Введите другие значения переменных.')
                break
        plt.plot(x_values, y_values)
        plt.show()
        i = 0
    else:
        print('Ошибка, попросите вывод результата одной из переменных G,F или Y.')

    x_values.clear()
    y_values.clear()
    print('Хотите ли провести вычисления ещё раз? Введите 1 для продолжение или 0 для выхода')
    uslovie = int(input())
    if uslovie == 0:
        break
    else:
        continue

