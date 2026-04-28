def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    seed_type = seed_type.capitalize()
    line = "Unknown unit type"
    if (unit == "packets"):
        line = f"{seed_type} seeds: {quantity} {unit} available"
    elif (unit == "grams"):
        line = f"{seed_type} seeds: {quantity} {unit} total"
    elif (unit == "area"):
        line = f"{seed_type} seeds: covers {quantity} square meters"
    print(f"{line}")
