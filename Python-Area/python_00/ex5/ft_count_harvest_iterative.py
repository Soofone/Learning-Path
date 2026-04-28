def ft_count_harvest_iterative() -> None:
    days = int(input("Days until harvest: "))
    d = 1
    while (d <= days):
        print(f"Day {d}")
        d += 1
    print("Harvest time!")
