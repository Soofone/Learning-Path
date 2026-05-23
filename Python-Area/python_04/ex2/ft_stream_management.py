from sys import stdin, stdout, stderr


def ft_stream_management() -> None:
    if stdin.closed or stdout.closed or stderr.closed:
        return
    print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")
    archivist_id = input("\nInput Stream active. Enter archivist ID: ")
    status_report = input("Input Stream active. Enter status report: ")

    print(f"\n[STANDARD] Archive status from {archivist_id}: {status_report}")
    print("[ALERT] System diagnostic: Communication "
          "channels verified", file=stderr)
    print("[STANDARD] Data transmission complete", file=stdout)
    print("\nThree-channel communication test successful.")


if __name__ == "__main__":
    ft_stream_management()
