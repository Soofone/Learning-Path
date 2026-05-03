#!/usr/bin/env python3

class SecurePlant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self._name = name
        self._height = 0
        self._age = 0
        print(f"Plant created: {self._name}")
        self.set_height(height)
        self.set_age(age)

    def set_height(self, new_height: int) -> None:
        if (new_height >= 0):
            self._height = new_height
            print(f"Height updated: {self._height}cm [OK]")
        else:
            print(f"Invalid operation attempted: height "
                  f"{new_height}cm [REJECTED]")
            print("Security: Negative height rejected")

    def set_age(self, new_age: int) -> None:
        if (new_age >= 0):
            self._age = new_age
            print(f"Age updated: {self._age} days [OK]")
        else:
            print(f"Invalid operation attempted: age "
                  f"{new_age} days [REJECTED]")
            print("Security: Negative age rejected")

    def get_height(self) -> int:
        return self._height

    def get_age(self) -> int:
        return self._age

    def get_name(self) -> str:
        return self._name


if __name__ == "__main__":
    print("=== Garden Security System ===")
    sp1 = SecurePlant("Rose", -25, 30)
    print()
    sp1.set_height(-5)
    print()
    print(f"Current Plant: {sp1.get_name()} ({sp1.get_height()}cm, "
          f"{sp1.get_age()} days)")
