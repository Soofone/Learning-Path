from ex0 import FlameFactory, AquaFactory, CreatureFactory


def test_factory(factory: CreatureFactory) -> None:
    print("Testing factory")
    base = factory.create_base()
    evolved = factory.create_evolved()

    print(base.describe())
    print(base.attack())
    print(evolved.describe())
    print(evolved.attack())


def test_battle(factory1: CreatureFactory, factory2: CreatureFactory) -> None:
    print("Testing battle")
    c1 = factory1.create_base()
    c2 = factory2.create_base()

    print(c1.describe())
    print(" vs. ")
    print(c2.describe())
    print(" fight!")
    print(c1.attack())
    print(c2.attack())


if __name__ == "__main__":
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()

    test_factory(flame_factory)
    print()
    test_factory(aqua_factory)
    print()
    test_battle(flame_factory, aqua_factory)
