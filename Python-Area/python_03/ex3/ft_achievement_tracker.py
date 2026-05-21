def ft_achievement_analytics(alice: set, bob: set, charlie: set) -> None:
    try:
        print("\n=== Achievement Analytics ===")
        all_unique_achts = alice.union(bob, charlie)
        print(f"All unique achievements: {all_unique_achts}")
        print(f"Total unique achievements: {len(all_unique_achts)}")
        common_plyrs = alice.intersection(bob, charlie)
        print(f"\nCommon to all players: {common_plyrs}")
        alice_unique = alice.difference(bob.union(charlie))
        bob_unique = bob.difference(alice.union(charlie))
        charlie_unique = charlie.difference(alice.union(bob))
        all_rare = alice_unique.union(bob_unique, charlie_unique)
        print(f"Rare achievements (1 player): {all_rare}\n")
        alice_bob_common = alice.intersection(bob)
        print(f"Alice vs Bob common: {alice_bob_common}")
        print(f"Alice unique: {alice.difference(bob)}")
        print(f"Bob unique: {bob.difference(alice)}")
    except Exception as e:
        print(e)


def ft_achievement_tracker() -> None:
    try:
        alice = {"first_kill", "level_10", "treasure_hunter", "speed_demon"}
        bob = {"first_kill", "level_10", "boss_slayer", "collector"}
        charlie = {"level_10", "treasure_hunter", "boss_slayer",
                   "speed_demon", "perfectionist"}
        print("=== Achievement Tracker System ===\n")
        print(f"Player alice achievements: {alice}")
        print(f"Player bob achievements: {bob}")
        print(f"Player charlie achievements: {charlie}")
        ft_achievement_analytics(alice, bob, charlie)
    except Exception as e:
        print(e)


if __name__ == "__main__":
    ft_achievement_tracker()
