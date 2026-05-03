#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self._name = name
        self._height = height
        self._age = age

    def get_line_first_part(self) -> str:
        return (f"{self._name} ({self.__class__.__name__}): "
                f"{self._height}cm, {self._age} days, ")


class Flower(Plant):
    def __init__(self, name: str, height: int, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self._color = color

    def set_line(self) -> None:
        self._line = (self.get_line_first_part() + f"{self._color} color")

    def get_line(self) -> str:
        self.set_line()
        return self._line

    def bloom(self) -> str:
        return f"{self._name} is blooming beautifully!"


class Tree(Plant):
    def __init__(self, name: str, height: int, age: int,
                 trunk_diameter: int) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter

    def set_line(self) -> None:
        self._line = (self.get_line_first_part() +
                      f"{self._trunk_diameter}cm diameter")

    def get_line(self) -> str:
        self.set_line()
        return self._line

    def produce_shade(self) -> str:
        pi = 3.141592
        radius = self._trunk_diameter * 10 / 100
        self._shade_area = pi * radius ** 2
        self._shade_area -= (self._shade_area % 1)
        return (f"{self._name} provides {self._shade_area:.0f} "
                f"square meters of shade")


class Vegetable(Plant):
    def __init__(self, name: str, height: int, age: int,
                 harvest_season: str, nutritional_value: str) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def set_line(self) -> None:
        self._line = (self.get_line_first_part() +
                      f"{self._harvest_season} harvest")

    def get_line(self) -> str:
        self.set_line()
        return self._line

    def display_nutritional_value(self) -> str:
        return f"{self._name} is rich in {self._nutritional_value}"


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print()

    flower1 = Flower("Rose", 25, 30, "red")
    print(flower1.get_line())
    print(flower1.bloom())
    print()
    flower2 = Flower("Sunflower", 20, 16, "yellow")
    print(flower2.get_line())
    print(flower2.bloom())
    print()

    tree1 = Tree("Oak", 500, 1825, 50)
    print(tree1.get_line())
    print(tree1.produce_shade())
    print()
    tree2 = Tree("Walnut", 300, 1500, 20)
    print(tree2.get_line())
    print(tree2.produce_shade())
    print()

    vegetable1 = Vegetable("Tomato", 80, 90, "summer", "vitamin C")
    print(vegetable1.get_line())
    print(vegetable1.display_nutritional_value())
    print()
    vegetable2 = Vegetable("Lettuce", 40, 60, "summer", "vitamin K")
    print(vegetable2.get_line())
    print(vegetable2.display_nutritional_value())
