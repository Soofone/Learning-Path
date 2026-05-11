class WaterError(Exception):
    """
    Exception raised for water-related problems.
    """
    pass


def water_plants(plant_list: list[str]) -> None:
    """
    Water plants and handle invalid entries with cleanup.
    """
    print("Opening watering system")
    for plant in plant_list:
        try:
            if not plant:
                raise WaterError("Cannot water None - invalid plant!")
            if plant.__class__.__name__ != "str":
                raise WaterError("Cannot water invalid plant!")
            print(f"Watering {plant}")
        except WaterError as e:
            print(f"Error: {e}")
    print("Closing watering system (cleanup)")


def test_watering_system() -> None:
    """
    Test the watering system with normal and error cases.
    """
    print("=== Garden Watering System ===\n")
    try:
        plant_list = ["tomato", "lettuce", "carrots"]
        print("Testing normal watering...")
        water_plants(plant_list)
        print("Watering completed successfully!\n")
        print("Testing with error...")
        plant_list = ["tomato", None]
        water_plants(plant_list)
    except Exception as e:
        print(e)
    finally:
        print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
