import sys


def program_name() -> None:
    print(f"Program name: {sys.argv[0]}")


def total_args() -> None:
    print(f"Total arguments: {len(sys.argv)}\n")


def args_received() -> None:
    print(f"Arguments received: {len(sys.argv) - 1}")


def no_args_case() -> None:
    print("No arguments provided!")
    program_name()
    total_args()


def print_args() -> None:
    i = 1
    while i < len(sys.argv):
        print(f"Argument {i}: {sys.argv[i]}")
        i += 1


def ft_command_quest() -> None:
    print("=== Command Quest ===")
    try:
        if len(sys.argv) == 1:
            no_args_case()
        else:
            program_name()
            args_received()
            print_args()
            total_args()
    except Exception as e:
        print(e)


if __name__ == "__main__":
    ft_command_quest()
