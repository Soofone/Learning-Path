import alchemy


try:
    print("=== Scared Scroll Mastery ===")
    print("\nTesting direct module access: ")
    print("alchemy.elements.create_fire(): "
          f"{alchemy.elements.create_fire()}")
    print("alchemy.elements.create_water(): "
          f"{alchemy.elements.create_water()}")
    print("alchemy.elements.create_earth(): "
          f"{alchemy.elements.create_earth()}")
    print("alchemy.elements.create_air(): "
          f"{alchemy.elements.create_air()}")

    print("\nTesting package-level access (controlled by __init__.py):")
    print("alchemy.create_fire(): "
          f"{alchemy.create_fire()}")
    print("alchemy.create_water(): "
          f"{alchemy.create_water()}")

    try:
        alchemy.create_earth()
    except AttributeError:
        print("alchemy.create_earth(): AttributeError - not exposed")

    try:
        alchemy.create_air()
    except AttributeError:
        print("alchemy.create_air(): AttributeError - not exposed")

    print("\nPackage metadata:")
    print(f"Version: {alchemy.__version__}")
    print(f"Author: {alchemy.__author__}")
except Exception as e:
    print(e)
