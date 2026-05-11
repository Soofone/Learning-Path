class GardenError(Exception):
    """
    Base exception for all garden-related errors.
    """
    pass


class PlantError(GardenError):
    """
    Exception raised for plant-related problems.
    """
    pass


class WaterError(GardenError):
    """
    Exception raised for water-related problems.
    """
    pass


def check_plant_health(is_wilting: bool) -> None:
    """
    Raise a PlantError if the plant is wilting.
    """
    if is_wilting:
        raise PlantError("The tomato plant is wilting!")


def check_water_tank(is_empty: bool) -> None:
    """
    Raise a WaterError if the water tank is empty.
    """
    if is_empty:
        raise WaterError("Not enough water in the tank!")


def test_custom_errors() -> None:
    """
    Demonstrate raising and catching custom garden exceptions.
    """
    print("=== Custom Garden Errors Demo ===")
    try:
        print("\nTesting PlantError...")
        check_plant_health(True)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    except Exception as e:
        print(e)
    try:
        print("\nTesting WaterError...")
        check_water_tank(True)
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    except Exception as e:
        print(e)
    print("\nTesting catching all garden errors...")
    try:
        check_plant_health(True)
    except GardenError as e:
        print(f"Caught a garden error: {e}")
    except Exception as e:
        print(e)
    try:
        check_water_tank(True)
    except GardenError as e:
        print(f"Caught a garden error: {e}")
    except Exception as e:
        print(e)
    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    test_custom_errors()
