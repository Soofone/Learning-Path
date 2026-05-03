#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self._name = name
        self._height = height
        self._age = age

    def grow(self) -> None:
        self._height += 1

    def age(self) -> None:
        self._age += 1

    def growth(self) -> None:
        self.grow()
        self.age()

    def get_info(self) -> None:
        print(f"{self._name}: {self._height}cm, {self._age} days old")


if __name__ == "__main__":
    plants = [Plant("Rose", 25, 30),
              Plant("Sunflower", 80, 45),
              Plant("Cactus", 15, 120)]
    print("=== Day 1 ===")
    for p in plants:
        p.get_info()
        for d in range(1, 7):
            p.growth()
    print(f"=== Day {d + 1} ===")
    for p in plants:
        p.get_info()
    print(f"Growth this week: +{d}cm")
