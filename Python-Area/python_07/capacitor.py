from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex1 import HealCapability, TransformCapability
from ex0.factories import CreatureFactory


def test_healing_factory(factory: CreatureFactory) -> None:
    for label in ["base", "evolved"]:
        print(f" {label}:")
        creature = (
            factory.create_base() if label == "base"
            else factory.create_evolved())
        print(creature.describe())
        print(creature.attack())
        if isinstance(creature, HealCapability):
            print(creature.heal())


def test_transform_factory(factory: CreatureFactory) -> None:
    for label in ["base", "evolved"]:
        print(f" {label}:")
        creature = (
            factory.create_base() if label == "base"
            else factory.create_evolved()
        )
        print(creature.describe())
        print(creature.attack())
        if isinstance(creature, TransformCapability):
            print(creature.transform())
            print(creature.attack())
            print(creature.revert())


if __name__ == "__main__":
    print("Testing Creature with healing capability")
    heal_factory = HealingCreatureFactory()
    test_healing_factory(heal_factory)

    print()
    print("Testing Creature with transform capability")
    transform_factory = TransformCreatureFactory()
    test_transform_factory(transform_factory)
