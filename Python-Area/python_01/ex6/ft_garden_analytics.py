#!/usr/bin/env python3

class GardenManager:

    count_gardens = 0
    gardens_list: list["Garden"] = []

    def __init__(self, name: str) -> None:
        self._name = name
        self._garden = Garden(name)
        GardenManager.count_gardens += 1

    def get_name(self) -> str:
        return self._name

    def get_garden(self) -> "Garden":
        return self._garden

    def add_plant_to_garden(self, plant: "Plant", display_line: int) -> None:
        self._garden.add_plant_to_list(plant)
        if display_line:
            print(f"Added {plant.get_name()} to {self._name}'s garden")

    def grow_plants(self) -> None:
        print()
        print(f"{self._name} is helping all plants grow...")
        self._garden.grew()

    class GardenStats:

        def plants_data() -> None:
            print(f"Plants added: {Garden.count_plants}, "
                  f"Total growth: {Garden.count_total_growth}cm")
            print(f"Plant types: {Plant.count_regular} regular, "
                  f"{Plant.count_flowering} flowering, "
                  f"{Plant.count_prize} flowers")
            print()

        def get_gardens_scores() -> None:
            print("Garden scores - ", end="")
            for i in range(GardenManager.count_gardens):
                garden = GardenManager.gardens_list[i]
                print(f"{garden.get_name()}: "
                      f"{garden.get_total_height()}", end="")
                if i != GardenManager.count_gardens - 1:
                    print(", ", end="")
            print()

        def get_total_gardens_managed() -> None:
            print(f"Total gardens managed: {GardenManager.count_gardens}")
        plants_data = staticmethod(plants_data)
        get_gardens_scores = staticmethod(get_gardens_scores)
        get_total_gardens_managed = staticmethod(get_total_gardens_managed)

    def create_garden_network(cls, garden: "Garden") -> None:
        cls.gardens_list += [garden]

    create_garden_network = classmethod(create_garden_network)


def display_plants_in_garden(garden: "Garden") -> None:
    print()
    print(f"=== {garden.get_name()}'s Garden Report ===")
    print("Plants in garden:")
    for plant in garden.get_plants_list():
        print(f"- {plant.get_info()}")
    print()


def validate_height(garden: "Garden") -> bool:
    for plant in garden.get_plants_list():
        if plant.get_height() < 0:
            return False
    return True


class Garden:
    count_plants = 0
    count_total_growth = 0

    def __init__(self, name: str) -> None:
        self._name = name
        self._plants_list: list["Plant"] = []

    def get_name(self) -> str:
        return self._name

    def get_plants_list(self) -> list["Plant"]:
        return self._plants_list

    def add_plant_to_list(self, plant: "Plant") -> None:
        self._plants_list += [plant]
        Garden.count_plants += 1

    def grew(self) -> None:
        for plant in self._plants_list:
            plant.grow()
            Garden.count_total_growth += 1
            print(f"{plant.get_name()} grew 1cm")

    def get_total_height(self) -> int:
        height = 0
        for plant in self._plants_list:
            height += plant.get_height()
        return height


class Plant:
    count_regular = 0
    count_flowering = 0
    count_prize = 0

    def __init__(self, name: str, height: int) -> None:
        self._name = name
        self._height = height

        if (self.__class__.__name__ == "Plant"):
            Plant.count_regular += 1
        elif (self.__class__.__name__ == "FloweringPlant"):
            Plant.count_flowering += 1
        else:
            Plant.count_prize += 1

    def set_name(self, new_name: str) -> None:
        self._name = new_name

    def set_height(self, new_height: int) -> None:
        self._height = new_height

    def get_name(self) -> str:
        return self._name

    def get_height(self) -> int:
        return self._height

    def grow(self) -> None:
        self._height += 1

    def get_info(self) -> str:
        return f"{self._name}: {self._height}cm"


class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, color: str) -> None:
        super().__init__(name, height)
        self._color = color

    def set_color(self, new_color: str) -> None:
        self._color = new_color

    def get_color(self) -> str:
        return self._color

    def get_info(self) -> str:
        return super().get_info() + f", {self._color} flowers (blooming)"


class PrizeFlower(FloweringPlant):
    def __init__(self, name: str, height: int,
                 color: str, prize_points: int) -> None:
        super().__init__(name, height, color)
        self._prize_points = prize_points

    def set_prize_points(self, new_prize_points: int) -> None:
        self._prize_points = new_prize_points

    def get_prize_points(self) -> int:
        return self._prize_points

    def get_info(self) -> str:
        return super().get_info() + f", Prize points: {self._prize_points}"


if __name__ == "__main__":
    print("=== Garden Management System Demo ===\n")
    g1 = GardenManager("Alice")
    plant1 = Plant("Oak Tree", 100)
    flowering_plant1 = FloweringPlant("Rose", 25, "red")
    prize_flower1 = PrizeFlower("Sunflower", 50, "yellow", 10)

    g2 = GardenManager("Bob")

    g1.add_plant_to_garden(plant1, 1)
    g1.add_plant_to_garden(flowering_plant1, 1)
    g1.add_plant_to_garden(prize_flower1, 1)
    g2.add_plant_to_garden(plant1, 0)
    g1.grow_plants()
    display_plants_in_garden(g1.get_garden())
    GardenManager.GardenStats.plants_data()

    print(f"Height validation test: "
          f"{validate_height(g1.get_garden())}")
    GardenManager.create_garden_network(g1.get_garden())
    GardenManager.create_garden_network(g2.get_garden())
    GardenManager.GardenStats.get_gardens_scores()
    GardenManager.GardenStats.get_total_gardens_managed()
