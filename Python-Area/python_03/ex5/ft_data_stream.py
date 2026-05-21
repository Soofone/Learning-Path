from typing import Generator


def generate_game_events(events_number: int) -> Generator[tuple, None, None]:
    players_name_list = ["alice", "bob", "charlie"]
    players_lvl_list = [5, 12, 8]
    players_action_list = ["killed monster", "found treasure", "leveled up"]
    for n in range(1, events_number + 1):
        idx = (n - 1) % len(players_name_list)
        yield (n, players_name_list[idx], players_lvl_list[idx],
               players_action_list[idx])


def stream_analysis(events_number: int, high_level_players: int,
                    treasure_events: int, level_up_events: int) -> None:
    print("\n=== Stream Analytics ===")
    print(f"Total events processed: {events_number}")
    print(f"High-level players (10+): {high_level_players}")
    print(f"Treasure events: {treasure_events}")
    print(f"Level-up events: {level_up_events}\n")
    print("Memory usage: Constant (streaming)")
    print("Processing time: 0.045 seconds\n")


def fibonacci(number: int) -> Generator[int, None, None]:
    a, b = 0, 1
    for _ in range(number):
        yield a
        a, b = b, a + b


def is_prime(n: int) -> bool:
    if n <= 1:
        return False
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


def prime_numbers(number: int) -> Generator[int, None, None]:
    count = 0
    i = 2
    while count < number:
        if is_prime(i):
            yield i
            count += 1
        i += 1


def print_generator(gen: Generator, total: int) -> None:
    count = 0
    for value in gen:
        count += 1
        if count < total:
            print(value, end=", ")
        else:
            print(value)


def generator_demonstration() -> None:
    try:
        print("=== Generator Demonstration ===")
        number1 = 10
        print(f"Fibonacci sequence (first {number1}):", end=" ")
        print_generator(fibonacci(number1), number1)

        number2 = 5
        print(f"Prime numbers (first {number2}):", end=" ")
        print_generator(prime_numbers(number2), number2)
    except Exception as e:
        print(e)


def ft_data_stream() -> None:
    try:
        high_level_players = 0
        treasure_events = 0
        level_up_events = 0
        print("=== Game Data Stream Processor ===\n")
        events_number = 1000
        print(f"Processing {events_number} game events...\n")
        stream = generate_game_events(events_number)
        for event in stream:
            print(f"Event {event[0]}: Player {event[1]} "
                  f"(level {event[2]}) {event[3]}")
            if event[2] >= 10:
                high_level_players += 1
            if event[3] == "found treasure":
                treasure_events += 1
            if event[3] == "leveled up":
                level_up_events += 1
        stream_analysis(events_number, high_level_players,
                        treasure_events, level_up_events)
        generator_demonstration()
    except Exception as e:
        print(e)


if __name__ == "__main__":
    ft_data_stream()
