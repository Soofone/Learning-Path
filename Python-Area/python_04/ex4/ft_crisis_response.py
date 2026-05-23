def ft_crisis_response() -> None:
    print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===\n")

    file1_name = "lost_archive.txt"
    print(f"CRISIS ALERT: Attempting access to '{file1_name}'...")
    try:
        with open(file1_name, "r") as file1:
            print(file1.read())
    except FileNotFoundError:
        print("RESPONSE: Archive not found in storage matrix")
    print("STATUS: Crisis handled, system stable")
    file2_name = "classified_vault.txt"
    print(f"\nCRISIS ALERT: Attempting access to '{file2_name}'...")
    try:
        with open(file2_name, "w") as file2:
            file2.write("Hello World")
    except PermissionError:
        print("RESPONSE: Security protocols deny access")
    print("STATUS: Crisis handled, security maintained")

    file3_name = "standard_archive.txt"
    print(f"\nROUTINE ACCESS: Attempting access to '{file3_name}'...")
    try:
        with open(file3_name, "r") as file:
            data = file.read()
            print(f"SUCCESS: Archive recovered - ''{data}''")
    except Exception:
        print("RESPONSE: Crisis handled")

    print("STATUS: Normal operations resumed")
    print("\nAll crisis scenarios handled successfully. Archives secure.")


if __name__ == "__main__":
    ft_crisis_response()
