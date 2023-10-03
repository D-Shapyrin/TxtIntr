import argparse
import math
import sys

def calculate_power_e_x(x):
    result = math.exp(x)
    return result

def calculate_power_x_y(x, y):
    result = math.pow(x, y)
    return result

def main():
    parser = argparse.ArgumentParser(description="Калькулятор для возведения 'e' в степень 'x' или возведения 'x' в степень 'y'.")
    parser.add_argument("-o", "--operation", choices=["exp", "pow"], required=True, help="Напишите один из флагов чтобы выполнить операцию 'exp' или 'pow'.")
    parser.add_argument("operands", nargs="+", type=float, help="Значение(я) (операнды) для выполнения операции.")

    if len(sys.argv) == 1:
        parser.print_help()
        sys.exit(1)

    args = parser.parse_args()

    if args.operation == "exp":
        if len(args.operands) != 1:
            print("Операция 'exp' требует один операнд.")
        else:
            result = calculate_power_e_x(args.operands[0])
            print(f"Результат: e^{args.operands[0]} = {result}")
    elif args.operation == "pow":
        if len(args.operands) != 2:
            print("Операция 'pow' требует два операнда.")
        else:
            result = calculate_power_x_y(args.operands[0], args.operands[1])
            print(f"Результат: {args.operands[0]}^{args.operands[1]} = {result}")
    else:
        print("Неподдерживаемая операция. Поддерживаемые операции: 'exp', 'pow'.")