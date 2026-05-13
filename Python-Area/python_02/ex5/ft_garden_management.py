class GardenError(Exception):
    """
    Base exception for garden-related errors.
    """
    pass


class PlantError(GardenError):
    """
    Exception raised for plant-related issues.
    """
    pass


class WaterError(GardenError):
    """
    Exception raised for watering-related issues.
    """
    pass


class Plant:
    """
    Represent a plant with water and sunlight requirements.
    """
    def __init__(self, name: str, water: int, sun_light: int) -> None:
        """
        Initialize plant name, water level, and sunlight hours.
        """
        self.name = name
        self.water = water
        self.sun_light = sun_light


class Garden:
    """
    Represent a garden containing multiple plants.
    """
    def __init__(self, name: str) -> None:
        self.name = name
        self.plants_list = []


class GardenManager:
    """
    Manage garden operations such as adding, watering, and checking plants.
    """
    tank = 20

    def __init__(self, manager: str) -> None:
        """
        Initialize manager and create an associated garden.
        """
        self.manager = manager
        self.garden = Garden(manager)

    def add_plant(self, plant: Plant) -> None:
        """
        Add a plant to the garden with basic validation.
        """
        try:
            if not plant.name:
                raise TypeError("Error adding plant: " +
                                "Plant name cannot be empty!")
            if (plant.name.__class__.__name__ != "str"):
                raise ValueError("Error adding plant: " +
                                 "Plant name should be a string")
            if not plant.water:
                raise TypeError("Error adding plant: " +
                                "Plant water cannot be empty!")
            if (plant.water.__class__.__name__ != "int"):
                raise ValueError("Error adding plant: " +
                                 "Plant water should be an int")

            if not plant.sun_light:
                raise TypeError("Error adding plant: " +
                                "Plant sun_light cannot be empty!")
            if (plant.sun_light.__class__.__name__ != "int"):
                raise ValueError("Error adding plant: " +
                                 "Plant sun_light should be an int")
            self.garden.plants_list += [plant]
            print(f"Added {plant.name} successfully")
        except Exception as e:
            print(e)

    def water_plants(self) -> None:
        """
        Water all plants and ensure cleanup using finally.
        """
        print("Opening watering system")
        try:
            for plant in self.garden.plants_list:
                print(f"Watering {plant.name} - success")
        finally:
            print("Closing watering system (cleanup)")

    def check_plant_health(self, plant: Plant) -> str:
        """
        Validate plant health parameters and return status.
        """
        if plant.water > 10:
            raise WaterError(f"Error checking {plant.name}: "
                             f"Water level {plant.water}"
                             f" is too high (max 10)")
        if plant.water < 1:
            raise WaterError(f"Error checking {plant.name}: "
                             f"Water level {plant.water}"
                             f" is too low (min 1)")
        if plant.sun_light > 12:
            raise PlantError(f"Error checking {plant.name}: "
                             f"Sunlight hours {plant.sun_light} "
                             f"is too high (max 12)")
        if plant.sun_light < 2:
            raise PlantError(f"Error checking {plant.name}: "
                             f"Sunlight hours {plant.sun_light} "
                             f"is too low (min 2)")
        return (f"{plant.name}: healthy (water: {plant.water}, "
                f"sun {plant.sun_light})")

    def check_tank() -> None:
        """
        Check if the water tank level is sufficient.
        """
        if (GardenManager.tank < 100):
            raise GardenError("Caught GardenError: Not enough water in tank")
    check_tank = staticmethod(check_tank)


def test_garden_management() -> None:
    """
    Run a full test of the garden management system.
    """
    try:
        print("=== Garden Management System ===")
        g1 = GardenManager("Soufiane")

        p1 = Plant("tomato", 5, 8)
        p2 = Plant("lettuce", 15, 9)
        p3 = Plant(None, 8, 10)

        print("\nAdding plants to garden..")

        g1.add_plant(p1)
        g1.add_plant(p2)
        g1.add_plant(p3)

        print("\nWatering plants...")
        g1.water_plants()

        print("\nChecking plant health...")
        for plant in g1.garden.plants_list:
            try:
                print(g1.check_plant_health(plant))
            except (PlantError, WaterError) as e:
                print(e)
        try:
            print("\nTesting error recovery...")
            GardenManager.check_tank()
        except GardenError as e:
            print(e)
        finally:
            print("System recovered and continuing...\n")
            print("Garden management system test complete!")
    except Exception as e:
        print(e)


if __name__ == "__main__":
    test_garden_management()
