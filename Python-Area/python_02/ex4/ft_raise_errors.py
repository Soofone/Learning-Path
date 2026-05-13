def check_plant_health(plant_name: str, water_level: int,
                       sunlight_hours: int) -> str:
    """
    Validate plant health parameters and return a success message.
    Raises ValueError if any input is invalid or out of range.
    """
    if not plant_name:
        raise ValueError("Error: Plant name cannot be empty!")
    if plant_name.__class__.__name__ != "str":
        raise TypeError("Error: Plant name can be only an str!")
    if water_level > 10:
        raise ValueError(f"Error: Water level {water_level}"
                         f" is too high (max 10)")
    if water_level < 1:
        raise ValueError(f"Error: Water level {water_level}"
                         f" is too low (min 1)")
    if sunlight_hours > 12:
        raise ValueError(f"Error: Sunlight hours {sunlight_hours} "
                         f"is too high (max 12)")
    if sunlight_hours < 2:
        raise ValueError(f"Error: Sunlight hours {sunlight_hours} "
                         f"is too low (min 2)")
    return f"Plant '{plant_name}' is healthy!"


def test_plant_checks() -> None:
    """
    Test plant health validation with valid and invalid cases.
    """
    print("=== Garden Plant Health Checker ===")
    try:
        print("\nTesting good values...")
        print(check_plant_health("tomato", 10, 7))
    except ValueError as e:
        print(e)
    except Exception as e:
        print(e)
    try:
        print("\nTesting empty plant name...")
        print(check_plant_health(None, 7, 9))
    except ValueError as e:
        print(e)
    except Exception as e:
        print(e)
    try:
        print("\nTesting bad water level...")
        print(check_plant_health("tomato", 15, 10))
    except ValueError as e:
        print(e)
    except Exception as e:
        print(e)
    try:
        print("\nTesting bad sunlight hours...")
        print(check_plant_health("tomato", 9, 0))
    except ValueError as e:
        print(e)
    except Exception as e:
        print(e)
    print("\nAll error raising tests completed!")


if __name__ == "__main__":
    test_plant_checks()
