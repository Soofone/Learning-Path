def list_comprehension_examples(data: dict) -> None:
    try:
        print("\n=== List Comprehension Examples ===")
        score = 2000
        high_scores = [player for player in data
                       if data[player]["score"] > score]
        scores_doubled = [data[player]["score"] * 2 for player in data]
        active_players = [player for player in data
                          if data[player]["active"]]
        print(f"High scores (>{score}): {high_scores}")
        print(f"Scores doubled: {scores_doubled}")
        print(f"Active players: {active_players}")
    except Exception as e:
        print(e)


def dict_comprehension_examples(data: dict) -> None:
    try:
        print("\n=== Dict Comprehension Examples ===")
        player_scores = {player: data[player]["score"] for player in data}
        score_categories = {
            "high": len([data[player]["score"] for player in data
                        if data[player]["score"] > 2000]),
            "medium": len([data[player]["score"] for player in data
                           if 1800 <= data[player]["score"] < 2000]),
            "low": len([data[player]["score"] for player in data
                        if data[player]["score"] < 1800])
        }
        acht_counts = {player: len(data[player]["achievements"])
                       for player in data}
        print(f"Player scores: {player_scores}")
        print(f"Score Categories: {score_categories}")
        print(f"achievement counts: {acht_counts}")
    except Exception as e:
        print(e)


def set_comprehension_examples(data: dict) -> None:
    try:
        print("\n=== Set Comprehension Examples ===")
        unique_players = {player for player in data}
        unique_achts = {acht for player in data
                        for acht in data[player]["achievements"]}
        active_regions = {data[player]["region"] for player in data}
        print(f"Unique players: {unique_players}")
        print(f"Unique achievements: {unique_achts}")
        print(f"Active regions: {active_regions}")
    except Exception as e:
        print(e)


def combined_analysis(data: dict) -> None:
    try:
        print("\n=== Combined Analysis ===")
        total_players = len([player for player in data])
        total_unq_achts = len({acht for player in data
                               for acht in data[player]["achievements"]})
        avg_score = sum(data[player]["score"]
                        for player in data) / total_players
        scores = [data[player]["score"] for player in data]
        top_score = max(scores)
        top_names = [player for player in data
                     if data[player]["score"] == top_score]
        top_achts = len(data[top_names[0]]["achievements"])
        print(f"Total players: {total_players}")
        print(f"Total unique achievements: {total_unq_achts}")
        print(f"Average score: {avg_score}")
        print("Top performer:", end=" ")
        print(*top_names, end="")
        print(f" ({top_score} points, {top_achts} achievements)")
    except Exception as e:
        print(e)


def ft_analytics_dashboard() -> None:
    try:
        print("=== Game Analytics Dashboard ===")
        data = {
            "alice": {
                "score": 2300,
                "active": True,
                "region": "north",
                "achievements": ["first_kill", "boss_slayer"],
            },
            "bob": {
                "score": 1800,
                "active": True,
                "region": "central",
                "achievements": ["level_10"],
            },
            "charlie": {
                "score": 2150,
                "active": True,
                "region": "east",
                "achievements": ["first_kill"],
            },
            "diana": {
                "score": 2050,
                "active": False,
                "region": "north",
                "achievements": ["level_10"],
            },
        }
        list_comprehension_examples(data)
        dict_comprehension_examples(data)
        set_comprehension_examples(data)
        combined_analysis(data)
    except Exception as e:
        print(e)


if __name__ == "__main__":
    ft_analytics_dashboard()
