def check_temperature(temp_str: str) -> int:
    """
    Convert and validate a plant temperature (0-40°C).

    Raises ValueError if the input is not a valid number
    or is outside the allowed range.
    """
    try:
        temp_int = int(temp_str)
    except ValueError:
        raise ValueError(f"Error: '{temp_str}' is not a valid number")
    if 0 <= temp_int <= 40:
        return temp_int
    elif temp_int > 40:
        raise ValueError(f"Error: {temp_int}°C "
                         f"is too hot for plants (max 40°C)")
    else:
        raise ValueError(f"Error: {temp_int}°C "
                         f"is too cold for plants (min 0°C)")


def test_temperature_input() -> None:
    """
    Test check_temperature() with valid and invalid inputs
    while handling errors safely.
    """
    try:
        temps_list = ['25', 'abc', '100', '-50']
        print("=== Garden Temperature Checker ===")
        for temp in temps_list:
            try:
                print(f"\nTesting temperature: {temp}")
                print(f"Temperature {check_temperature(temp)}°C "
                      f"is perfect for plants!")
            except Exception as e:
                print(e)
    except Exception as e:
        print(e)
    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature_input()
