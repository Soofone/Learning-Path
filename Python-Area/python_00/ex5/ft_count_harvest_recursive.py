def rec(days: int) -> None:
    if (days == 0):
        return
    rec(days - 1)
    print(f"Day {days}")


def ft_count_harvest_recursive() -> None:
    days = int(input("Days until harvest: "))
    rec(days)
    print("Harvest time!")
