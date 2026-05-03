#!/usr/bin/env python3

class Plant:
    len = 0

    def __init__(self, name: str, height: int, age: int) -> None:
        self._name = name
        self._height = height
        self._age = age
        print(f"Created: {self._name} ({self._height}cm, {self._age} days)")
        Plant.len += 1


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    plants = [Plant("Rose", 25, 30),
              Plant("Oak", 200, 365),
              Plant("Cactus", 5, 90),
              Plant("Sunflower", 80, 45),
              Plant("Fern", 15, 120)]
    print(f"\nTotal plants created: {Plant.len}")
