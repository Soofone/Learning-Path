from .elements import create_fire, create_water, create_earth, create_air


def healing_potion() -> str:
    return f"Healing potion brewed with {create_fire()} and {create_water()}"


def strength_potion() -> str:
    return f"Strength potion brewed with {create_earth()} and {create_fire()}"


def invisibility_potion() -> str:
    return (f"invisibility potion brewed with "
            f"{create_air()} and {create_water()}")


def wisdom_potion() -> str:
    all_elements = (f"{create_fire()}, {create_water()}, "
                    f"{create_earth()}, {create_air()}")
    return f"Wisdom potion brewed with all elements: {all_elements}"
