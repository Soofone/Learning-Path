VALID_ELEMENTS = {"fire", "water", "earth", "air"}


def validate_ingredients(ingredients: str) -> str:
    words = ingredients.lower().split()
    is_valid = any(word in VALID_ELEMENTS for word in words)
    status = "VALID" if is_valid else "INVALID"
    return f"{ingredients} - {status}"
