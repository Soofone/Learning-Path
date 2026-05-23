def ft_vault_security() -> None:
    print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===\n")
    print("Initiating secure vault access...")
    print("Vault connection established with failsafe protocols\n")
    try:
        print("SECURE EXTRACTION:")
        file1_name = "classified_data.txt"
        with open(file1_name, "r") as file1:
            print(file1.read())

        print("SECURE PRESERVATION:")
        file2_name = "new_classified_data.txt"
        data = "[CLASSIFIED] New security protocols archived"
        with open(file2_name, "w") as file2:
            file2.write(data)
        with open(file2_name, "r") as file2:
            print(file2.read())
        print("Vault automatically sealed upon completion")
        print("\nAll vault operations completed with maximum security.")
    except Exception:
        print("Error: Cannot read/write from files.")


if __name__ == "__main__":
    ft_vault_security()
