def ft_ancient_text() -> None:
    try:
        file_name = "ancient_fragment.txt"
        print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===\n")
        print(f"Accessing Storage Vault: {file_name}")
        file = open(file_name, "r")
        print("Connection established...\n")
        print("RECOVERED DATA:")
        content = file.read()
        print(content)
        file.close()
        print("Data recovery complete. Storage unit disconnected.")
    except FileNotFoundError:
        print("ERROR: Storage vault not found.")
    except Exception as e:
        print(e)


if __name__ == "__main__":
    ft_ancient_text()
