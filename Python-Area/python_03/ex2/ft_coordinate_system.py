import math


def calculate_distance(t1: tuple, t2: tuple) -> None:
    x1, y1, z1 = t1
    x2, y2, z2 = t2
    distance = math.sqrt(
        (x2 - x1) ** 2 +
        (y2 - y1) ** 2 +
        (z2 - z1) ** 2
    )
    print(f"Distance between {t1} and {t2}: {distance:.2f}\n")


def create_position(x: str, y: str, z: str) -> tuple:
    try:
        position = (int(x), int(y), int(z))
    except ValueError:
        position = (float(x), float(y), float(z))
    return position


def parsing_process(text: str) -> tuple | None:
    try:
        elements = text.split(",")
        position = create_position(
            elements[0],
            elements[1],
            elements[2]
        )
        print(f'Parsing coordinates: "{text}"')
        print(f"Parsed position: {position}")
        return position
    except ValueError as e:
        message, = e.args
        print(f'Parsing invalid coordinates: "{text}"')
        print(f'Error parsing coordinates: {e}')
        print(f"Error details - Type: {e.__class__.__name__}, Args: "
              f'("{message}",)\n')
        return None


def ft_coordinate_system() -> None:
    print("=== Game Coordinate System ===\n")
    origin = (0, 0, 0)
    try:
        try:
            position = (10, 20, 5)
            print(f"Position created: {position}")
            calculate_distance(origin, position)
        except Exception as e:
            print(e)

        try:
            pos = parsing_process("3,4,0")
            if pos:
                calculate_distance(origin, pos)
        except Exception as e:
            print(e)

        try:
            parsing_process("abc,def,ghi")
        except Exception as e:
            print(e)

        print("Unpacking demonstration:")
        x, y, z = (3, 4, 0)
        print(f"Player at x={x}, y={y}, z={z}")
        print(f"Coordinates: X={x}, Y={y}, Z={z}")
    except Exception as e:
        print(e)


if __name__ == "__main__":
    ft_coordinate_system()
