def garden_operations(error_type: str) -> None:
    """
    Trigger different built-in exceptions based on error_type.
    """
    if not error_type:
        raise TypeError("Error type cannot be None!")
    if error_type == "ValueError":
        int("abc")
    elif error_type == "ZeroDivisionError":
        10 / 0
    elif error_type == "FileNotFoundError":
        f = open("missing.txt")
        f.close()
    elif error_type == "KeyError":
        person = {"name": "Soufiane"}
        print(person["missing\\_plant"])


def test_error_types() -> None:
    """
    Test various exception types and demonstrate proper handling.
    """
    print("=== Garden Error Types Demo ===")
    try:
        try:
            print("\nTesting ValueError...")
            garden_operations("ValueError")
        except ValueError:
            print("Caught ValueError: invalid literal for int()")
        except Exception as e:
            print(e)
        try:
            print("\nTesting ZeroDivisionError...")
            garden_operations("ZeroDivisionError")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
        except Exception as e:
            print(e)
        try:
            print("\nTesting FileNotFoundError...")
            garden_operations("FileNotFoundError")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: No such file '{e.filename}'")
        except Exception as e:
            print(e)
        try:
            print("\nTesting KeyError...")
            garden_operations("KeyError")
        except KeyError as e:
            print(f"Caught KeyError: {e.args[0]}")
        except Exception as e:
            print(e)
    except Exception as e:
        print(f"Caught Exception: {e}")
    print("\nTesting multiple errors together...")
    try:
        garden_operations("ValueError")
        garden_operations("ZeroDivisionError")
        garden_operations("FileNotFoundError")
        garden_operations("KeyError")
    except (ValueError, ZeroDivisionError, FileNotFoundError, KeyError):
        print("Caught an error, but program continues!")
    except Exception as e:
        print(e)
    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
