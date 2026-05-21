import sys


class NoArgsError(Exception):
    pass


class NoValidScoresError(Exception):
    pass


def print_details(numbers_list: list[int]) -> None:
    if not numbers_list:
        raise NoValidScoresError("No valid scores to process.")

    len_numbers = len(numbers_list)
    sum_numbers = sum(numbers_list)
    avg_numbers = sum_numbers / len_numbers
    max_number = max(numbers_list)
    min_number = min(numbers_list)
    score_range = max_number - min_number

    print(f"Scores processed: {numbers_list}\n"
          f"Total players: {len_numbers}\n"
          f"Total score: {sum_numbers}\n"
          f"Average score: {avg_numbers:.1f}\n"
          f"High score: {max_number}\n"
          f"Low score: {min_number}\n"
          f"Score range: {score_range}")


def ft_score_analytics() -> None:
    print("=== Player Score Analytics ===")
    try:
        if len(sys.argv) == 1:
            raise NoArgsError(f"No scores provided. Usage: "
                              f"python3 {sys.argv[0]} <score1> <score2> ...")
        numbers_list = []
        for arg in sys.argv[1:]:
            try:
                numbers_list.append(int(arg))
            except Exception:
                print(f"Invalid input detected: '{arg}' is not a number.")
        print_details(numbers_list)
    except Exception as e:
        print(e)


if __name__ == "__main__":
    ft_score_analytics()
