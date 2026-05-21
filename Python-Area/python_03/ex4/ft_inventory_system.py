import sys


def parse_inventory() -> dict:
    if len(sys.argv) == 1:
        print("Usage: python3 ft_inventory_system.py key:value ...")
        return dict()

    inventory = dict()
    for arg in sys.argv[1:]:
        try:
            key, value = arg.split(":")
            inventory[key] = int(value)
        except Exception:
            print(f"Invalid argument: {arg}")
    return inventory


def print_inventory_overview(inventory: dict) -> int:
    print("=== Inventory System Analysis ===")

    total_items = 0
    for value in inventory.values():
        total_items += value

    print(f"Total items in inventory: {total_items}")
    print(f"Unique item types: {len(inventory)}")

    return total_items


def print_current_inventory(inventory: dict, total_items: int) -> None:
    print("\n=== Current Inventory ===")

    for key, value in inventory.items():
        percent = (value / total_items) * 100
        unit = "unit" if value == 1 else "units"
        print(f"{key}: {value} {unit} ({percent:.1f}%)")


def print_inventory_statistics(inventory: dict) -> None:
    most_item = None
    least_item = None

    for key, value in inventory.items():
        if most_item is None or value > most_item[1]:
            most_item = (key, value)
        if least_item is None or value < least_item[1]:
            least_item = (key, value)

    print("\n=== Inventory Statistics ===")
    print(f"Most abundant: {most_item[0]} ({most_item[1]} units)")
    print(f"Least abundant: {least_item[0]} ({least_item[1]} units)")


def print_item_categories(inventory: dict) -> None:
    categories = {
        "Abundant": dict(),
        "Moderate": dict(),
        "Scarce": dict()
    }

    for key, value in inventory.items():
        if value >= 6:
            categories["Abundant"].update({key: value})
        elif value >= 4:
            categories["Moderate"].update({key: value})
        else:
            categories["Scarce"].update({key: value})

    print("\n=== Item Categories ===")

    for category, items_dict in categories.items():
        if items_dict:
            print(f"{category}: {items_dict}")


def print_management_suggestions(inventory: dict) -> None:
    restock = []

    for key, value in inventory.items():
        if value == 1:
            restock.append(key)

    print("\n=== Management Suggestions ===")

    if len(restock) == 0:
        print("Restock needed: None")
    else:
        print("Restock needed:", end=" ")

        count = 0
        total = len(restock)

        for item in restock:
            count += 1
            if count < total:
                print(item, end=", ")
            else:
                print(item)


def print_dictionary_properties(inventory: dict) -> None:
    print("\n=== Dictionary Properties Demo ===")

    print("Dictionary keys:", end=" ")

    count = 0
    total = len(inventory)

    for key in inventory.keys():
        count += 1
        if count < total:
            print(key, end=", ")
        else:
            print(key)

    print("Dictionary values:", end=" ")

    count = 0

    for value in inventory.values():
        count += 1
        if count < total:
            print(value, end=", ")
        else:
            print(value)

    item = "sword"
    print(f"Sample lookup - '{item}' in inventory:",
          inventory.get(item) is not None)


def inventory_analysis(inventory: dict) -> None:
    try:
        total_items = print_inventory_overview(inventory)
        print_current_inventory(inventory, total_items)
        print_inventory_statistics(inventory)
        print_item_categories(inventory)
        print_management_suggestions(inventory)
        print_dictionary_properties(inventory)
    except Exception as e:
        print(e)


def ft_inventory_system() -> None:
    try:
        inventory = parse_inventory()
        if inventory:
            inventory_analysis(inventory)
    except Exception as e:
        print(e)


if __name__ == "__main__":
    ft_inventory_system()
