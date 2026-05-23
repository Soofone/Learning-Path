def ft_archive_creation() -> None:
    file_name = "new_discovery.txt"
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===\n")
    print(f"Initializing new storage unit: {file_name}")
    try:
        file = open(file_name, "w")
        print("Storage unit created successfully...")
        content = [
            "[ENTRY 001] New quantum algorithm discovered\n",
            "[ENTRY 002] Efficiency increased by 347%\n",
            "[ENTRY 003] Archived by Data Archivist trainee\n"
        ]
        print("\nInscribing preservation data...")
        for line in content:
            file.write(line)
            print(line, end="")

        file.close()
        print("\nData inscription complete. Storage unit sealed.")
        print(f"Archive '{file_name}' ready for long-term preservation.")
    except Exception:
        print("Error: Storage unit could not be written to")


if __name__ == "__main__":
    ft_archive_creation()
